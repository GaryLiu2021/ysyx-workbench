#include <proc.h>

#define MAX_NR_PROC 4

static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static PCB pcb_boot = {};
PCB* current = NULL;

void switch_boot_pcb() {
  current = &pcb_boot;
}

void hello_fun(void *arg) {
  int j = 1;
  while (1) {
    Log("Hello World from Nanos-lite with arg '%s' for the %dth time!", (char*)arg, j);
    j ++;
    yield();
  }
}

void init_proc() {

	Log("Initializing processes...");

	// context_kload(&pcb[0], hello_fun, "h0");
    char* argv[] = { NULL };
    char* envp[] = { NULL };
	// context_uload(&pcb[1], "/bin/nterm", argv, envp);
	switch_boot_pcb();
	context_uload(&pcb[0], "/bin/dummy", argv, envp);

  // load program here
  // naive_uload(NULL, "/bin/nterm");
}

Context* schedule(Context* prev) {
	PCB* tmp = current;
	current->cp = prev;
	// current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
	current = &pcb[0];
	Log("Switching from %p to %p...", tmp, current);
	Log("Reloading context from %p...", current->cp);
	// Log("Stack pointer going to %p", current->cp->gpr[10]);
	return current->cp;
}

void context_kload(PCB* p, void (*entry)(void*), void* arg) {
	p->cp = kcontext((Area) { p->stack, p + 1 }, hello_fun, arg);
}

int context_uload(PCB* p, const char* filename, char* const argv[], char* const envp[]) {
    // Create an address space and also a page table(a new map) for this UP
    protect(&p->as);

    uintptr_t entry = naive_uload(p, filename);
    if (entry == (uintptr_t)NULL)
		return -1;

	int argc = 0, envc = 0;
	while (argv[argc] != NULL) argc++;
	while (envp[envc] != NULL) envc++;

	/*
	|               |
	+---------------+ <---- ustack.end
	|  Unspecified  |
	+---------------+
	|               | <----------+
	|    string     | <--------+ |
	|     area      | <------+ | |
	|               | <----+ | | |
	|               | <--+ | | | |
	+---------------+    | | | | |
	|  Unspecified  |    | | | | |
	+---------------+    | | | | |
	|     NULL      |    | | | | |
	+---------------+    | | | | |
	|    ......     |    | | | | |
	+---------------+    | | | | |
	|    envp[1]    | ---+ | | | |
	+---------------+      | | | |
	|    envp[0]    | -----+ | | |
	+---------------+        | | |
	|     NULL      |        | | |
	+---------------+        | | |
	| argv[argc-1]  | -------+ | |
	+---------------+          | |
	|    ......     |          | |
	+---------------+          | |
	|    argv[1]    | ---------+ |
	+---------------+            |
	|    argv[0]    | -----------+
	+---------------+
	|      argc     |
	+---------------+ <---- cp->GPRx
	|               |
    */

    /**
     * Allocate user stack for this UP
    */
#define NR_PAGE 8
	char* us1 = (char*)new_page(NR_PAGE); // 32KB for user stack
	AddrSpace* uas = &p->as;
	for (int i = 1;i <= NR_PAGE;i++) {
		map(uas, (char*)uas->area.end - i * PGSIZE, us1 - i * PGSIZE, PROT_R | PROT_W);
		Log("Mapping user stack: %p(vaddr)-->%p(paddr)", uas->area.end - i * PGSIZE, us1 - i * PGSIZE);
	}
	Log("kernel stack: [%p - %p], user stack: [%p - %p]\n", p + 1, p, us1, us1 - NR_PAGE * PGSIZE);
	char* us_tmp = us1;
	// clone argv
	for (int i = 0; i < argc; i++) {
        size_t len = strlen(argv[i]) + 1;
        us1 -= len;
        strcpy(us1, argv[i]);
	}
	// clone envp
	for (int i = 0; i < envc; i++) {
		size_t len = strlen(envp[i]) + 1; // include null character
		us1 -= len;
		strcpy(us1, envp[i]);
	}

	uintptr_t* us2 = (uintptr_t*)us1;
	us2 -= (argc + envc + 3);

	us2[0] = argc;
	// char* argv[argc]
	for (int i = 0; i < argc; i++) {
		size_t len = strlen(argv[i]) + 1;
		us_tmp -= len;
		us2[i + 1] = (uintptr_t)us_tmp;
	}
	// char* envp[envc]
	us2[argc + 1] = 0;
	for (int i = 0; i < envc; i++) {
		size_t len = strlen(envp[i]) + 1; // include null character
		us_tmp -= len;
		us2[argc + i + 2] = (uintptr_t)us_tmp;
	}
	// NULL
	us2[argc + 2 + envc] = 0;

	// Allocate context for new user process
	p->cp = ucontext(&p->as, (Area) { p->stack, p + 1 }, (void*)entry);
	// Pass the argument to user
	p->cp->GPRx = (uintptr_t)us2;

	return 0;
}
