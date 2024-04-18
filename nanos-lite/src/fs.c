#include <fs.h>

typedef size_t (*ReadFn) (void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn) (const void *buf, size_t offset, size_t len);

typedef struct {
  char *name;
  size_t size;
  size_t disk_offset;
  ReadFn read;
  WriteFn write;
  size_t open_offset;
} Finfo;

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

extern size_t serial_write(const void* buf, size_t offset, size_t len);
extern size_t events_read(void* buf, size_t offset, size_t len);
extern size_t dispinfo_read(void* buf, size_t offset, size_t len);
extern size_t fb_write(const void* buf, size_t offset, size_t len);

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
	[FD_STDIN] = {"stdin", 0, 0, invalid_read, invalid_write},
	[FD_STDOUT] = {"stdout", 0, 0, invalid_read, serial_write},
	[FD_STDERR] = {"stderr", 0, 0, invalid_read, serial_write},
	[FD_EVTDEV] = {"evtdev",0 , 0,events_read, invalid_write},
	[FD_DISP] = {"/proc/dispinfo",0,0,dispinfo_read},
	[FD_FB] = {"/dev/fb",0,0,invalid_read,fb_write},
#include "files.h"
};

// How many files in ramdisk
#define FILENUM sizeof(file_table)/sizeof(Finfo)
#define FILEINFO(x) (file_table[fd].x)
// Current processing offset of file
#define FILE_CUR_OFF (FILEINFO(disk_offset) + FILEINFO(open_offset))
// Start offset of this file
#define FILE_START (FILEINFO(disk_offset))
// End offset of this file
#define FILE_END (FILEINFO(disk_offset) + FILEINFO(size) - 1)
// Bound val into [min,max]
#define BOUND(min,val,max) \
if ((long)val < (long)min) \
	val = min; \
else if ((long)val > (long)max) \
val = max;

#define BOUND_MAX(val,max) \
if((long)val > (long)max) \
	val = max;

void init_fs() {
	// TODO: initialize the size of /dev/fb
	AM_GPU_CONFIG_T ev = io_read(AM_GPU_CONFIG);
	int width = ev.width;
	int height = ev.height;
	file_table[FD_FB].size = width * height * sizeof(uint32_t);
}

extern size_t ramdisk_read(void* buf, size_t offset, size_t len);
extern size_t ramdisk_write(const void* buf, size_t offset, size_t len);

// Return the index of @pathname
int fs_open(const char* pathname, int flags, int mode) {
	int fileTableIdx;
	for (fileTableIdx = 0;fileTableIdx < FILENUM;fileTableIdx++) {
		if (strcmp(file_table[fileTableIdx].name, pathname) == 0)
			return fileTableIdx;
	}
	// assert(fileTableIdx != FILENUM); // Should not not-found
	// todo: flags and mode
	return -1;
}

// Read @len bytes from file @fd and store into @buf
size_t fs_read(int fd, void* buf, size_t len) {
	// For those who has own function
	if (file_table[fd].read) {
		return file_table[fd].read(buf, FILEINFO(open_offset), len);
	}
    else {
        // Should not over bound
        BOUND_MAX(len, FILE_END - FILE_CUR_OFF + 1);
		printf("reading %d bytes from %p into %p\n", len, FILE_CUR_OFF, buf);
		int ramdisk_read_length = ramdisk_read(buf, FILE_CUR_OFF, len);
		fs_lseek(fd, ramdisk_read_length, SEEK_CUR);
		return ramdisk_read_length;
	}

}

// Write @len bytes from @buf into file @fd
size_t fs_write(int fd, const void* buf, size_t len) {
	// For those who has own function
	if (file_table[fd].write) {
		return file_table[fd].write(buf, 0, len);
	}
	// Should not over bound
	BOUND_MAX(len, FILE_END - FILE_CUR_OFF + 1);
	int ramdisk_write_length = ramdisk_write(buf, FILE_CUR_OFF, len);
	fs_lseek(fd, ramdisk_write_length, SEEK_CUR);
	return ramdisk_write_length;
}

// Move 
size_t fs_lseek(int fd, off_t offset, int whence) {
	// switch (whence)
	// {
	// case SEEK_SET:
	// 	BOUND(0, offset, FILEINFO(size));
	// 	FILEINFO(open_offset) = offset;
	// 	break;
	// case SEEK_CUR:
	// 	BOUND_MAX(offset, FILE_END - FILE_CUR_OFF);
	// 	FILEINFO(open_offset) += offset;
	// 	break;
	// case(SEEK_END):
	// 	BOUND(-FILEINFO(size), offset, 0);
    //     FILEINFO(open_offset) = FILEINFO(size) + offset;
    //     break;
	// default:
	// 	Log("Invalid whence value: %d\n", whence);
	// 	return -1;
    // }
	// return FILEINFO(open_offset);
	if (fd <= 2) {
		Log("ignore lseek %s", file_table[fd].name);
		return 0;
	}
	Finfo* file = &file_table[fd];
	int new_offset;
	// 根据 whence 参数来计算新的指针位置
	if (whence == SEEK_SET) {
		new_offset = offset;
	}
	else if (whence == SEEK_CUR) {
		new_offset = file->open_offset + offset;
	}
	else if (whence == SEEK_END) {
		new_offset = file->size + offset;
	}
	else {
		Log("Invalid whence value: %d", whence);
		return -1;
	}
	// 检查新的指针位置是否在文件范围内
	if (new_offset < 0 || new_offset > file->size) {
		Log("Seek position out of bounds");
		return -1;
	}
	// 设置新的文件读写指针
	file->open_offset = new_offset;

	return new_offset;
}

// Close file @fd
int fs_close(int fd) {
	// Always success
	return 0;
}
