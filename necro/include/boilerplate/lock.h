
#ifndef _BOILERPLATE_LOCK_H
#define _BOILERPLATE_LOCK_H

#include <pthread.h>
#include <boilerplate/wrappers.h>
#include <boilerplate/debug.h>


struct service {
	int cancel_type;
};

#ifdef CONFIG_NECRO_ASYNC_CANCEL

#define CANCEL_DEFER(__s)					\
	do {								\
		pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,		\
				      &(__s).cancel_type);		\
	} while (0)

#define CANCEL_RESTORE(__s)					\
	do {								\
		pthread_setcanceltype((__s).cancel_type, NULL);		\
		backtrace_check();					\
	} while (0)

#else  

#define CANCEL_DEFER(__s)	do { (void)(__s); } while (0)

#define CANCEL_RESTORE(__s)	do { } while (0)

#endif  

struct cleanup_block {
	pthread_mutex_t *lock;
	void (*handler)(void *arg);
	void *arg;
};

#define __push_cleanup_args(__cb, __lock, __fn, __arg)	\
	((__cb)->lock = (__lock)),			\
	((__cb)->handler = (void (*)(void *))(__fn)),	\
	((__cb)->arg = (__arg))

#define push_cleanup_handler(__cb, __lock, __fn, __arg)			\
	pthread_cleanup_push((void (*)(void *))__run_cleanup_block,	\
			     (__push_cleanup_args(__cb, __lock, __fn, __arg), (__cb)))

#define pop_cleanup_handler(__cb)	\
	pthread_cleanup_pop(0)

#define push_cleanup_lock(__lock)	\
	pthread_cleanup_push((void (*)(void *))__RT(pthread_mutex_unlock), (__lock))

#define pop_cleanup_lock(__lock)	\
	pthread_cleanup_pop(0)

#ifdef CONFIG_NECRO_DEBUG
int __check_cancel_type(const char *locktype);
#else
#define __check_cancel_type(__locktype)				\
	({ (void)__locktype; 0; })
#endif

#define __do_lock(__lock, __op)					\
	({							\
		int __ret;					\
		__ret = -__RT(pthread_mutex_##__op(__lock));	\
		__ret;						\
	})

#define __do_lock_nocancel(__lock, __type, __op)			\
	({								\
		__bt(__check_cancel_type(#__op "_nocancel"));		\
		__do_lock(__lock, __op);				\
	})

#define __do_unlock(__lock)					\
	({							\
		int __ret;					\
		__ret = -__RT(pthread_mutex_unlock(__lock));	\
		__ret;						\
	})

#define read_lock(__lock)			\
	__do_lock(__lock, lock)

#define read_trylock(__lock)			\
	__do_lock(__lock, trylock)

#define read_lock_nocancel(__lock)		\
	__do_lock_nocancel(__lock, read_lock, lock)

#define read_trylock_nocancel(__lock)		\
	__do_lock_nocancel(__lock, read_trylock, trylock)

#define read_unlock(__lock)			\
	__do_unlock(__lock)

#define write_lock(__lock)			\
	__do_lock(__lock, lock)

#define write_trylock(__lock)			\
	__do_lock(__lock, trylock)

#define write_lock_nocancel(__lock)		\
	__do_lock_nocancel(__lock, write_lock, lock)

#define write_trylock_nocancel(__lock)		\
	__do_lock_nocancel(__lock, write_trylock, trylock)

#define write_unlock(__lock)			\
	__do_unlock(__lock)

#define __do_lock_safe(__lock, __state, __op)				\
	({								\
		int __ret, __oldstate;					\
		__bt(__check_cancel_type(#__op "_safe"));		\
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &__oldstate); \
		__ret = -__RT(pthread_mutex_##__op(__lock));		\
		if (__ret)						\
			pthread_setcancelstate(__oldstate, NULL);	\
		__state = __oldstate;					\
		__ret;							\
	})

#define __do_unlock_safe(__lock, __state)				\
	({								\
		int __ret, __restored_state = __state;			\
		__ret = -__RT(pthread_mutex_unlock(__lock));		\
		pthread_setcancelstate(__restored_state, NULL);		\
		__ret;							\
	})



#define write_lock_safe(__lock, __state)	\
	__do_lock_safe(__lock, __state, lock)

#define write_trylock_safe(__lock, __state)	\
	__do_lock_safe(__lock, __state, trylock)

#define write_unlock_safe(__lock, __state)	\
	__do_unlock_safe(__lock, __state)

#define read_lock_safe(__lock, __state)	\
	__do_lock_safe(__lock, __state, lock)

#define read_unlock_safe(__lock, __state)	\
	__do_unlock_safe(__lock, __state)

#ifdef CONFIG_NECRO_DEBUG
#define mutex_type_attribute PTHREAD_MUTEX_ERRORCHECK
#else
#define mutex_type_attribute PTHREAD_MUTEX_NORMAL
#endif

#ifdef __cplusplus
extern "C" {
#endif

void __run_cleanup_block(struct cleanup_block *cb);

#ifdef __cplusplus
}
#endif

#endif 
