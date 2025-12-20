
#ifndef _QIUNIU_UAPI_MUTEX_H
#define _QIUNIU_UAPI_MUTEX_H

#include <qiuniu/uapi/kernel/types.h>

#define QIUNIU_MUTEX_MAGIC  0x86860303

struct qiuniu_mutex_state {
	atomic_t owner;
	__u32 flags;
#define QIUNIU_MUTEX_COND_SIGNAL 0x00000001
#define QIUNIU_MUTEX_ERRORCHECK  0x00000002
	__u32 ceiling;
};

union qiuniu_mutex_union {
	pthread_mutex_t native_mutex;
	struct qiuniu_mutex_shadow {
		__u32 magic;
		__u32 lockcnt;
		__u32 state_offset;
		xnhandle_t handle;
		struct qiuniu_mutexattr attr;
	} shadow_mutex;
};

#endif 
