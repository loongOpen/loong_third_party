
#ifndef _QIUNIU_SYS_TIMERFD_H
#define _QIUNIU_SYS_TIMERFD_H

#pragma GCC system_header
#include_next <sys/timerfd.h>
#include <qiuniu/wrappers.h>
#include <qiuniu/uapi/time.h>

#ifdef __cplusplus
extern "C" {
#endif 

QIUNIU_DECL(int, timerfd_create(int clockid, int flags));

QIUNIU_DECL(int, timerfd_settime(int fd, int flags,
		const struct itimerspec *new_value,
		struct itimerspec *old_value));

QIUNIU_DECL(int, timerfd_gettime(int fd, struct itimerspec *curr_value));

#ifdef __cplusplus
}
#endif 

#endif 
