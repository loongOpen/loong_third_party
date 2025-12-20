
#pragma GCC system_header
#include_next <unistd.h>

#ifndef _QIUNIU_UNISTD_H
#define _QIUNIU_UNISTD_H

#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(ssize_t, read(int fd, void *buf, size_t nbyte));

QIUNIU_DECL(ssize_t, write(int fd, const void *buf, size_t nbyte));

QIUNIU_DECL(int, close(int fildes));

QIUNIU_DECL(unsigned int, sleep(unsigned int seconds));

QIUNIU_DECL(int, usleep(useconds_t usec));

#ifdef __cplusplus
}
#endif

#endif 
