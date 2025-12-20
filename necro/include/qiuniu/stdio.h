
#pragma GCC system_header
#include_next <stdio.h>

#ifndef _QIUNIU_STDIO_H
#define _QIUNIU_STDIO_H

#include <stddef.h>
#include <stdarg.h>
#include <necro_config.h>
#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif 

QIUNIU_DECL(int, vfprintf(FILE *stream, const char *fmt, va_list args));

#ifdef CONFIG_NECRO_FORTIFY

QIUNIU_DECL(int, __vfprintf_chk(FILE *stream, int level,
				const char *fmt, va_list ap));

QIUNIU_DECL(int, __vprintf_chk(int flag,
			       const char *fmt, va_list ap));

QIUNIU_DECL(int, __printf_chk(int flag, const char *fmt, ...));

QIUNIU_DECL(int, __fprintf_chk(FILE *fp, int flag, const char *fmt, ...));

int __rt_vfprintf_chk(FILE *stream, int level,
		      const char *fmt, va_list args);

void __rt_vsyslog_chk(int priority, int level,
		      const char *fmt, va_list args);

#endif	

QIUNIU_DECL(int, vprintf(const char *fmt, va_list args));

QIUNIU_DECL(int, fprintf(FILE *stream, const char *fmt, ...));

QIUNIU_DECL(int, printf(const char *fmt, ...));

QIUNIU_DECL(int, puts(const char *s));

QIUNIU_DECL(int, fputs(const char *s, FILE *stream));

#ifndef putchar
QIUNIU_DECL(int, putchar(int c));
#else
static inline int __real_putchar(int c)
{
	return putchar(c);
}
int __wrap_putchar(int c);
int __qiuniu_putchar(int c);
#undef putchar
#define putchar putchar
#endif

#ifndef fputc
QIUNIU_DECL(int, fputc(int c, FILE *stream));
#else
static inline int __real_fputc(int c, FILE *stream)
{
	return fputc(c, stream);
}
int __wrap_fputc(int c, FILE *stream);
int __qiuniu_fputc(int c, FILE *stream);
#undef fputc
#define fputc fputc
#endif

QIUNIU_DECL(size_t,
	    fwrite(const void *ptr, size_t sz, size_t nmemb, FILE *stream));

QIUNIU_DECL(int, fclose(FILE *stream));

int rt_vfprintf(FILE *stream, const char *format, va_list args);

int rt_vprintf(const char *format, va_list args);

int rt_fprintf(FILE *stream, const char *format, ...);

int rt_printf(const char *format, ...);

int rt_puts(const char *s);

int rt_fputs(const char *s, FILE *stream);

int rt_fputc(int c, FILE *stream);

int rt_putchar(int c);

size_t rt_fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

void rt_syslog(int priority, const char *format, ...);

void rt_vsyslog(int priority, const char *format, va_list args);

int rt_print_init(size_t buffer_size, const char *name);

const char *rt_print_buffer_name(void);

void rt_print_flush_buffers(void);

#ifdef __cplusplus
}
#endif 

#endif 
