#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  char buf[256]; // 假设最大输出不超过 256 个字符
  int result = vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);
  putstr(buf); // 输出字符串到终端
  return result;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf(out, SIZE_MAX, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int result = vsprintf(out, fmt, args);
  va_end(args);
  return result;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int result = vsnprintf(out, n, fmt, args);
  va_end(args);
  return result;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  int result = snprintf(out, n, fmt, ap);
  if (result >= n) {
      // 字符串被截断，返回实际需要的缓冲区大小
      return result;
  }
  return result;  // 返回实际写入的字符数（不包括 null 终止符）
}

#endif
