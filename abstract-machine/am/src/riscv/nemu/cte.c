#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context* c) {
	// Save current process' pdir into context
	__am_get_cur_as(c);
	// printf("Context is saved at %p.\n", c);

	// for (int i = 0;i < 32;i++) {
	// 	printf("x%d=0x%x\n", i, c->gpr[i]);
	// }
	// printf("mepc=0x%x\n", c->mepc);

	if (user_handler) {
		Event ev = { 0 };
		if (c->mcause == -1)
			ev.event = EVENT_YIELD;
		else if (c->mcause < 20)
			ev.event = EVENT_SYSCALL;
		else
			ev.event = EVENT_ERROR;

		c = user_handler(ev, c);
		assert(c != NULL);
	}

	// Reload pdir to reg `satp`
	__am_switch(c);

	// printf("Reloading context from %p...\n", c);
	// for (int i = 0;i < 32;i++) {
	// 	printf("x%d=0x%x\n", i, c->gpr[i]);
	// }
	// printf("mepc=0x%x\n", c->mepc);

	return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context* (*handler)(Event, Context*)) {
	// initialize exception entry
	asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

	// register event handler
	user_handler = handler;

	return true;
}

Context* kcontext(Area kstack, void (*entry)(void*), void* arg) {
	Context* cp = (Context*)(kstack.end - sizeof(Context));
	cp->mepc = (uintptr_t)entry - 4;
	cp->mstatus = 0x1800; // For difftest
	cp->gpr[10] = (uintptr_t)(arg);
	return cp;
}

// Yield an interupt
void yield() {
	asm volatile("li a7, -1; ecall");
}

bool ienabled() {
	return false;
}

void iset(bool enable) {}
