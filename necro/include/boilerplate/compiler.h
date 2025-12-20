#ifndef _BOILERPLATE_COMPILER_H
#define _BOILERPLATE_COMPILER_H

#include <stddef.h>

#define container_of(ptr, type, member)					\
	({								\
		const __typeof__(((type *)0)->member) *__mptr = (ptr);	\
		(type *)((char *)__mptr - offsetof(type, member));	\
	})

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

#ifndef __noreturn
#define __noreturn	__attribute__((__noreturn__))
#endif

#ifndef __must_check
#define __must_check	__attribute__((__warn_unused_result__))
#endif

#ifndef __weak
#define __weak		__attribute__((__weak__))
#endif

#ifndef __maybe_unused
#define __maybe_unused	__attribute__((__unused__))
#endif

#ifndef __aligned
#define __aligned(__n)	__attribute__((aligned (__n)))
#endif

#ifndef __deprecated
#define __deprecated	__attribute__((__deprecated__))
#endif

#ifndef __packed
#define __packed	__attribute__((__packed__))
#endif

#ifndef __alloc_size
#define __alloc_size(__args)	__attribute__((__alloc_size__(__args)))
#endif

#define __align_to(__size, __al)  (((__size) + (__al) - 1) & (~((__al) - 1)))

#ifdef __cplusplus
extern "C" {
#endif

#define necro_count_trailing_zeros(x)					\
	((x) == 0 ? (int)(sizeof(x) * __CHAR_BIT__)			\
	: sizeof(x) <= sizeof(unsigned int) ?				\
		__builtin_ctz((unsigned int)x)				\
	: sizeof(x) <= sizeof(unsigned long) ?				\
		__builtin_ctzl((unsigned long)x)			\
	: __builtin_ctzll(x))

#define necro_count_leading_zeros(x)					\
	((x) == 0 ? (int)(sizeof(x) * __CHAR_BIT__)			\
	: sizeof(x) <= sizeof(unsigned int) ?				\
		__builtin_clz((unsigned int)x) +			\
			(int)(sizeof(unsigned int) - sizeof(x))		\
	: sizeof(x) <= sizeof(unsigned long) ?				\
		__builtin_clzl((unsigned long)x)			\
	: __builtin_clzll(x))

#ifdef __cplusplus
}
#endif

#endif 
