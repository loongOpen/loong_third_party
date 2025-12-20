
#ifndef _QIUNIU_UAPI_KERNEL_HEAP_H
#define _QIUNIU_UAPI_KERNEL_HEAP_H

#include <linux/types.h>

#define QIUNIU_MEMDEV_PRIVATE  "memdev-private"
#define QIUNIU_MEMDEV_SHARED   "memdev-shared"
#define QIUNIU_MEMDEV_SYS      "memdev-sys"

struct qiuniu_memdev_stat {
	__u32 size;
	__u32 free;
};

#define MEMDEV_RTIOC_STAT	_IOR(RLDF_CLASS_MEMORY, 0, struct qiuniu_memdev_stat)

#endif 
