#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>

static int evtdev = 3;
static int fbdev = 5;
static int screen_w = 0, screen_h = 0;
static int canvas_w = 0, canvas_h = 0;
static int canvas_x = 0, canvas_y = 0;

static uint64_t NDL_init_time = 0;

uint32_t NDL_GetTicks() {
	struct timeval tv;
	// struct timezone tz;
	gettimeofday(&tv, NULL);
	uint64_t NDL_current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (uint32_t)(NDL_current_time - NDL_init_time);
}

int NDL_PollEvent(char *buf, int len) {
	return read(evtdev, buf, len);
}

void NDL_OpenCanvas(int *w, int *h) {
  if (getenv("NWM_APP")) {
    int fbctl = 4;
    fbdev = 5;
    screen_w = *w; screen_h = *h;
    char buf[64];
    int len = sprintf(buf, "%d %d", screen_w, screen_h);
    // let NWM resize the window and create the frame buffer
    write(fbctl, buf, len);
    while (1) {
      // 3 = evtdev
      int nread = read(3, buf, sizeof(buf) - 1);
      if (nread <= 0) continue;
      buf[nread] = '\0';
      if (strcmp(buf, "mmap ok") == 0) break;
    }
    close(fbctl);
  }
	int buf_size = 1024;
	char* buf = (char*)malloc(buf_size * sizeof(char));
	int fd = open("/proc/dispinfo", 0, 0);
	int ret = read(fd, buf, buf_size);
	assert(ret < buf_size); // to be cautious...
	assert(close(fd) == 0);

	int i = 0;
	int width = 0, height = 0;
	//使用 strncmp 函数检查字符串 "WIDTH" 是否位于 buf 中 i 处开始的位置，以确保文件内容的格式正确。
	assert(strncmp(buf + i, "WIDTH", 5) == 0);
	//这一行将 i 增加 5，以跳过字符串 "WIDTH"。
	i += 5;
	for (; i < buf_size; ++i) {
		if (buf[i] == ':') { i++; break; }
		assert(buf[i] == ' ');
	}
	for (; i < buf_size; ++i) {
		//检查当前字符是否是数字字符。如果是，它跳出循环以开始解析宽度值。
		if (buf[i] >= '0' && buf[i] <= '9') break;
		assert(buf[i] == ' ');
	}
	for (; i < buf_size; ++i) {

		if (buf[i] >= '0' && buf[i] <= '9') {
			//检查当前字符是否是数字字符。如果是，它将当前字符的数字值添加到 width 变量中。
			width = width * 10 + buf[i] - '0';
		}
		else {
			break;
		}
	}
	assert(buf[i++] == '\n');

	assert(strncmp(buf + i, "HEIGHT", 6) == 0);
	i += 6;
	for (; i < buf_size; ++i) {
		if (buf[i] == ':') { i++; break; }
		assert(buf[i] == ' ');
	}
	for (; i < buf_size; ++i) {
		if (buf[i] >= '0' && buf[i] <= '9') break;
		assert(buf[i] == ' ');
	}
	for (; i < buf_size; ++i) {
		if (buf[i] >= '0' && buf[i] <= '9') {
			height = height * 10 + buf[i] - '0';
		}
		else {
			break;
		}
	}

	free(buf);

	screen_w = width;
	screen_h = height;
	printf("%d,%d\n", width, height);
	if (*w == 0 && *h == 0) {
		*w = screen_w;
		*h = screen_h;
	}
	canvas_w = *w;
	canvas_h = *h;
	canvas_x = (screen_w - canvas_w) / 2;
	canvas_y = (screen_h - canvas_h) / 2;
}

void NDL_DrawRect(uint32_t* pixels, int x, int y, int w, int h) {
	int fd = open("/dev/fb", 0, 0);
	for (int i = 0; i < h; i++) {
		lseek(fd, (screen_w * (i + y) + x) * 4, SEEK_SET);
		write(fd, pixels + w * i, w * 4);
	}
	close(fd);
}

void NDL_OpenAudio(int freq, int channels, int samples) {
}

void NDL_CloseAudio() {
}

int NDL_PlayAudio(void *buf, int len) {
  return 0;
}

int NDL_QueryAudio() {
  return 0;
}

int NDL_Init(uint32_t flags) {
  if (getenv("NWM_APP")) {
    evtdev = 3;
  }

  NDL_init_time = 0;
  NDL_init_time = NDL_GetTicks();

  char buf[64];
  int dispinfo = open("/proc/dispinfo", 0, 0);
  read(dispinfo, buf, sizeof(buf));
  sscanf(buf, "WIDTH : %d\nHEIGHT : %d\n", &screen_w, &screen_h);

  return 0;
}

void NDL_Quit() {
}
