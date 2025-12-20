
#ifndef _QIUNIU_UAPI_KERNEL_SYNCH_H
#define _QIUNIU_UAPI_KERNEL_SYNCH_H

#include <qiuniu/uapi/kernel/types.h>


#define XNSYNCH_FIFO    0x0
#define XNSYNCH_PRIO    0x1
#define XNSYNCH_PI      0x2
#define XNSYNCH_DREORD  0x4
#define XNSYNCH_OWNER   0x8
#define XNSYNCH_PP      0x10


static inline int xnsynch_fast_is_claimed(xnhandle_t handle)
{
	return (handle & XNSYNCH_FLCLAIM) != 0;
}

static inline xnhandle_t xnsynch_fast_claimed(xnhandle_t handle)
{
	return handle | XNSYNCH_FLCLAIM;
}

static inline xnhandle_t xnsynch_fast_ceiling(xnhandle_t handle)
{
	return handle | XNSYNCH_FLCEIL;
}

static inline int
xnsynch_fast_owner_check(atomic_t *fastlock, xnhandle_t ownerh)
{
	return (xnhandle_get_id(atomic_read(fastlock)) == ownerh) ?
		0 : -EPERM;
}

static inline
int xnsynch_fast_acquire(atomic_t *fastlock, xnhandle_t new_ownerh)
{
	xnhandle_t h;

	h = atomic_cmpxchg(fastlock, XN_NO_HANDLE, new_ownerh);
	if (h != XN_NO_HANDLE) {
		if (xnhandle_get_id(h) == new_ownerh)
			return -EBUSY;

		return -EAGAIN;
	}

	return 0;
}

static inline
int xnsynch_fast_release(atomic_t *fastlock, xnhandle_t cur_ownerh)
{
	return (xnhandle_t)atomic_cmpxchg(fastlock, cur_ownerh, XN_NO_HANDLE)
		== cur_ownerh;
}


static inline int xnsynch_is_shared(xnhandle_t handle)
{
	return (handle & XNSYNCH_PSHARED) != 0;
}

#endif 
