
#pragma GCC system_header
#include_next <fcntl.h>

#ifndef _QIUNIU_FCNTL_H
#define _QIUNIU_FCNTL_H

#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(int, open(const char *path, int oflag, ...));

QIUNIU_DECL(int, open64(const char *path, int oflag, ...));

QIUNIU_DECL(int, __open_2(const char *path, int oflag));

QIUNIU_DECL(int, __open64_2(const char *path, int oflag));

QIUNIU_DECL(int, fcntl(int fd, int cmd, ...));

#ifdef __cplusplus
}
#endif

#endif 
