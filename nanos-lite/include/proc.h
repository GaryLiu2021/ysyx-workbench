#ifndef __PROC_H__
#define __PROC_H__

#include <common.h>
#include <memory.h>

#define STACK_SIZE (8 * PGSIZE)

typedef union {
  uint8_t stack[STACK_SIZE] PG_ALIGN;
  struct {
	Context *cp;
	AddrSpace as;
	// we do not free memory, so use `max_brk' to determine when to call _map()
	uintptr_t max_brk;
  };
} PCB;

extern PCB* current;
extern char* cur_cmd;

uintptr_t naive_uload(PCB* pcb, const char* filename);

void context_kload(PCB* p, void (*entry)(void*), void* arg);

Context* schedule(Context* prev);

int context_uload(PCB* p, const char* filename, char* const argv[], char* const envp[]);

void switch_boot_pcb();

#define PROT_R	0x4		// Read permission
#define PROT_W	0x2		// Write permission
#define PROT_X	0x1		// Execute permission
#define PROT_RWX (PROT_R | PROT_W | PROT_X)
#define PROT_RW (PROT_R | PROT_W)

#endif
