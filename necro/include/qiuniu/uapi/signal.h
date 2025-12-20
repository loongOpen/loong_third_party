
#ifndef _QIUNIU_UAPI_SIGNAL_H
#define _QIUNIU_UAPI_SIGNAL_H


#define SIGSUSP (SIGRTMAX + 1)
#define SIGRESM (SIGRTMAX + 2)
#define SIGRELS (SIGRTMAX + 3)
#define SIGKICK (SIGRTMAX + 4)
#define SIGDEMT (SIGRTMAX + 5)


#define SIGSHADOW			SIGWINCH
#define sigshadow_action(code)		((code) & 0xff)
#define sigshadow_arg(code)		(((code) >> 8) & 0xff)
#define sigshadow_int(action, arg)	((action) | ((arg) << 8))


#define SIGSHADOW_ACTION_HARDEN		1
#define SIGSHADOW_ACTION_BACKTRACE	2
#define SIGSHADOW_ACTION_HOME		3
#define SIGSHADOW_BACKTRACE_DEPTH	16

#define SIGDEBUG			SIGXCPU
#define sigdebug_code(si)		((si)->si_value.sival_int)
#define sigdebug_reason(si)		(sigdebug_code(si) & 0xff)
#define sigdebug_marker			0xfccf0000
#define sigdebug_marked(si)		\
	((sigdebug_code(si) & 0xffff0000) == sigdebug_marker)


#define SIGDEBUG_UNDEFINED		0
#define SIGDEBUG_MIGRATE_SIGNAL		1
#define SIGDEBUG_MIGRATE_SYSCALL	2
#define SIGDEBUG_MIGRATE_FAULT		3
#define SIGDEBUG_MIGRATE_PRIOINV	4
#define SIGDEBUG_NOMLOCK		5
#define SIGDEBUG_WATCHDOG		6
#define SIGDEBUG_RESCNT_IMBALANCE	7
#define SIGDEBUG_LOCK_BREAK		8
#define SIGDEBUG_MUTEX_SLEEP		9

#define QIUNIU_DELAYMAX			2147483647U


#ifdef __OPTIMIZE__
extern void *__siginfo_overflow(void);
static inline
const void *__check_si_overflow(size_t fldsz, size_t extrasz, const void *p)
{
	siginfo_t *si __attribute__((unused));

	if (fldsz + extrasz <= sizeof(si->_sifields))
		return p;

	return __siginfo_overflow();
}
#define __qiuniu_si_extra(__si, __basefield, __type)				\
	((__type *)__check_si_overflow(sizeof(__si->_sifields.__basefield),	\
	       sizeof(__type), &(__si->_sifields.__basefield) + 1))
#else
#define __qiuniu_si_extra(__si, __basefield, __type)				\
	((__type *)((&__si->_sifields.__basefield) + 1))
#endif



#ifdef __OPTIMIZE__
extern void *__sigevent_overflow(void);
static inline
const void *__check_sev_overflow(size_t fldsz, size_t extrasz, const void *p)
{
	sigevent_t *sev __attribute__((unused));

	if (fldsz + extrasz <= sizeof(sev->_sigev_un))
		return p;

	return __sigevent_overflow();
}
#define __qiuniu_sev_extra(__sev, __basefield, __type)				\
	((__type *)__check_sev_overflow(sizeof(__sev->_sigev_un.__basefield),	\
	       sizeof(__type), &(__sev->_sigev_un.__basefield) + 1))
#else
#define __qiuniu_sev_extra(__sev, __basefield, __type)				\
	((__type *)((&__sev->_sigev_un.__basefield) + 1))
#endif

#endif 
