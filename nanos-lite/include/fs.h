#ifndef __FS_H__
#define __FS_H__

#include <common.h>

#ifndef SEEK_SET
enum {SEEK_SET, SEEK_CUR, SEEK_END};
#endif

typedef long off_t;

enum { FD_STDIN, FD_STDOUT, FD_STDERR, FD_EVTDEV, FD_FB };

int fs_open(const char* pathname, int flags, int mode);
size_t fs_read(int fd, void* buf, size_t len);
size_t fs_write(int fd, const void* buf, size_t len);
size_t fs_lseek(int fd, off_t offset, int whence);
int fs_close(int fd);

#endif
