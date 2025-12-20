
#ifndef _QIUNIU_UAPI_KERNEL_THREAD_H
#define _QIUNIU_UAPI_KERNEL_THREAD_H

#include <qiuniu/uapi/kernel/types.h>


#define XNSUSP    0x00000001 
#define XNPEND    0x00000002 
#define XNDELAY   0x00000004 
#define XNREADY   0x00000008 
#define XNDORMANT 0x00000010 
#define XNZOMBIE  0x00000020 
#define XNMAPPED  0x00000040 
#define XNRELAX   0x00000080 
#define XNHELD    0x00000200 
#define XNBOOST   0x00000400 
#define XNSSTEP   0x00000800 
#define XNLOCK    0x00001000 
#define XNRRB     0x00002000 
#define XNWARN    0x00004000 
#define XNFPU     0x00008000 
#define XNROOT    0x00010000 
#define XNWEAK    0x00020000 
#define XNUSER    0x00040000 
#define XNJOINED  0x00080000 
#define XNTRAPLB  0x00100000 
#define XNDEBUG   0x00200000 
#define XNDBGSTOP 0x00400000 





#define XNTIMEO   0x00000001 
#define XNRMID    0x00000002 
#define XNBREAK   0x00000004 
#define XNKICKED  0x00000008 
#define XNWAKEN   0x00000010 
#define XNROBBED  0x00000020 
#define XNCANCELD 0x00000040 
#define XNPIALERT 0x00000080 
#define XNSCHEDP  0x00000100 
#define XNCONTHI  0x00000200 


#define XNMOVED   0x00000001 
#define XNLBALERT 0x00000002 
#define XNDESCENT 0x00000004 
#define XNSYSRST  0x00000008 
#define XNHICCUP  0x00000010 


#define XNTHREAD_STATE_LABELS  "SWDRU..X.HbTlrt.....L.s"

struct xnthread_user_window {
	__u32 state;
	__u32 info;
	__u32 grant_value;
	__u32 pp_pending;
};

#endif 
