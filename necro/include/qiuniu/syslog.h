
#pragma GCC system_header
#include_next <syslog.h>

#ifndef _QIUNIU_SYSLOG_H
#define _QIUNIU_SYSLOG_H

#include <stdarg.h>
#include <necro_config.h>
#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif 

QIUNIU_DECL(void, syslog(int priority, const char *fmt, ...));

QIUNIU_DECL(void, vsyslog(int priority,
			  const char *fmt, va_list ap));

#ifdef CONFIG_NECRO_FORTIFY

QIUNIU_DECL(void, __vsyslog_chk(int priority, int level,
				const char *fmt, va_list ap));

QIUNIU_DECL(void, __syslog_chk(int pri, int flag,
			       const char *fmt, ...));

#endif 

#ifdef __cplusplus
}
#endif 

#endif 
