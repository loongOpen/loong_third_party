
#ifndef _QIUNIU_TICKS_H
#define _QIUNIU_TICKS_H

#include <stdbool.h>
#include <qiuniu/uapi/kernel/types.h>



#ifdef __cplusplus
extern "C" {
#endif

extern unsigned long long __qiuniu_tsc_clockfreq;

static inline bool qiuniu_use_legacy_tsc(void)
{
	return !!__qiuniu_tsc_clockfreq;
}

xnsticks_t __qiuniu_tsc_to_ns(xnsticks_t ticks);

xnsticks_t __qiuniu_tsc_to_ns_rounded(xnsticks_t ticks);

xnsticks_t __qiuniu_ns_to_tsc(xnsticks_t ns);

static inline
xnsticks_t qiuniu_ns_to_ticks(xnsticks_t ns)
{
	if (qiuniu_use_legacy_tsc())
		return __qiuniu_ns_to_tsc(ns);

	return ns;
}

static inline
xnsticks_t qiuniu_ticks_to_ns(xnsticks_t ticks)
{
	if (qiuniu_use_legacy_tsc())
		return __qiuniu_tsc_to_ns(ticks);

	return ticks;
}

static inline
xnsticks_t qiuniu_ticks_to_ns_rounded(xnsticks_t ticks)
{
	if (qiuniu_use_legacy_tsc())
		return __qiuniu_tsc_to_ns_rounded(ticks);

	return ticks;
}

unsigned long long qiuniu_divrem_billion(unsigned long long value,
					 unsigned long *rem);
#ifdef __cplusplus
}
#endif

#endif 
