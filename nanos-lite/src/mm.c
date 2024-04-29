#include <memory.h>

static void *pf = NULL;

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
  return 0;
}

void init_mm() {
  pf = (void *)ROUNDUP(heap.start, PGSIZE);
  Log("free physical pages starting from %p", pf);

#ifdef HAS_VME
  vme_init(pg_alloc, free_page);
#endif
}
