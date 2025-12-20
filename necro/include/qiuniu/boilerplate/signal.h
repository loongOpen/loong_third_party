
#ifndef _QIUNIU_BOILERPLATE_SIGNAL_H
#define _QIUNIU_BOILERPLATE_SIGNAL_H

#include <qiuniu/signal.h>


#define __SIGRSVD(n)	(SIGRTMIN + 8 + (n))

#define SIGAGENT	__SIGRSVD(0) 
#define SIGPERIOD	__SIGRSVD(1) 


#define __SIGPRIV(n)	__SIGRSVD(8 + (n))

#define SIGSAFE_LOCK_ENTRY(__safelock)					\
  	do {								\
		push_cleanup_lock(__safelock);				\
		write_lock(__safelock);

#define SIGSAFE_LOCK_EXIT(__safelock)					\
		write_unlock(__safelock);				\
		pop_cleanup_lock(&__safelock);				\
	} while (0)

#endif 
