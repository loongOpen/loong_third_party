
#pragma GCC system_header
#include_next <sys/select.h>

#ifndef _QIUNIU_SYS_SELECT_H
#define _QIUNIU_SYS_SELECT_H

#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(int, select(int __nfds, fd_set *__restrict __readfds,
			fd_set *__restrict __writefds,
			fd_set *__restrict __exceptfds,
			struct timeval *__restrict __timeout));
#ifdef __cplusplus
}
#endif

#endif 
