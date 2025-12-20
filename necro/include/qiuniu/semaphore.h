
#pragma GCC system_header
#include_next <semaphore.h>

#ifndef _QIUNIU_SEMAPHORE_H
#define _QIUNIU_SEMAPHORE_H

#include <boilerplate/atomic.h>
#include <qiuniu/uapi/sem.h>
#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(int, sem_init(sem_t *sem,
			  int pshared,
			  unsigned int value));

QIUNIU_DECL(int, sem_destroy(sem_t *sem));

QIUNIU_DECL(int, sem_post(sem_t *sem));

QIUNIU_DECL(int, sem_wait(sem_t *sem));

QIUNIU_DECL(int, sem_timedwait(sem_t *sem,
			       const struct timespec *abs_timeout));

QIUNIU_DECL(int, sem_trywait(sem_t *sem));

QIUNIU_DECL(int, sem_getvalue(sem_t *sem, int *value));

QIUNIU_DECL(sem_t *, sem_open(const char *name, int oflags, ...));

QIUNIU_DECL(int, sem_close(sem_t *sem));

QIUNIU_DECL(int, sem_unlink(const char *name));

int sem_init_np(sem_t *sem,
		int flags,
		unsigned int value);

int sem_broadcast_np(sem_t *sem);

#ifdef __cplusplus
}
#endif

#endif 
