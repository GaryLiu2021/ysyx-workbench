#include <memory.h>
#include <proc.h>

static void* pf = NULL;
extern PCB* current;

void* new_page(size_t nr_page) {
	pf += nr_page * PGSIZE;
	return pf;
}

#ifdef HAS_VME
static void* pg_alloc(int n) {
	int nr_page = n / PGSIZE;
	void* end = new_page(nr_page);
	void* start = end - nr_page * 4096;
	memset(start, 0, nr_page * 4096);
	return start;
}
#endif

void free_page(void *p) {
  panic("not implement yet");
}

/* The brk() system call handler. */
int mm_brk(uintptr_t brk) {
	// If brk requested is lower than max_brk, it means to free
	if (brk < current->max_brk) {
		panic("Heap free not implemented!");
	}

	// If brk requested is larger than max_brk, it means to allocate
	if (brk > current->max_brk) {
		int nr_page = PG_NUM(brk) - PG_NUM(current->max_brk);
		if (nr_page){
			void* start = pg_alloc(nr_page);
			do {
				map(&current->as, (void*)PG_NUM(current->max_brk) + nr_page * PGSIZE, start + (nr_page - 1) * PGSIZE, PROT_RWX);
			} while (--nr_page);
		}
		current->max_brk = brk;
		return 0;
	}

	// If brk requested equals max_brk
	return 0;
}

void init_mm() {
  pf = (void *)ROUNDUP(heap.start, PGSIZE);
  Log("free physical pages starting from %p", pf);

#ifdef HAS_VME
  vme_init(pg_alloc, free_page);
#endif
}
