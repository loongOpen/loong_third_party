
#ifndef _QIUNIU_UAPI_COND_H
#define _QIUNIU_UAPI_COND_H

#include <qiuniu/uapi/mutex.h>

#define QIUNIU_COND_MAGIC 0x86860505

struct qiuniu_cond_state {
	__u32 pending_signals;
	__u32 mutex_state_offset;
};

union qiuniu_cond_union {
	pthread_cond_t native_cond;
	struct qiuniu_cond_shadow {
		__u32 magic;
		__u32 state_offset;
		xnhandle_t handle;
	} shadow_cond;
};

#endif 
