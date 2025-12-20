
#pragma GCC system_header
#include_next <sys/socket.h>

#ifndef _QIUNIU_SYS_SOCKET_H
#define _QIUNIU_SYS_SOCKET_H

#include <qiuniu/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif

QIUNIU_DECL(int, socket(int protocol_family,
			int socket_type, int protocol));

QIUNIU_DECL(ssize_t, recvmsg(int fd,
			     struct msghdr *msg, int flags));

QIUNIU_DECL(int, recvmmsg(int fd,
			  struct mmsghdr *msgvec, unsigned int vlen,
			  unsigned int flags, struct timespec *timeout));

QIUNIU_DECL(ssize_t, sendmsg(int fd,
			     const struct msghdr *msg, int flags));

QIUNIU_DECL(int, sendmmsg(int fd,
			  struct mmsghdr *msgvec, unsigned int vlen,
			  unsigned int flags));

QIUNIU_DECL(ssize_t, recvfrom(int fd, void *buf, size_t len, int flags,
			      struct sockaddr *from, socklen_t *fromlen));

QIUNIU_DECL(ssize_t, sendto(int fd, const void *buf, size_t len, int flags,
			    const struct sockaddr *to, socklen_t tolen));

QIUNIU_DECL(ssize_t, recv(int fd, void *buf,
			  size_t len, int flags));

QIUNIU_DECL(ssize_t, send(int fd, const void *buf,
			  size_t len, int flags));

QIUNIU_DECL(int, getsockopt(int fd, int level, int optname,
			    void *optval, socklen_t *optlen));

QIUNIU_DECL(int, setsockopt(int fd, int level, int optname,
			    const void *optval, socklen_t optlen));

QIUNIU_DECL(int, bind(int fd, const struct sockaddr *my_addr,
		      socklen_t addrlen));

QIUNIU_DECL(int, connect(int fd, const struct sockaddr *serv_addr,
			 socklen_t addrlen));

QIUNIU_DECL(int, listen(int fd, int backlog));

QIUNIU_DECL(int, accept(int fd, struct sockaddr *addr,
			socklen_t *addrlen));

QIUNIU_DECL(int, getsockname(int fd, struct sockaddr *name,
			     socklen_t *namelen));

QIUNIU_DECL(int, getpeername(int fd, struct sockaddr *name,
			     socklen_t *namelen));

QIUNIU_DECL(int, shutdown(int fd, int how));

#ifdef __cplusplus
}
#endif

#endif 
