#ifndef _BOILERPLATE_TIME_H
#define _BOILERPLATE_TIME_H

#include <time.h>

typedef unsigned long long ticks_t;

typedef long long sticks_t;

#ifdef __cplusplus
extern "C" {
#endif

void timespec_sub(struct timespec *__restrict r,
		  const struct timespec *__restrict t1,
		  const struct timespec *__restrict t2);

void timespec_subs(struct timespec *__restrict r,
		   const struct timespec *__restrict t1,
		   sticks_t t2);

void timespec_add(struct timespec *__restrict r,
		  const struct timespec *__restrict t1,
		  const struct timespec *__restrict t2);

void timespec_adds(struct timespec *__restrict r,
		   const struct timespec *__restrict t1,
		   sticks_t t2);

void timespec_sets(struct timespec *__restrict r,
		   ticks_t ns);

#ifdef __cplusplus
}
#endif

static inline sticks_t timespec_scalar(const struct timespec *__restrict t)
{
	return t->tv_sec * 1000000000LL + t->tv_nsec;
}

static inline int __attribute__ ((always_inline))
timespec_before(const struct timespec *__restrict t1,
		const struct timespec *__restrict t2)
{
	if (t1->tv_sec < t2->tv_sec)
		return 1;

	if (t1->tv_sec == t2->tv_sec &&
	    t1->tv_nsec < t2->tv_nsec)
		return 1;

	return 0;
}

static inline int __attribute__ ((always_inline))
timespec_before_or_same(const struct timespec *__restrict t1,
			const struct timespec *__restrict t2)
{
	if (t1->tv_sec < t2->tv_sec)
		return 1;

	if (t1->tv_sec == t2->tv_sec &&
	    t1->tv_nsec <= t2->tv_nsec)
		return 1;

	return 0;
}

static inline int __attribute__ ((always_inline))
timespec_after(const struct timespec *__restrict t1,
	       const struct timespec *__restrict t2)
{
	return !timespec_before_or_same(t1, t2);
}

static inline int __attribute__ ((always_inline))
timespec_after_or_same(const struct timespec *__restrict t1,
		       const struct timespec *__restrict t2)
{
	return !timespec_before(t1, t2);
}

#endif 
