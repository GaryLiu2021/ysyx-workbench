#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <common.h>

#define Log(format, ...) \
  printf("\33[1;35m[%s,%d,%s] " format "\33[0m\n", \
      __FILE__, __LINE__, __func__, ## __VA_ARGS__)

#undef panic
#define panic(format, ...) \
  do { \
    Log("\33[1;31msystem panic: " format, ## __VA_ARGS__); \
    halt(1); \
  } while (0)

#ifdef assert
# undef assert
#endif

#define assert(cond) \
  do { \
    if (!(cond)) { \
      panic("Assertion failed: %s", #cond); \
    } \
  } while (0)

#define TODO() panic("please implement me")

#define dprint(x) _Generic((x), \
    int:    	printf(#x " = %d\n", x), \
    double: 	printf(#x " = %f\n", x), \
	unsigned: 	printf(#x " = %u\n", x), \
	char* :  	printf(#x " = %s\n", x), \
    default: 	printf(#x " = %p\n", (void*)x) \
)

#endif
