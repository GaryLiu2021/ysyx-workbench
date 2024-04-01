#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);

	int written = 0;
	while (*fmt) {
		if (*fmt != '%') {
			// 普通字符，直接复制到缓冲区
			putch(*fmt++);
			written++;
		}
		else {
			// Proccess '%'
			fmt++;
			if (*fmt == '\0') {
				break;
			}

			if (*fmt == 'd') {
				// 处理整数格式化符号 %d
				int num = va_arg(args, int);
				char str[32] = {};
				itoa(num, str, 10);
				int i = 0;
				while (str[i] != '\0') {
					putch(str[i++]);
					written++;
				}
			}
			else if (*fmt == 's') {
				// 处理字符串格式化符号 %s
				const char* str = va_arg(args, const char*);
				while (*str) {
					putch(*str++);
					written++;
				}
			}
			fmt++;  // 移动到下一个字符
		}
	}
	va_end(args);
	return written;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
	return vsnprintf(out, -1, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
	va_list arg;
	va_start(arg, fmt);

	int res = vsprintf(out, fmt, arg);    // 将格式化的内容(字符串)赋值给out

	va_end(arg);
	return res;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}
static char NUM_CHAR[] = "0123456789ABCDEF";
int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
	int len = 0;
	char buf[128];
	int buf_len = 0;
	while (*fmt != '\0' && len < n) {
		switch (*fmt) {
		case '%':
			fmt++;
			// 检查百分号之后的字符
			switch (*fmt) {
			case 'd':
				int val = va_arg(ap, int);    // 将该参数转为int型
				if (val == 0) out[len++] = '0';
				if (val < 0) {
					out[len++] = '-';
					val = 0 - val;
				}
				for (buf_len = 0; val;val /= 10, buf_len++)
					buf[buf_len] = NUM_CHAR[val % 10];    //这里buf会是逆序的
				for (int i = buf_len - 1; i >= 0; i--)
					out[len++] = buf[i];
				break;
			case 'u':
				// uint32_t uval = va_arg(ap, uint32_t);
				// 同%d, 只不过不用考虑负数
				break;
			case 'c':
				char c = (char)va_arg(ap, int);    //va_arg函数没有char这个参数
				out[len++] = c;
				break;
			case 's':
				char* s = va_arg(ap, char*);
				for (int i = 0; s[i] != '\0'; i++)
					out[len++] = s[i];
				break;
			case 'p':
				out[len++] = '0'; out[len++] = 'x';
				uint32_t address = va_arg(ap, uint32_t);
				for (buf_len = 0; address; address /= 16, buf_len++)
					buf[buf_len] = NUM_CHAR[address % 16];
				for (int i = buf_len - 1; i >= 0; i--)
					out[len++] = buf[i];
				break;
			}
			break; // case % 的break.
		case '\n':
			out[len++] = '\n';
			break;
		default:
			out[len++] = *fmt;
		}
		fmt++;
	}
	out[len] = '\0';    // 这句千万不能漏.
	return len;
}

#endif
