
#pragma GCC system_header
#include_next <sys/mman.h>

#ifndef _QIUNIU_SYS_MMAN_H
#define _QIUNIU_SYS_MMAN_H

#include <sys/types.h>
#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(void *, mmap(void *addr, size_t length, int prot, int flags,
			 int fd, off_t offset));

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
QIUNIU_DECL(void *, mmap64(void *addr, size_t length, int prot, int flags,
			   int fd, off64_t offset));
#endif

#ifdef __cplusplus
}
#endif

#endif 
