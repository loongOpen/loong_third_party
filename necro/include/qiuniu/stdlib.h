
#pragma GCC system_header
#include_next <stdlib.h>

#ifndef _QIUNIU_STDLIB_H
#define _QIUNIU_STDLIB_H


#include_next <stdlib.h>
#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif 

QIUNIU_DECL(void, free(void *ptr));

QIUNIU_DECL(void *, malloc(size_t size));

#ifdef __cplusplus
}
#endif 

#endif 
