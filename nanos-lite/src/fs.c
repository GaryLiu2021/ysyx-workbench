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

enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_FB};

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
  [FD_STDIN] = {"stdin", 0, 0, invalid_read, invalid_write},
  [FD_STDOUT] = {"stdout", 0, 0, invalid_read, invalid_write},
  [FD_STDERR] = {"stderr", 0, 0, invalid_read, invalid_write},
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
if (val < min) \
	val = min; \
else if (val > max) \
val = max;

#define BOUND_MAX(val,max) \
if(val > max) \
	val = max;

void init_fs() {
  // TODO: initialize the size of /dev/fb
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
	assert(fileTableIdx != FILENUM); // Should not not-found
	// todo: flags and mode
	return -1;
}

// Read @len bytes from file @fd and store into @buf
size_t fs_read(int fd, void* buf, size_t len) {
	// Should not over bound
	int overflow = (FILE_CUR_OFF + len - 1) - FILE_END;
	if (overflow > 0)
		len -= overflow;
	
	if (fd < 3) {
		return 0;
	}
	else {
		printf("read %d bytes from %p into %p\n", len, FILE_CUR_OFF, buf);
		int ramdisk_read_length = ramdisk_read(buf, FILE_CUR_OFF, len);
		fs_lseek(fd, ramdisk_read_length, SEEK_CUR);
		return ramdisk_read_length;
	}

}

// Write @len bytes from @buf into file @fd
size_t fs_write(int fd, const void* buf, size_t len) {
	// Should not over bound
	assert((FILE_CUR_OFF + len - 1) <= FILE_END);
	
	if (fd == 0) {
		return 0;
	}
	// If write stdout or stderr, putch
	else if (fd == 1 || fd == 2) {
		for (int i = 0;i < len;i++) {
			putch(((char*)buf)[i]);
		}
		return len;
	}
	else {
		int ramdisk_write_length = ramdisk_write(buf, FILE_CUR_OFF, len);
		fs_lseek(fd, ramdisk_write_length, SEEK_CUR);
		return ramdisk_write_length;
	}
}

// Move 
size_t fs_lseek(int fd, off_t offset, int whence) {
	switch (whence)
	{
	case SEEK_SET:
		BOUND(0, offset, FILEINFO(size));
		FILEINFO(open_offset) = offset;
		break;
	case SEEK_CUR:
		BOUND_MAX(offset, FILE_END - FILE_CUR_OFF);
		FILEINFO(open_offset) += offset;
		break;
	case(SEEK_END):
		BOUND(-FILEINFO(size), offset, 0);
		FILEINFO(open_offset) = FILEINFO(size) + offset;
		break;
	default:
		panic("Not implemented");
		break;
	}
	return FILEINFO(open_offset);
}

// Close file @fd
int fs_close(int fd) {
	// Always success
	return 0;
}
