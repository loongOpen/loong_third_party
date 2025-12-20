
#ifndef _QIUNIU_WRAPPERS_H
#define _QIUNIU_WRAPPERS_H

#include <boilerplate/compiler.h>

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

#define __WRAP(call)		__wrap_ ## call
#define __STD(call)		__real_ ## call
#define __QIUNIU(call)		__qiuniu_ ## call
#define __RT(call)		__QIUNIU(call)
#define QIUNIU_DECL(T, P)	\
	__typeof__(T) __RT(P);	\
	__typeof__(T) __STD(P); \
	__typeof__(T) __WRAP(P)


#define QIUNIU_IMPL(T, I, A)								\
__typeof__(T) __wrap_ ## I A __attribute__((alias("__qiuniu_" __stringify(I)), weak));	\
__typeof__(T) __qiuniu_ ## I A

#endif 
