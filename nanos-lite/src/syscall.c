#include <common.h>
#include "syscall.h"
void do_syscall(Context* c) {
	uintptr_t a[4];
	a[0] = c->GPR1;
	switch (a[0]) {
	case SYS_exit: {
		Log("Nanos-lite: Doing syscall _exit(%d)...", c->GPR2);
		halt(0);
		break;
	}
	case SYS_yield: {
		Log("Nanos-lite: Doing syscall yield...");
		yield();
		c->GPRx = 0;
		Log("Nanos-lite: Return syscall yield with %d.", c->GPRx);
		break;// return 0
	}
	default: panic("Unhandled syscall ID = %d", a[0]);break;
	}
}
