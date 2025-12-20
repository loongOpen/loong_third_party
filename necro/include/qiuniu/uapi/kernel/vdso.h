
#ifndef _QIUNIU_UAPI_KERNEL_VDSO_H
#define _QIUNIU_UAPI_KERNEL_VDSO_H

#include <qiuniu/uapi/kernel/urw.h>


struct xnvdso_hostrt_data {
	__u64 wall_sec;
	__u64 wtom_sec;
	__u64 cycle_last;
	__u64 mask;
	__u32 wall_nsec;
	__u32 wtom_nsec;
	__u32 mult;
	__u32 shift;
	__u32 live;
	urw_t lock;
};


struct xnvdso {
	__u64 features;
	struct xnvdso_hostrt_data hostrt_data;
	
	__u64 wallclock_offset;
};


#define XNVDSO_FEAT_HOST_REALTIME	0x0000000000000001ULL
#define XNVDSO_FEAT_WALLCLOCK_OFFSET	0x0000000000000002ULL

static inline int xnvdso_test_feature(struct xnvdso *vdso,
				      __u64 feature)
{
	return (vdso->features & feature) != 0;
}

#endif 
