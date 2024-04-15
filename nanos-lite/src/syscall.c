#include <common.h>
#include "syscall.h"
#define SYS_RETURN(ret) c->GPRx=ret

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
		SYS_RETURN(0);
		Log("Nanos-lite: Return syscall yield with %d.", c->GPRx);
		break;// return 0
	}
	case SYS_write: {
		int fd = c->GPR2;
		void* buf = (void*)c->GPR3;
		unsigned int count = c->GPR4;
		Log("Nanos-lite: Doing syscall _write(int fd=%d, void *buf=%p, size_t count=%x)", fd, buf, count);
		if (fd == 1 || fd == 2) {
			for (int iChar = 0;iChar < count;iChar++)
				putch(((char*)buf)[iChar]);
		}
		SYS_RETURN(count);
		break;
	}
	default: panic("Unhandled syscall ID = %d", a[0]);break;
	}
}
