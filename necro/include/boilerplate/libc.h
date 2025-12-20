#ifndef _BOILERPLATE_LIBC_H
#define _BOILERPLATE_LIBC_H

#include <limits.h>

#ifdef __IN_NECRO__

#include <necro_config.h>
#include <errno.h>
#include <boilerplate/compiler.h>

#if !HAVE_DECL_PTHREAD_PRIO_NONE
enum {
	PTHREAD_PRIO_NONE,
	PTHREAD_PRIO_INHERIT,
	PTHREAD_PRIO_PROTECT
};
#endif 

#ifndef HAVE_FORK
static inline int fork(void)
{
	errno = ENOSYS;
	return -1;
}
#endif

#ifndef HAVE_PTHREAD_ATFORK
#ifndef HAVE_FORK
static inline
int pthread_atfork(void (*prepare)(void), void (*parent)(void),
		   void (*child)(void))
{
	return 0;
}
#else
#error "fork() without pthread_atfork()"
#endif
#endif 

#ifndef HAVE_PTHREAD_GETATTR_NP
static inline
int pthread_getattr_np(pthread_t th, pthread_attr_t *attr)
{
	return ENOSYS;
}
#endif 

#ifndef HAVE_PTHREAD_CONDATTR_SETCLOCK
static inline
int pthread_condattr_setclock(pthread_condattr_t *__restrict__ attr,
			      clockid_t clock_id)
{
	return clock_id == CLOCK_REALTIME ? 0 : ENOSYS;
}
#endif	

#ifndef HAVE_PTHREAD_CONDATTR_GETCLOCK
static inline
int pthread_condattr_getclock(const pthread_condattr_t *__restrict__ attr,
			      clockid_t *__restrict__ clock_id)
{
	*clock_id = CLOCK_REALTIME;

	return 0;
}
#endif	

#ifndef HAVE_PTHREAD_MUTEXATTR_SETPROTOCOL
static inline
int pthread_mutexattr_setprotocol(pthread_mutexattr_t *__restrict__ attr,
				  int protocol)
{
	return protocol == PTHREAD_PRIO_NONE ? 0 : ENOSYS;
}
#endif 

#ifndef HAVE_PTHREAD_MUTEXATTR_GETPROTOCOL
static inline
int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *
				  __restrict__ attr, int *__restrict__ protocol)
{
	*protocol = PTHREAD_PRIO_NONE;

	return 0;
}
#endif 

#ifndef HAVE_PTHREAD_MUTEXATTR_SETPRIOCEILING
static inline
int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *attr,
				     int prioceiling)
{
	return ENOSYS;
}
#endif 

#ifndef HAVE_PTHREAD_MUTEXATTR_GETPRIOCEILING
static inline
int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *
				      __restrict attr,
				     int *__restrict prioceiling)
{
	return ENOSYS;
}
#endif 

#ifndef HAVE_PTHREAD_MUTEX_SETPRIOCEILING
static inline
int pthread_mutex_setprioceiling(pthread_mutex_t *__restrict attr,
				 int prioceiling,
				 int *__restrict old_ceiling)
{
	return ENOSYS;
}
#endif 

#ifndef HAVE_PTHREAD_MUTEX_GETPRIOCEILING
static inline
int pthread_mutex_getprioceiling(pthread_mutex_t *__restrict attr,
				 int *__restrict prioceiling)
{
	return ENOSYS;
}
#endif 

#ifndef HAVE_PTHREAD_ATTR_SETAFFINITY_NP
#include <sched.h>
static inline
int pthread_attr_setaffinity_np(pthread_attr_t *attr,
				size_t cpusetsize, const cpu_set_t *cpuset)
{
	if (CPU_ISSET(0, cpuset) && CPU_COUNT(cpuset) == 1)
		return 0;
	return ENOSYS;
}
#endif 

#ifndef HAVE_PTHREAD_SETAFFINITY_NP
static inline
int pthread_setaffinity_np(pthread_t thread, size_t cpusetsize,
			   const cpu_set_t *cpuset)
{
	if (CPU_ISSET(0, cpuset) && CPU_COUNT(cpuset) == 1)
		return 0;
	return ENOSYS;
}
#endif 

#ifndef HAVE_PTHREAD_SETSCHEDPRIO

static inline
int pthread_setschedprio(pthread_t thread, int prio)
{
	struct sched_param param;
	int policy, ret;

	ret = pthread_getschedparam(thread, &policy, &param);
	if (ret)
		return ret;

	param.sched_priority = prio;

	return pthread_setschedparam(thread, policy, &param);
}

#endif 

#if !defined(HAVE_CLOCK_NANOSLEEP) && defined(CONFIG_NECRO_MERCURY)

__weak int clock_nanosleep(clockid_t clock_id, int flags,
			   const struct timespec *request,
			   struct timespec *remain)
{
	struct timespec now, tmp;

	tmp = *request;
	if (flags) {
		clock_gettime(CLOCK_REALTIME, &now);
		tmp.tv_sec -= now.tv_sec;
		tmp.tv_nsec -= now.tv_nsec;
		if (tmp.tv_nsec < 0) {
			tmp.tv_sec--;
			tmp.tv_nsec += 1000000000;
		}
	}

	return nanosleep(&tmp, remain);
}
#endif 

#ifndef HAVE_SCHED_GETCPU

__weak int sched_getcpu(void)
{
	return 0;   
}
#endif 

#ifndef HAVE_SHM_OPEN
__weak int shm_open(const char *name, int oflag, mode_t mode)
{
	errno = ENOSYS;
	return -1;
}
#endif	

#ifndef HAVE_SHM_UNLINK
__weak int shm_unlink(const char *name)
{
	errno = ENOSYS;
	return -1;
}
#endif	

#ifndef HAVE_PTHREAD_MUTEXATTR_SETROBUST
#ifdef HAVE_PTHREAD_MUTEXATTR_SETROBUST_NP
#define pthread_mutexattr_setrobust	pthread_mutexattr_setrobust_np
#else
static inline
int pthread_mutexattr_setrobust(const pthread_mutexattr_t *attr,
				int *robustness)
{
	return ENOSYS;
}
#endif 
#endif 

#if !defined(HAVE_PTHREAD_SETNAME_NP) && defined(CONFIG_NECRO_MERCURY)
static inline
int pthread_setname_np(pthread_t thread, const char *name)
{
	return ENOSYS;
}
#endif 

#endif 

#if defined(__QIUNIU_WRAP__) || defined(__IN_NECRO__)

#ifndef HAVE_CLOCK_NANOSLEEP
int clock_nanosleep(clockid_t clock_id, int flags,
		    const struct timespec *request,
		    struct timespec *remain);
#endif 

#ifndef HAVE_PTHREAD_SETNAME_NP
int pthread_setname_np(pthread_t thread, const char *name);
#endif 
#endif 

#ifndef PTHREAD_STACK_DEFAULT
#define PTHREAD_STACK_DEFAULT			\
	({					\
		int __ret = PTHREAD_STACK_MIN;	\
		if (__ret < 65536)		\
			__ret = 65536;		\
		__ret;				\
	})
#endif 

#endif 
