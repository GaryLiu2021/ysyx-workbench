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
			else if (*fmt == 'c') {
				// 处理字符格式化符号 %c
				char ch = va_arg(args, int);
				putch(ch);
				written++;
			}
			else if (*fmt == 'x') {
				// 处理十六进制格式化符号 %x
				int num = va_arg(args, int);
				char str[32];
				sprintf(str, "%x", num);
				int i = 0;
				while (str[i] != '\0') {
					putch(str[i++]);
					written++;
				}
			}
			else if (*fmt == 'p') {
				// 处理指针格式化符号 %p
				void* ptr = va_arg(args, void*);
				char str[32];
				sprintf(str, "%p", ptr);
				int i = 0;
				while (str[i] != '\0') {
					putch(str[i++]);
					written++;
				}
			}
			else {
				panic("@printf: Unsupported symbol!\n");
			}
			fmt++;  // 移动到下一个字符
		}
	}
	va_end(args);
	return written;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int written = 0;  // 记录写入的字符数
    char buf[256];

    while (*fmt) {
        if (*fmt != '%') {
            // 普通字符，直接复制到缓冲区
            buf[written++] = *fmt++;
        } else {
            // 遇到 '%'，处理格式化符号
            fmt++;  // 跳过 '%'
            if (*fmt == '\0') {
                break;  // 避免在字符串末尾的 '%' 导致无限循环
            }

            if (*fmt == 'd') {
                // 处理整数格式化符号 %d
                int num = va_arg(args, int);
                char str[32] = {};
                itoa(num, str, 10);
                int i = 0;
                while (str[i]!='\0') {
                  buf[written++] = str[i++];
                }
            } else if (*fmt == 's') {
                // 处理字符串格式化符号 %s
                const char *str = va_arg(args, const char *);
                while (*str) {
                    buf[written++] = *str++;
                }
			}
			else if (*fmt == 'x') {
				// 处理指针格式化符号 %x
				int value = va_arg(args, int);
				char str[32] = {};
				itoa(value, str, 16);
				int i = 0;
				while (str[i] != '\0') {
					buf[written++] = str[i++];
				}
			}
			else if (*fmt == 'p') {
				// 处理指针格式化符号 %p
				void* ptr = va_arg(args, void*);
				uintptr_t value = (uintptr_t)ptr;
				char str[32] = {};
				itoa(value, str, 16);
				buf[written++] = '0';
				buf[written++] = 'x';
				int i = 0;
				while (str[i] != '\0') {
					buf[written++] = str[i++];
				}
			}
			else {
				panic("@sprintf: Unsupported symbol!\n");
			}
			fmt++;  // 移动到下一个字符
        }
    }
    va_end(args);
    buf[written] = '\0'; // 添加 null 终止符
    strcpy(out, buf);
    return written;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
