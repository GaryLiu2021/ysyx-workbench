#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  while(*s) {
    len++;
    s++;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  char *d = dst;
  while ((*d++ = *src++) != '\0');
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
    char *d = dst;
    size_t i;

    // Copy at most n characters from src to dst
    for (i = 0; i < n && *src != '\0'; ++i) {
        *d++ = *src++;
    }

    // If src was shorter than n, pad dst with '\0' characters
    for (; i < n; ++i) {
        *d++ = '\0';
    }

    return dst;
}

// add src to the end of dst
char *strcat(char *dst, const char *src) {
  char *d = dst;
  while (*d) {
    d++;
  }
  while ((*d++ = *src++) != '\0');
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  while (n > 0 && *s1 && (*s1 == *s2)) {
    s1++;
    s2++;
    n--;
  }
  if (n == 0) return 0;
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

void *memset(void *s, int c, size_t n) {
  unsigned char *p = s;
  while (n > 0) {
    *p++ = (unsigned char)c;
    n--;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) { //ljl@2024/04/17: if n is not right, may cause deadlock
  unsigned char *d = dst;
  const unsigned char *s = src;
  if (d < s) {
    while (n > 0) {
      *d++ = *s++;
      n--;
    }
  } else if (d > s) {
    d += n;
    s += n;
    while (n > 0) {
      *(--d) = *(--s);
      n--;
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  unsigned char *d = out;
  const unsigned char *s = in;
  while (n > 0) {
    *d++ = *s++;
    n--;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = s1;
  const unsigned char *p2 = s2;
  while (n > 0 && *p1 == *p2) {
    p1++;
    p2++;
    n--;
  }
  if (n == 0) return 0;
  return (*p1 < *p2) ? -1 : 1;
}

#endif
