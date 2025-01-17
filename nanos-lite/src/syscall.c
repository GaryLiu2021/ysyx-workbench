#include <common.h>
#include "syscall.h"
#include <fs.h>
#include <sys/time.h>
#include <proc.h>
#define SYS_RETURN(ret) c->GPRx=ret
#define SYSCALL_LOG(syscall) Log("[Nanos-lite]: SYS_" #syscall)

// Declare syscall functions
int sys_execve(const char* pathname, char* const argv[], char* const envp[]);

static uintptr_t sys_gettimeofday(uintptr_t* a) {
	struct timeval* tv = (struct timeval*)a[1];
	struct timezone* tz = (struct timezone*)a[2];
	uint64_t us = io_read(AM_TIMER_UPTIME).us;
	if (tv != NULL) {
		tv->tv_sec = us / (1000 * 1000);
		tv->tv_usec = us % (1000 * 1000);
	}
	if (tz != NULL) {
		// to implement
	}
	return 0;
}

void do_syscall(Context* c) {
	uintptr_t a[4];
	a[0] = c->GPR1;
	a[1] = c->GPR2;
	a[2] = c->GPR3;
	a[3] = c->GPR4;
	switch (a[0]) {
	case SYS_exit: {
		Log("[Nanos-lite]: Doing syscall _exit(%d)...", c->GPR2);
		// halt(0);
		char* const argv[] = { NULL };
        char* const envp[] = { "/bin:/usr/bin", NULL };
		SYS_RETURN(sys_execve("/bin/nterm", argv, envp));
		break;
	}
	case SYS_yield: {
		Log("[Nanos-lite]: Doing syscall yield...");
		yield();
		SYS_RETURN(0);
		Log("[Nanos-lite]: Return syscall yield with %d.", c->GPRx);
		break;// return 0
	}
	case SYS_open: {
		// SYSCALL_LOG(open);
		// Log("Open \"%s\"\n", (const char*)a[1]);
		SYS_RETURN(fs_open((const char*)a[1], (int)a[2], (int)a[3]));
        // Log("Return %d", c->GPRx);
        break;
	}
	case SYS_read: {
		// SYSCALL_LOG(read);
		SYS_RETURN(fs_read((int)a[1], (void*)a[2], (size_t)a[3]));
		break;
	}
	case SYS_write: {
		// SYSCALL_LOG(write);
		int fd = c->GPR2;
		const void* buf = (const void*)c->GPR3;
		size_t count = c->GPR4;
		// Log("[Nanos-lite]: Doing syscall _write(int fd=%d, void *buf=%p, size_t count=%d)", fd, buf, count);
		SYS_RETURN(fs_write(fd, buf, count));
		// Log("[Nanos-lite]: Return syscall _write with %d.", c->GPRx);
		break;
    }
    case SYS_kill: {
        while(1)
        break;
    }
    case SYS_close: {
		// SYSCALL_LOG(close);
		SYS_RETURN(fs_close((int)a[1]));
		break;
	}
	case SYS_lseek: {
		// SYSCALL_LOG(lseek);
		SYS_RETURN(fs_lseek((int)a[1],(size_t)a[2],(int)a[3]));
		break;
	}
	case SYS_brk: {
		SYS_RETURN(mm_brk((intptr_t)a[1]));
		break;
	}
	case SYS_execve: {
		SYS_RETURN(sys_execve((const char*)a[1], (char* const*)a[2], (char* const*)a[3]));
		break;
	}
	case SYS_gettimeofday: {
		// SYSCALL_LOG(gettimeofday);
		SYS_RETURN(sys_gettimeofday(a));
		break;
	}
	default: panic("Unhandled syscall ID = %d", a[0]);break;
	}
}

int sys_execve(const char* pathname, char* const argv[], char* const envp[]) {
	if (pathname == NULL)
		return -1;

	if (context_uload(current, pathname, argv, envp)) // Cannot open file `pathname`
		return -2;
	
	Log("New process: [%s]:%p,%p", pathname, argv, envp);

	// Now we can change to PCB root to save context of current
	switch_boot_pcb();
	yield();
	// panic("Should not reach here.");
	return 0;
}
