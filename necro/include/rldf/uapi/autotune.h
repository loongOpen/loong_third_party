
#ifndef _RLDF_UAPI_AUTOTUNE_H
#define _RLDF_UAPI_AUTOTUNE_H

#include <linux/types.h>

#define RLDF_CLASS_AUTOTUNE		RLDF_CLASS_MISC
#define RLDF_SUBCLASS_AUTOTUNE		0

struct autotune_setup {
	__u32 period;
	__u32 quiet;
};

#define AUTOTUNE_RTIOC_IRQ		_IOW(RLDF_CLASS_AUTOTUNE, 0, struct autotune_setup)
#define AUTOTUNE_RTIOC_KERN		_IOW(RLDF_CLASS_AUTOTUNE, 1, struct autotune_setup)
#define AUTOTUNE_RTIOC_USER		_IOW(RLDF_CLASS_AUTOTUNE, 2, struct autotune_setup)
#define AUTOTUNE_RTIOC_PULSE		_IOW(RLDF_CLASS_AUTOTUNE, 3, __u64)
#define AUTOTUNE_RTIOC_RUN		_IOR(RLDF_CLASS_AUTOTUNE, 4, __u32)
#define AUTOTUNE_RTIOC_RESET		_IO(RLDF_CLASS_AUTOTUNE, 5)

#endif 
