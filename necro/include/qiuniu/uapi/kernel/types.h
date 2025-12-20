
#ifndef _QIUNIU_UAPI_KERNEL_TYPES_H
#define _QIUNIU_UAPI_KERNEL_TYPES_H

#include <linux/types.h>
#include <qiuniu/uapi/kernel/limits.h>

typedef __u64 xnticks_t;

typedef __s64 xnsticks_t;

typedef __u32 xnhandle_t;

#define XN_NO_HANDLE		((xnhandle_t)0)
#define XN_HANDLE_INDEX_MASK	((xnhandle_t)0xf0000000)


#define XNSYNCH_PSHARED		((xnhandle_t)0x40000000)


#define XNSYNCH_FLCLAIM		((xnhandle_t)0x80000000) 
#define XNSYNCH_FLCEIL		((xnhandle_t)0x20000000) 

#define XN_HANDLE_TRANSIENT_MASK	(XNSYNCH_FLCLAIM|XNSYNCH_FLCEIL)


static inline xnhandle_t xnhandle_get_index(xnhandle_t handle)
{
	return handle & ~XN_HANDLE_INDEX_MASK;
}


static inline xnhandle_t xnhandle_get_id(xnhandle_t handle)
{
	return handle & ~XN_HANDLE_TRANSIENT_MASK;
}


struct __user_old_timespec {
	long  tv_sec;
	long  tv_nsec;
};

struct __user_old_itimerspec {
	struct __user_old_timespec it_interval;
	struct __user_old_timespec it_value;
};

struct __user_old_timeval {
	long  tv_sec;
	long  tv_usec;
};


struct __user_old_timex {
	unsigned int modes;	
	__kernel_long_t offset;	
	__kernel_long_t freq;	
	__kernel_long_t maxerror;
	__kernel_long_t esterror;
	int status;		
	__kernel_long_t constant;
	__kernel_long_t precision;
	__kernel_long_t tolerance;
	struct __user_old_timeval time;	
	__kernel_long_t tick;	

	__kernel_long_t ppsfreq;
	__kernel_long_t jitter; 
	int shift;              
	__kernel_long_t stabil;      
	__kernel_long_t jitcnt; 
	__kernel_long_t calcnt; 
	__kernel_long_t errcnt; 
	__kernel_long_t stbcnt; 

	int tai;		

	int  :32; int  :32; int  :32; int  :32;
	int  :32; int  :32; int  :32; int  :32;
	int  :32; int  :32; int  :32;
};

#endif 
