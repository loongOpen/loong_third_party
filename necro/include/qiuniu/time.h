
#pragma GCC system_header
#include_next <time.h>

#ifndef _QIUNIU_TIME_H
#define _QIUNIU_TIME_H


#include_next <time.h>
#include <qiuniu/wrappers.h>
#include <qiuniu/uapi/time.h>

#ifdef __cplusplus
extern "C" {
#endif

struct timex;

QIUNIU_DECL(int, clock_getres(clockid_t clock_id,
			      struct timespec *tp));

QIUNIU_DECL(int, clock_gettime(clockid_t clock_id,
			       struct timespec *tp));

QIUNIU_DECL(int, clock_settime(clockid_t clock_id,
			       const struct timespec *tp));

QIUNIU_DECL(int, clock_adjtime(clockid_t clock_id,
			       struct timex *tx));

QIUNIU_DECL(int, clock_nanosleep(clockid_t clock_id,
				 int flags,
				 const struct timespec *rqtp,
				 struct timespec *rmtp));

QIUNIU_DECL(time_t, time(time_t *t));

QIUNIU_DECL(int, nanosleep(const struct timespec *rqtp,
			   struct timespec *rmtp));

QIUNIU_DECL(int, timer_create(clockid_t clockid,
			      const struct sigevent *__restrict__ evp,
			      timer_t * __restrict__ timerid));

QIUNIU_DECL(int, timer_delete(timer_t timerid));

QIUNIU_DECL(int, timer_settime(timer_t timerid,
			       int flags,
			       const struct itimerspec *value,
			       struct itimerspec *ovalue));

QIUNIU_DECL(int, timer_gettime(timer_t timerid,
			       struct itimerspec *value));

QIUNIU_DECL(int, timer_getoverrun(timer_t timerid));

#ifdef __cplusplus
}
#endif

#endif 
