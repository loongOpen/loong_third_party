
#ifndef _RLDF_UAPI_IPC_H
#define _RLDF_UAPI_IPC_H


#ifdef DOXYGEN_CPP
int socket__AF_RTIPC(int domain =AF_RTIPC, int type =SOCK_DGRAM, int protocol);
#endif


#ifdef DOXYGEN_CPP
int close__AF_RTIPC(int sockfd);
#endif


#ifdef DOXYGEN_CPP
int bind__AF_RTIPC(int sockfd, const struct sockaddr_ipc *addr,
		   socklen_t addrlen);
#endif


#ifdef DOXYGEN_CPP
int connect__AF_RTIPC(int sockfd, const struct sockaddr_ipc *addr,
		      socklen_t addrlen);
#endif


#ifdef DOXYGEN_CPP
int setsockopt__AF_RTIPC(int sockfd, int level, int optname,
			 const void *optval, socklen_t optlen);
#endif

#ifdef DOXYGEN_CPP
int getsockopt__AF_RTIPC(int sockfd, int level, int optname,
			 void *optval, socklen_t *optlen);
#endif


#ifdef DOXYGEN_CPP
ssize_t sendmsg__AF_RTIPC(int sockfd, const struct msghdr *msg, int flags);
#endif


#ifdef DOXYGEN_CPP
ssize_t recvmsg__AF_RTIPC(int sockfd, struct msghdr *msg, int flags);
#endif


#ifdef DOXYGEN_CPP
int getsockname__AF_RTIPC(int sockfd, struct sockaddr_ipc *addr, socklen_t *addrlen);
#endif


#ifdef DOXYGEN_CPP
int getpeername__AF_RTIPC(int sockfd, struct sockaddr_ipc *addr, socklen_t *addrlen);
#endif


#include <qiuniu/uapi/kernel/types.h>
#include <qiuniu/uapi/kernel/pipe.h>
#include <rldf/rldf.h>


#define AF_RTIPC		111


#define PF_RTIPC		AF_RTIPC


enum {

	IPCPROTO_IPC  = 0,

	IPCPROTO_EXIPC = 1,

	IPCPROTO_INIPC = 2,

	IPCPROTO_BUFP = 3,
	IPCPROTO_MAX
};


typedef int16_t rtipc_port_t;


struct rtipc_port_label {

	char label[XNOBJECT_NAME_LEN];
};


struct sockaddr_ipc {
	
	sa_family_t sipc_family;

	rtipc_port_t sipc_port;
};

#define SOL_EXIPC		311

#define EXIPC_LABEL		1

#define EXIPC_POOLSZ		2

#define EXIPC_BUFSZ		3

#define EXIPC_MONITOR		4

#define EXIPC_EVTIN		1

#define EXIPC_EVTOUT		2

#define EXIPC_EVTDOWN		3

#define EXIPC_EVTNOBUF		4


#define SOL_INIPC		312

#define INIPC_LABEL		1

#define INIPC_POOLSZ		2


#define SOL_BUFP		313

#define BUFP_LABEL		1

#define BUFP_BUFSZ		2

#ifdef DOXYGEN_CPP
#define SO_SNDTIMEO defined_by_kernel_header_file
#endif

#ifdef DOXYGEN_CPP
#define SO_RCVTIMEO defined_by_kernel_header_file
#endif


#endif 
