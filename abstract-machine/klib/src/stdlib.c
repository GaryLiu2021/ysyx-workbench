#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
static unsigned long int next = 1;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char* nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr ++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return x;
}

void utoa(unsigned long num, char* str, int base) {
	assert(base >= 2 && base <= 16);

	int i = 0;
	if (num == 0) {
		str[i++] = '0';
	}
	else {
		while (num != 0) {
			unsigned rem = num % base;
			str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
			num = num / base;
		}
		str[i] = '\0';

		// 反转字符串
		int start = 0;
		int end = i - 1;
		while (start < end) {
			char temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			start++;
			end--;
		}
	}
}

void itoa(int num, char *str, int base)
{
  int i = 0;
  int isNegative = 0;
  assert(base >= 2 && base <= 16);

  // 处理负数
  if (num < 0 && base == 10)
  {
    isNegative = 1;
    num = -num;
  }

  // 处理特殊情况：0
  if (num == 0)
  {
    str[i++] = '0';
  }
  else
  {
    // 处理整数部分
    while (num != 0)
    {
      int rem = num % base;
      str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
      num = num / base;
    }

    // 如果是负数，添加负号
    if (isNegative)
    {
      str[i++] = '-';
    }

    str[i] = '\0';

    // 反转字符串
    int start = 0;
    int end = i - 1;
    while (start < end)
    {
      char temp = str[start];
      str[start] = str[end];
      str[end] = temp;
      start++;
      end--;
    }
  }
}

static char* start_addr = NULL; // initial address
static bool init_flag = false; //flag of initial done

void* malloc(size_t size) {
  // On native, malloc() will be called during initializaion of C runtime.
  // Therefore do not call panic() here, else it will yield a dead recursion:
  //   panic() -> putchar() -> (glibc) -> malloc() -> panic()

	if (!init_flag) {
		start_addr = (char*)ROUNDUP(heap.start, 8);
		init_flag = true;
	}
	size = (size_t)ROUNDUP(size, 8);
	char* old = start_addr;
	start_addr += size;
	return old;
}

void free(void* ptr) {
}

#endif
