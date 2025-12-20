
#ifndef _QIUNIU_TRACE_H
#define _QIUNIU_TRACE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

int xntrace_max_begin(unsigned long v);

int xntrace_max_end(unsigned long v);

int xntrace_max_reset(void);

int xntrace_user_start(void);

int xntrace_user_stop(unsigned long v);

int xntrace_user_freeze(unsigned long v, int once);

int xntrace_special(unsigned char id, unsigned long v);

int xntrace_special_u64(unsigned char id, unsigned long long v);

void xntrace_latpeak_freeze(int delay);

int xnftrace_vprintf(const char *format, va_list args);
int xnftrace_printf(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif 
