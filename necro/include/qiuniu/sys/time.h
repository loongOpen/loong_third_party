
#pragma GCC system_header
#include_next <sys/time.h>

#ifndef _QIUNIU_SYS_TIME_H
#define _QIUNIU_SYS_TIME_H

#include <qiuniu/wrappers.h>

struct timezone;

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(int, gettimeofday(struct timeval *tv,
			      struct timezone *tz));

#ifdef __cplusplus
}
#endif

#endif 
