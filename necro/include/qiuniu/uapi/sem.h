
#ifndef _QIUNIU_UAPI_SEM_H
#define _QIUNIU_UAPI_SEM_H

#include <qiuniu/uapi/kernel/types.h>

#define QIUNIU_SEM_MAGIC (0x86860707)
#define QIUNIU_NAMED_SEM_MAGIC (0x86860D0D)

struct qiuniu_sem;

struct qiuniu_sem_state {
	atomic_t value;
	__u32 flags;
};

union qiuniu_sem_union {
	sem_t native_sem;
	struct qiuniu_sem_shadow {
		__u32 magic;
		__s32 state_offset;
		xnhandle_t handle;
	} shadow_sem;
};

struct qiuniu_sem_info {
	unsigned int value;
	int flags;
	int nrwait;
};

#define SEM_FIFO       0x1
#define SEM_PULSE      0x2
#define SEM_PSHARED    0x4
#define SEM_REPORT     0x8
#define SEM_WARNDEL    0x10
#define SEM_RAWCLOCK   0x20
#define SEM_NOBUSYDEL  0x40

#endif 
