
#ifndef _QIUNIU_UAPI_EVENT_H
#define _QIUNIU_UAPI_EVENT_H

#include <qiuniu/uapi/kernel/types.h>

struct qiuniu_event_state {
	__u32 value;
	__u32 flags;
#define QIUNIU_EVENT_PENDED  0x1
	__u32 nwaiters;
};

struct qiuniu_event;


#define QIUNIU_EVENT_FIFO    0x0
#define QIUNIU_EVENT_PRIO    0x1
#define QIUNIU_EVENT_SHARED  0x2


#define QIUNIU_EVENT_ALL  0x0
#define QIUNIU_EVENT_ANY  0x1

struct qiuniu_event_shadow {
	__u32 state_offset;
	__u32 flags;
	xnhandle_t handle;
};

struct qiuniu_event_info {
	unsigned int value;
	int flags;
	int nrwait;
};

typedef struct qiuniu_event_shadow qiuniu_event_t;

#endif 
