
#ifndef _QIUNIU_SYS_QIUNIU_H
#define _QIUNIU_SYS_QIUNIU_H

#include <sys/types.h>
#include <signal.h>
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <boilerplate/atomic.h>
#include <boilerplate/list.h>
#include <qiuniu/uapi/kernel/synch.h>
#include <qiuniu/uapi/kernel/vdso.h>
#include <qiuniu/uapi/corectl.h>
#include <qiuniu/uapi/mutex.h>
#include <qiuniu/uapi/event.h>
#include <qiuniu/uapi/monitor.h>
#include <qiuniu/uapi/thread.h>
#include <qiuniu/uapi/cond.h>
#include <qiuniu/uapi/sem.h>
#include <qiuniu/ticks.h>

#define qiuniu_commit_memory(p) __qiuniu_commit_memory(p, sizeof(*p))

struct qiuniu_tsd_hook {
	void (*create_tsd)(void);
	void (*delete_tsd)(void);
	struct pvholder next;
};

#ifdef __cplusplus
extern "C" {
#endif

int qiuniu_extend(unsigned int magic);

int qiuniu_corectl(int request, void *buf, size_t bufsz);

int qiuniu_thread_stat(pid_t pid,
		       struct qiuniu_threadstat *stat);

int qiuniu_serial_debug(const char *fmt, ...);

void __qiuniu_commit_memory(void *p, size_t len);

void qiuniu_thread_harden(void);

void qiuniu_thread_relax(void);

int qiuniu_thread_join(pthread_t thread);

pid_t qiuniu_thread_pid(pthread_t thread);

int qiuniu_thread_mode(void);
  
int qiuniu_monitor_init(qiuniu_monitor_t *mon,
			clockid_t clk_id, int flags);

int qiuniu_monitor_destroy(qiuniu_monitor_t *mon);

int qiuniu_monitor_enter(qiuniu_monitor_t *mon);

int qiuniu_monitor_exit(qiuniu_monitor_t *mon);

int qiuniu_monitor_wait(qiuniu_monitor_t *mon, int event,
			const struct timespec *ts);

void qiuniu_monitor_grant(qiuniu_monitor_t *mon,
			  struct xnthread_user_window *u_window);

int qiuniu_monitor_grant_sync(qiuniu_monitor_t *mon,
			      struct xnthread_user_window *u_window);

void qiuniu_monitor_grant_all(qiuniu_monitor_t *mon);

int qiuniu_monitor_grant_all_sync(qiuniu_monitor_t *mon);

void qiuniu_monitor_drain(qiuniu_monitor_t *mon);

int qiuniu_monitor_drain_sync(qiuniu_monitor_t *mon);

void qiuniu_monitor_drain_all(qiuniu_monitor_t *mon);

int qiuniu_monitor_drain_all_sync(qiuniu_monitor_t *mon);

int qiuniu_event_init(qiuniu_event_t *event,
		      unsigned int value,
		      int flags);

int qiuniu_event_post(qiuniu_event_t *event,
		      unsigned int bits);

int qiuniu_event_wait(qiuniu_event_t *event,
		      unsigned int bits,
		      unsigned int *bits_r,
		      int mode,
		      const struct timespec *timeout);

unsigned long qiuniu_event_clear(qiuniu_event_t *event,
				 unsigned int bits);

int qiuniu_event_inquire(qiuniu_event_t *event,
			 struct qiuniu_event_info *info,
			 pid_t *waitlist, size_t waitsz);

int qiuniu_event_destroy(qiuniu_event_t *event);

int qiuniu_sem_inquire(sem_t *sem, struct qiuniu_sem_info *info,
		       pid_t *waitlist, size_t waitsz);

int qiuniu_sched_weighted_prio(int policy,
			       const struct sched_param_ex *param_ex);

void qiuniu_register_tsd_hook(struct qiuniu_tsd_hook *th);

void qiuniu_assert_nrt(void);

unsigned long long qiuniu_read_tsc(void);

extern int __qiuniu_control_bind;

#ifdef __cplusplus
}
#endif

#endif 
