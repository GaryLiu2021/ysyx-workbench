#include <common.h>
#include <proc.h>
extern void do_syscall(Context* c);

static Context* do_event(Event e, Context* c) {
	switch (e.event) {
	case(EVENT_YIELD): {
		c = schedule(c);
		break;
	}
	case(EVENT_SYSCALL): {
		do_syscall(c);
		break;
	}
	case(EVENT_PAGEFAULT): {
		panic("Not implemented");
		break;
	}
	case(EVENT_ERROR):
		panic("Event Error happened!");
		break;
	case(EVENT_IRQ_TIMER): {
		Log("[Nanos-lite]: %s recv EVENT_IRQ_TIMER", cur_cmd);
		c = schedule(c);
        break;
	}
	case(EVENT_IRQ_IODEV): {
		panic("Not implemented");
		break;
	}
	default: panic("Unhandled event ID = %d", e.event);
	}

	return c;
}

void init_irq(void) {
	Log("Initializing interrupt/exception handler...");
	cte_init(do_event);
}
