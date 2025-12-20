
#pragma GCC system_header
#include_next <sched.h>

#ifndef _QIUNIU_SCHED_H
#define _QIUNIU_SCHED_H

#include <sys/types.h>
#include <qiuniu/wrappers.h>
#include <qiuniu/uapi/sched.h>

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(int, sched_yield(void));

QIUNIU_DECL(int, sched_get_priority_min(int policy));

QIUNIU_DECL(int, sched_get_priority_max(int policy));

QIUNIU_DECL(int, sched_setscheduler(pid_t pid, int policy,
				    const struct sched_param *param));

QIUNIU_DECL(int, sched_getscheduler(pid_t pid));

int sched_get_priority_min_ex(int policy);

int sched_get_priority_max_ex(int policy);

int sched_setscheduler_ex(pid_t pid, int policy,
			  const struct sched_param_ex *param_ex);

int sched_getscheduler_ex(pid_t pid, int *policy_r,
			  struct sched_param_ex *param_ex);
 
int sched_setconfig_np(int cpu, int policy,
		       const union sched_config *config, size_t len);

ssize_t sched_getconfig_np(int cpu, int policy,
			   union sched_config *config, size_t *len_r);

#ifdef __cplusplus
}
#endif

#endif 
