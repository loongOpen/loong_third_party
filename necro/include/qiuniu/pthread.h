
#pragma GCC system_header
#include_next <pthread.h>

#ifndef _QIUNIU_PTHREAD_H
#define _QIUNIU_PTHREAD_H

#include <boilerplate/libc.h>
#include <qiuniu/wrappers.h>
#include <qiuniu/uapi/thread.h>

typedef struct pthread_attr_ex {
	pthread_attr_t std;
	struct {
		int personality;
		int sched_policy;
		struct sched_param_ex sched_param;
	} nonstd;
} pthread_attr_ex_t;

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(int, pthread_attr_init(pthread_attr_t *attr));

QIUNIU_DECL(int, pthread_create(pthread_t *ptid_r,
				const pthread_attr_t *attr,
				void *(*start) (void *),
				void *arg));

QIUNIU_DECL(int, pthread_getschedparam(pthread_t thread,
				       int *policy,
				       struct sched_param *param));

QIUNIU_DECL(int, pthread_setschedparam(pthread_t thread,
				       int policy,
				       const struct sched_param *param));

QIUNIU_DECL(int, pthread_setschedprio(pthread_t thread, int prio));

QIUNIU_DECL(int, pthread_mutex_init(pthread_mutex_t *mutex,
				    const pthread_mutexattr_t *attr));

QIUNIU_DECL(int, pthread_mutex_destroy(pthread_mutex_t *mutex));

QIUNIU_DECL(int, pthread_mutex_lock(pthread_mutex_t *mutex));

QIUNIU_DECL(int, pthread_mutex_timedlock(pthread_mutex_t *mutex,
					 const struct timespec *to));

QIUNIU_DECL(int, pthread_mutex_trylock(pthread_mutex_t *mutex));

QIUNIU_DECL(int, pthread_mutex_unlock(pthread_mutex_t *mutex));

QIUNIU_DECL(int, pthread_mutex_setprioceiling(pthread_mutex_t *__restrict mutex,
					      int prioceiling,
					      int *__restrict old_ceiling));
  
QIUNIU_DECL(int, pthread_mutex_getprioceiling(pthread_mutex_t *__restrict mutex,
					      int *__restrict old_ceiling));

QIUNIU_DECL(int, pthread_cond_init (pthread_cond_t *cond,
				    const pthread_condattr_t *attr));

QIUNIU_DECL(int, pthread_cond_destroy(pthread_cond_t *cond));

QIUNIU_DECL(int, pthread_cond_wait(pthread_cond_t *cond,
				   pthread_mutex_t *mutex));

QIUNIU_DECL(int, pthread_cond_timedwait(pthread_cond_t *cond,
					pthread_mutex_t *mutex,
					const struct timespec *abstime));

QIUNIU_DECL(int, pthread_cond_signal(pthread_cond_t *cond));

QIUNIU_DECL(int, pthread_cond_broadcast(pthread_cond_t *cond));

QIUNIU_DECL(int, pthread_kill(pthread_t ptid, int sig));

QIUNIU_DECL(int, pthread_join(pthread_t ptid, void **retval));

#ifndef pthread_yield

QIUNIU_DECL(int, pthread_yield(void));
#endif

int pthread_setmode_np(int clrmask, int setmask,
		       int *mask_r);

QIUNIU_DECL(int, pthread_setname_np(pthread_t thread, const char *name));

int pthread_create_ex(pthread_t *ptid_r,
		      const pthread_attr_ex_t *attr_ex,
		      void *(*start)(void *),
		      void *arg);

int pthread_getschedparam_ex(pthread_t ptid,
			     int *pol,
			     struct sched_param_ex *par);

int pthread_setschedparam_ex(pthread_t ptid,
			     int pol,
			     const struct sched_param_ex *par);

int pthread_attr_init_ex(pthread_attr_ex_t *attr_ex);

int pthread_attr_destroy_ex(pthread_attr_ex_t *attr_ex);

int pthread_attr_setschedpolicy_ex(pthread_attr_ex_t *attr_ex,
				   int policy);

int pthread_attr_getschedpolicy_ex(const pthread_attr_ex_t *attr_ex,
				   int *policy);

int pthread_attr_setschedparam_ex(pthread_attr_ex_t *attr_ex,
				  const struct sched_param_ex *param_ex);

int pthread_attr_getschedparam_ex(const pthread_attr_ex_t *attr_ex,
				  struct sched_param_ex *param_ex);

int pthread_attr_getinheritsched_ex(const pthread_attr_ex_t *attr_ex,
				    int *inheritsched);

int pthread_attr_setinheritsched_ex(pthread_attr_ex_t *attr_ex,
				    int inheritsched);

int pthread_attr_getdetachstate_ex(const pthread_attr_ex_t *attr_ex,
				   int *detachstate);

int pthread_attr_setdetachstate_ex(pthread_attr_ex_t *attr_ex,
				   int detachstate);

int pthread_attr_setdetachstate_ex(pthread_attr_ex_t *attr_ex,
				   int detachstate);

int pthread_attr_getstacksize_ex(const pthread_attr_ex_t *attr_ex,
				 size_t *stacksize);

int pthread_attr_setstacksize_ex(pthread_attr_ex_t *attr_ex,
				 size_t stacksize);

int pthread_attr_getscope_ex(const pthread_attr_ex_t *attr_ex,
			     int *scope);

int pthread_attr_setscope_ex(pthread_attr_ex_t *attr_ex,
			     int scope);

int pthread_attr_getpersonality_ex(const pthread_attr_ex_t *attr_ex,
				   int *personality);

int pthread_attr_setpersonality_ex(pthread_attr_ex_t *attr_ex,
				   int personality);
#ifdef __cplusplus
}
#endif

#endif 
