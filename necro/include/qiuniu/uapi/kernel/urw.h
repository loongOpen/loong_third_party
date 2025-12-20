
#ifndef _QIUNIU_UAPI_KERNEL_URW_H
#define _QIUNIU_UAPI_KERNEL_URW_H

#include <linux/types.h>



typedef struct {
	__u32 sequence;
} urw_t;

typedef struct {
	__u32 token;
	__u32 dirty;
} urwstate_t;

#define URW_INITIALIZER     { 0 }
#define DEFINE_URW(__name)  urw_t __name = URW_INITIALIZER

#ifndef READ_ONCE
#define READ_ONCE ACCESS_ONCE
#endif

static inline void __try_read_start(const urw_t *urw, urwstate_t *tmp)
{
	__u32 token;
repeat:
	token = READ_ONCE(urw->sequence);
	smp_rmb();
	if (token & 1) {
		cpu_relax();
		goto repeat;
	}

	tmp->token = token;
	tmp->dirty = 1;
}

static inline void __try_read_end(const urw_t *urw, urwstate_t *tmp)
{
	smp_rmb();
	if (urw->sequence != tmp->token) {
		__try_read_start(urw, tmp);
		return;
	}

	tmp->dirty = 0;
}

static inline void __do_write_start(urw_t *urw, urwstate_t *tmp)
{
	urw->sequence++;
	tmp->dirty = 1;
	smp_wmb();
}

static inline void __do_write_end(urw_t *urw, urwstate_t *tmp)
{
	smp_wmb();
	tmp->dirty = 0;
	urw->sequence++;
}

static inline void unsynced_rw_init(urw_t *urw)
{
	urw->sequence = 0;
}

#define unsynced_read_block(__tmp, __urw)		\
	for (__try_read_start(__urw, __tmp);		\
	     (__tmp)->dirty; __try_read_end(__urw, __tmp))

#define unsynced_write_block(__tmp, __urw)		\
	for (__do_write_start(__urw, __tmp);		\
	     (__tmp)->dirty; __do_write_end(__urw, __tmp))

#endif 
