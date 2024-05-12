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
	  map(&kas, va, va, 0x7);
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

// Store reg `satp` into saving context `c`
void __am_get_cur_as(Context* c) {
  c->pdir = (vme_enable ? (void *)get_satp() : NULL);
}

// Reload reg `satp` with on-going context `c`
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
	// // Check user space mapping
	// if ((uintptr_t)va < 0x80000000)
	// 	printf("va[%p]-->pa[%p]\n", va, pa);
	uintptr_t va_trans = (uintptr_t)va;
	uintptr_t pa_trans = (uintptr_t)pa;

	// Prot sanity check and mapping
	assert(prot < 0x8);
	prot = prot << 1;

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
		*page_table_target = (ppn << 12) | PTE_V | (uint32_t)prot;
	}
	else {
		// Get the level-2 page table base address
		PTE* page_table_base = (PTE*)((*page_dir_target) & PTE_PPN);
		// Seek the level-2 PTE
		PTE* page_table_target = page_table_base + vpn_2;
		// Fill the level-2 PTE with physical page number and flags
		*page_table_target = (ppn << 12) | PTE_V | (uint32_t)prot;
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
	// Allocate this user stack at the bottom of kstack.
	Context* cp = (Context*)(kstack.end - sizeof(Context));

	// Set the mepc with entry-4, so that CPU can jump to user process after mret
	cp->mepc = (uintptr_t)entry;

	// Set the user process's pdir with current PCB's AddrSpace
	cp->pdir = as->ptr;

	// Enable the hardware intr
	cp->mstatus = (cp->mstatus & ~MPIE_MASKBIT) | (0x1 << MPIE_OFFSET);
	return cp;
}
