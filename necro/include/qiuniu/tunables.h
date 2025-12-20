
#ifndef _QIUNIU_TUNABLES_H
#define _QIUNIU_TUNABLES_H

#include <boilerplate/tunables.h>
#include <sys/qiuniu.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int __qiuniu_main_prio;

extern int __qiuniu_print_bufsz;

extern int __qiuniu_print_bufcount;

extern int __qiuniu_print_syncdelay;

static inline define_config_tunable(main_prio, int, prio)
{
	__qiuniu_main_prio = prio;
}

static inline read_config_tunable(main_prio, int)
{
	return __qiuniu_main_prio;
}

static inline define_config_tunable(print_buffer_size, int, size)
{
	__qiuniu_print_bufsz = size;
}

static inline read_config_tunable(print_buffer_size, int)
{
	return __qiuniu_print_bufsz;
}

static inline define_config_tunable(print_buffer_count, int, count)
{
	__qiuniu_print_bufcount = count;
}

static inline read_config_tunable(print_buffer_count, int)
{
	return __qiuniu_print_bufcount;
}

static inline define_config_tunable(print_sync_delay, int, delay_ms)
{
	__qiuniu_print_syncdelay = delay_ms;
}

static inline read_config_tunable(print_sync_delay, int)
{
	return __qiuniu_print_syncdelay;
}

#ifdef __cplusplus
}
#endif

#endif 
