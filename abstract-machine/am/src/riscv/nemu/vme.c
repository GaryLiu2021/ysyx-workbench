#include <am.h>
#include <nemu.h>
#include <klib.h>

static AddrSpace kas = {};
static void* (*pgalloc_usr)(int) = NULL;
static void (*pgfree_usr)(void*) = NULL;
static int vme_enable = 0;

static Area segments[] = {      // Kernel memory mappings
  NEMU_PADDR_SPACE
};

#define USER_SPACE RANGE(0x40000000, 0x80000000)

static inline void set_satp(void *pdir) {
  uintptr_t mode = 1ul << (__riscv_xlen - 1);
  asm volatile("csrw satp, %0" : : "r"(mode | ((uintptr_t)pdir >> 12)));
}

static inline uintptr_t get_satp() {
  uintptr_t satp;
  asm volatile("csrr %0, satp" : "=r"(satp));
  return satp << 12;
}

/**
 * To launch the page system, such as preparing kernel page tables.
 * 1.Set the callback function:
 * `pgalloc_f` for page allocation
 * `pgfree_f` for page free
 * 2. Call `map` to fill up the kernel address space page tables.
 * 3. Set reg `satp`(Supervisor Address Translation and Protection)
*/
bool vme_init(void* (*pgalloc_f)(int), void (*pgfree_f)(void*)) {
  pgalloc_usr = pgalloc_f;
  pgfree_usr = pgfree_f;

  kas.ptr = pgalloc_f(PGSIZE);

  int i;
  for (i = 0; i < LENGTH(segments); i ++) {
    void *va = segments[i].start;
    for (; va < segments[i].end; va += PGSIZE) {
      map(&kas, va, va, 0);
    }
  }

  set_satp(kas.ptr);
  vme_enable = 1;

  return true;
}

void protect(AddrSpace *as) {
  PTE *updir = (PTE*)(pgalloc_usr(PGSIZE));
  as->ptr = updir;
  as->area = USER_SPACE;
  as->pgsize = PGSIZE;
  // map kernel space
  memcpy(updir, kas.ptr, PGSIZE);
}

void unprotect(AddrSpace *as) {
}

void __am_get_cur_as(Context *c) {
  c->pdir = (vme_enable ? (void *)get_satp() : NULL);
}

void __am_switch(Context *c) {
  if (vme_enable && c->pdir != NULL) {
    set_satp(c->pdir);
  }
}

#define VA_OFFSET(addr) (addr & 0x00000FFF) // Extract page offset
#define VA_VPN_2(addr)  ((addr >> 12) & 0x000003FF) // Extract level-1 page number
#define VA_VPN_1(addr)  ((addr >> 22) & 0x000003FF) // Extract level-2 page number

#define PA_OFFSET(addr) (addr & 0x00000FFF) // Extract physical page offset
#define PA_PPN(addr)    ((addr >> 12) & 0x000FFFFF) // Extract physical page number
#define PTE_PPN 0xFFFFF000 // 31 ~ 12

/*

															  PAGE FRAME
			  +-----------+-----------+----------+         +---------------+
			  |    DIR    |   PAGE    |  OFFSET  |         |               |
			  +-----+-----+-----+-----+-----+----+         |               |
					|           |           |              |               |
	  +-------------+           |           +------------->|    PHYSICAL   |
	  |                         |                          |    ADDRESS    |
	  |   PAGE DIRECTORY        |      PAGE TABLE          |               |
	  |  +---------------+      |   +---------------+      |               |
	  |  |               |      |   |               |      +---------------+
	  |  |               |      |   |---------------|              ^
	  |  |               |      +-->| PG TBL ENTRY  |--------------+
	  |  |---------------|          |---------------|
	  +->|   DIR ENTRY   |--+       |               |
		 |---------------|  |       |               |
		 |               |  |       |               |
		 +---------------+  |       +---------------+
				 ^          |               ^
+-------+        |          +---------------+
|  CR3  |--------+
+-------+

*/


/**
 * Allocate an page table entry in `prot` privilege, which maps the page where the address `va`(in address space`as`) locates with the physical page where the address `pa` locates.
*/
void map(AddrSpace* as, void* va, void* pa, int prot) {
	uintptr_t va_trans = (uintptr_t)va;
	uintptr_t pa_trans = (uintptr_t)pa;

	// Va and pa should be the start of a page.
	assert(PA_OFFSET(pa_trans) == 0);
	assert(VA_OFFSET(va_trans) == 0);

	uint32_t ppn = PA_PPN(pa_trans);
	uint32_t vpn_1 = VA_VPN_1(va_trans);
	uint32_t vpn_2 = VA_VPN_2(va_trans);

	#define PTE_BYTES (4) // riscv32 4bytes

	PTE* page_dir_base = (PTE*)as->ptr;
	PTE* page_dir_target = page_dir_base + vpn_1;

	// If level-1 PTE is empty, allocate a new page and fill the PTE.
	if (*page_dir_target == 0) {
		// Allocate a page for level-2 page table
		PTE* page_table_base = (PTE*)pgalloc_usr(PGSIZE);
		// Store the base address of the new PT in l1 PT, also the valid flag
		*page_dir_target = ((PTE)page_table_base) | PTE_V;
		// Seek the level-2 PTE
		PTE* page_table_target = page_table_base + vpn_2;
		// Fill the level-2 PTE with physical page number and flags
		*page_table_target = (ppn << 12) | PTE_V | PTE_R | PTE_W | PTE_X;
	}
	else {
		// Get the level-2 page table base address
		PTE* page_table_base = (PTE*)((*page_dir_target) & PTE_PPN);
		// Seek the level-2 PTE
		PTE* page_table_target = page_table_base + vpn_2;
		// Fill the level-2 PTE with physical page number and flags
		*page_table_target = (ppn << 12) | PTE_V | PTE_R | PTE_W | PTE_X;
	}
	// if ((((uint32_t)va)&(0xfffff000)) == 0x807f0000)
	// {printf("Mapped va[%p] with pa[%p]\n", va, pa);}
}

/**
 * Allocate a context for a user process.
 * User process starts from `entry`
 * Allocate at PCB in `kstack`
*/
Context* ucontext(AddrSpace* as, Area kstack, void* entry) {
	Context* cp = (Context*)(kstack.end - sizeof(Context));
	cp->mepc = (uintptr_t)entry - 4;
	return cp;
}
