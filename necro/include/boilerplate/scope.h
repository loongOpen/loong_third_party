#ifndef _BOILERPLATE_SCOPE_H
#define _BOILERPLATE_SCOPE_H

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <necro_config.h>

typedef uintptr_t memoff_t;

#ifdef CONFIG_NECRO_PSHARED

extern void *__main_heap;

int pshared_check(void *heap, void *addr);

#define dref_type(t)	memoff_t

#define __memoff(__base, __addr)	((memoff_t)((caddr_t)(__addr) - (caddr_t)(__base)))
#define __memptr(__base, __off)		((void *)((caddr_t)(__base) + (__off)))
#define __memchk(__base, __addr)	pshared_check(__base, __addr)

#define __moff(__p)		__memoff(__main_heap, __p)
#define __moff_nullable(__p)	(__p ? __memoff(__main_heap, __p) : 0)
#define __mptr(__off)		__memptr(__main_heap, __off)
#define __mptr_nullable(__off)	(__off ? __memptr(__main_heap, __off) : NULL)
#define __mchk(__p)		__memchk(__main_heap, __p)

#define mutex_scope_attribute	PTHREAD_PROCESS_SHARED
#define sem_scope_attribute	1
#ifdef CONFIG_NECRO_QIUNIU
#define monitor_scope_attribute	QIUNIU_MONITOR_SHARED
#define event_scope_attribute	QIUNIU_EVENT_SHARED
#endif

#else 

#define __main_heap	NULL

#define dref_type(t)	__typeof__(t)

#define __memoff(__base, __addr)	(__addr)
#define __memptr(__base, __off)		(__off)
#define __memchk(__base, __addr)	1

#define __moff(__p)		(__p)
#define __moff_nullable(__p)	(__p)
#define __mptr(__off)		(__off)
#define __mptr_nullable(__off)	(__off)
#define __mchk(__p)		1

#define mutex_scope_attribute	PTHREAD_PROCESS_PRIVATE
#define sem_scope_attribute	0
#ifdef CONFIG_NECRO_QIUNIU
#define monitor_scope_attribute	0
#define event_scope_attribute	0
#endif

#endif 

#endif 
