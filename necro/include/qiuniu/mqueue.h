
#pragma GCC system_header
#include_next <mqueue.h>

#ifndef _QIUNIU_MQUEUE_H
#define _QIUNIU_MQUEUE_H

#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(mqd_t, mq_open(const char *name,
			   int oflags,
			   ...));

QIUNIU_DECL(int, mq_close(mqd_t qd));

QIUNIU_DECL(int, mq_unlink(const char *name));

QIUNIU_DECL(int, mq_getattr(mqd_t qd,
			    struct mq_attr *attr));

QIUNIU_DECL(int, mq_setattr(mqd_t qd,
			    const struct mq_attr *__restrict__ attr,
			    struct mq_attr *__restrict__ oattr));

QIUNIU_DECL(int, mq_send(mqd_t qd,
			 const char *buffer,
			 size_t len,
			 unsigned prio));

QIUNIU_DECL(int, mq_timedsend(mqd_t q,
			      const char * buffer,
			      size_t len,
			      unsigned prio,
			      const struct timespec *timeout));

QIUNIU_DECL(ssize_t, mq_receive(mqd_t q,
				char *buffer,
				size_t len,
				unsigned *prio));

QIUNIU_DECL(ssize_t, mq_timedreceive(mqd_t q,
				     char *__restrict__ buffer,
				     size_t len,
				     unsigned *__restrict__ prio,
				     const struct timespec *__restrict__ timeout));

QIUNIU_DECL(int, mq_notify(mqd_t q,
			   const struct sigevent *evp));

#ifdef __cplusplus
}
#endif

#endif 
