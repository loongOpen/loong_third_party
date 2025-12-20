
#ifndef _QIUNIU_UAPI_MONITOR_H
#define _QIUNIU_UAPI_MONITOR_H

#include <qiuniu/uapi/kernel/types.h>

struct qiuniu_monitor_state {
	atomic_t owner;
	__u32 flags;
#define QIUNIU_MONITOR_GRANTED    0x01
#define QIUNIU_MONITOR_DRAINED    0x02
#define QIUNIU_MONITOR_SIGNALED   0x03 
#define QIUNIU_MONITOR_BROADCAST  0x04
#define QIUNIU_MONITOR_PENDED     0x08
};

struct qiuniu_monitor;

struct qiuniu_monitor_shadow {
	__u32 state_offset;
	__u32 flags;
	xnhandle_t handle;
#define QIUNIU_MONITOR_SHARED     0x1
#define QIUNIU_MONITOR_WAITGRANT  0x0
#define QIUNIU_MONITOR_WAITDRAIN  0x1
};

typedef struct qiuniu_monitor_shadow qiuniu_monitor_t;

#endif 
