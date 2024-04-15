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
	case SYS_write: {
		int fd = c->GPR1;
		void* buf = (void*)c->GPR2;
		int count = c->GPR3;
		Log("Nanos-lite: Doing syscall _write(int fd=%d, void *buf=%p, size_t count=%d)", fd, buf, count);
		if (fd == 1 || fd == 2) {
			for (int iChar = 0;iChar < count;iChar++)
				putch(((char*)buf)[iChar]);
		}
		break;
	}
	default: panic("Unhandled syscall ID = %d", a[0]);break;
	}
}
