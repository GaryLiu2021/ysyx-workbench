#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <common.h>

#ifndef PGSIZE
#define PGSIZE 4096

#define PG_NUM(x) ((uint32_t)(x) & 0xFFFFF000)
#define PG_OFF(x) ((uint32_t)(x) & 0x00000FFF)
#endif

#define PG_ALIGN __attribute((aligned(PGSIZE)))

void* new_page(size_t);

// Heap management
int mm_brk(intptr_t increment);

// Ramdisk read
size_t ramdisk_read(void* buf, size_t offset, size_t len);

#endif
