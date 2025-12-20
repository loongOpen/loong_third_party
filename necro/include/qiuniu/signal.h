
#pragma GCC system_header
#include_next <signal.h>

#ifndef _QIUNIU_SIGNAL_H
#define _QIUNIU_SIGNAL_H


#include_next <signal.h>
#include <qiuniu/wrappers.h>
#include <qiuniu/uapi/signal.h>

#ifndef sigev_notify_thread_id
#define sigev_notify_thread_id	 _sigev_un._tid
#endif

#ifdef __cplusplus
extern "C" {
#endif

int qiuniu_sigshadow_handler(int sig, siginfo_t *si,
			     void *ctxt);

void qiuniu_sigdebug_handler(int sig, siginfo_t *si,
			     void *context);

QIUNIU_DECL(int, sigpending(sigset_t *set));

QIUNIU_DECL(int, sigwait(const sigset_t *set, int *sig));

QIUNIU_DECL(int, sigwaitinfo(const sigset_t *set, siginfo_t *si));

QIUNIU_DECL(int, sigtimedwait(const sigset_t *set, siginfo_t *si,
			      const struct timespec *timeout));

QIUNIU_DECL(int, kill(pid_t pid, int sig));

QIUNIU_DECL(int, sigqueue(pid_t pid, int sig,
			  const union sigval value));

#ifdef __cplusplus
}
#endif

#endif 
