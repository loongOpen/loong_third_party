#ifndef _RLDF_UAPI_RLDF_H
#define _RLDF_UAPI_RLDF_H


#define RLDF_API_VER			9


#define RLDF_API_MIN_COMPAT_VER		9

typedef uint64_t nanosecs_abs_t;


typedef int64_t nanosecs_rel_t;


#define RLDF_TIMEOUT_INFINITE		0


#define RLDF_TIMEOUT_NONE		(-1)

#define RLDF_CLASS_PARPORT		1
#define RLDF_CLASS_SERIAL		2
#define RLDF_CLASS_CAN			3
#define RLDF_CLASS_NETWORK		4
#define RLDF_CLASS_RTMAC		5
#define RLDF_CLASS_TESTING		6
#define RLDF_CLASS_RTIPC		7
#define RLDF_CLASS_QIUNIU		8
#define RLDF_CLASS_UDD			9
#define RLDF_CLASS_MEMORY		10
#define RLDF_CLASS_GPIO			11
#define RLDF_CLASS_SPI			12
#define RLDF_CLASS_PWM			13

#define RLDF_CLASS_MISC			223
#define RLDF_CLASS_EXPERIMENTAL		224
#define RLDF_CLASS_MAX			255


#define RLDF_SUBCLASS_GENERIC		(-1)

#define RTIOC_TYPE_COMMON		0


#define RLDF_MAX_DEVNAME_LEN		31

typedef struct rldf_device_info {
	
	int device_flags;

	
	int device_class;

	
	int device_sub_class;

	
	int profile_version;
} rldf_device_info_t;


#define RLDF_PURGE_RX_BUFFER		0x0001
#define RLDF_PURGE_TX_BUFFER		0x0002



#define RTIOC_DEVICE_INFO \
	_IOR(RTIOC_TYPE_COMMON, 0x00, struct rldf_device_info)

#define RTIOC_PURGE		_IOW(RTIOC_TYPE_COMMON, 0x10, int)

struct _rldf_getsockopt_args {
	int level;
	int optname;
	void *optval;
	socklen_t *optlen;
};

struct _rldf_setsockopt_args {
	int level;
	int optname;
	const void *optval;
	socklen_t optlen;
};

struct _rldf_getsockaddr_args {
	struct sockaddr *addr;
	socklen_t *addrlen;
};

struct _rldf_setsockaddr_args {
	const struct sockaddr *addr;
	socklen_t addrlen;
};

#define _RTIOC_GETSOCKOPT	_IOW(RTIOC_TYPE_COMMON, 0x20,		\
				     struct _rldf_getsockopt_args)
#define _RTIOC_SETSOCKOPT	_IOW(RTIOC_TYPE_COMMON, 0x21,		\
				     struct _rldf_setsockopt_args)
#define _RTIOC_BIND		_IOW(RTIOC_TYPE_COMMON, 0x22,		\
				     struct _rldf_setsockaddr_args)
#define _RTIOC_CONNECT		_IOW(RTIOC_TYPE_COMMON, 0x23,		\
				     struct _rldf_setsockaddr_args)
#define _RTIOC_LISTEN		_IOW(RTIOC_TYPE_COMMON, 0x24,		\
				     int)
#define _RTIOC_ACCEPT		_IOW(RTIOC_TYPE_COMMON, 0x25,		\
				     struct _rldf_getsockaddr_args)
#define _RTIOC_GETSOCKNAME	_IOW(RTIOC_TYPE_COMMON, 0x26,		\
				     struct _rldf_getsockaddr_args)
#define _RTIOC_GETPEERNAME	_IOW(RTIOC_TYPE_COMMON, 0x27,		\
				     struct _rldf_getsockaddr_args)
#define _RTIOC_SHUTDOWN		_IOW(RTIOC_TYPE_COMMON, 0x28,		\
				     int)


struct _rldf_mmap_request {
	__u64 offset;
	size_t length;
	int prot;
	int flags;
};

#endif 
