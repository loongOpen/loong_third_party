
#pragma GCC system_header
#include_next <sys/ioctl.h>

#ifndef _QIUNIU_SYS_IOCTL_H
#define _QIUNIU_SYS_IOCTL_H

#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(int, ioctl(int fildes, unsigned int request, ...));

#ifdef __cplusplus
}
#endif

#endif 
