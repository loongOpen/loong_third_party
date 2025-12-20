
#ifndef _QIUNIU_UAPI_TIME_H
#define _QIUNIU_UAPI_TIME_H

#ifndef CLOCK_MONOTONIC_RAW
#define CLOCK_MONOTONIC_RAW  4
#endif


#define __QIUNIU_CLOCK_STATIC(nr)	((clockid_t)(nr + 32))

#define CLOCK_HOST_REALTIME  __QIUNIU_CLOCK_STATIC(0)

#define QIUNIU_MAX_EXTCLOCKS  64

#define __QIUNIU_CLOCK_EXT(nr)		((clockid_t)(nr) | (1 << 6))
#define __QIUNIU_CLOCK_EXT_P(id)	((int)(id) >= 64 && (int)(id) < 128)
#define __QIUNIU_CLOCK_EXT_INDEX(id)	((int)(id) & ~(1 << 6))


#define TFD_WAKEUP	(1 << 2)

#endif 
