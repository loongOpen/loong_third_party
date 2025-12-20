
#ifndef _QIUNIU_UAPI_THREAD_H
#define _QIUNIU_UAPI_THREAD_H

#include <qiuniu/uapi/kernel/thread.h>

#define PTHREAD_WARNSW             XNWARN
#define PTHREAD_LOCK_SCHED         XNLOCK
#define PTHREAD_DISABLE_LOCKBREAK  XNTRAPLB
#define PTHREAD_CONFORMING     0

struct qiuniu_mutexattr {
	int type : 3;
	int protocol : 3;
	int pshared : 1;
	int __pad : 1;
	int ceiling : 8;  
};

struct qiuniu_condattr {
	int clock : 7;
	int pshared : 1;
};

struct qiuniu_threadstat {
	__u64 xtime;
	__u64 timeout;
	__u64 msw;
	__u64 csw;
	__u64 xsc;
	__u32 status;
	__u32 pf;
	int cpu;
	int cprio;
	char name[XNOBJECT_NAME_LEN];
	char personality[XNOBJECT_NAME_LEN];
};

#endif 
