#ifndef _BOILERPLATE_NAMEGEN_H
#define _BOILERPLATE_NAMEGEN_H

#include <boilerplate/atomic.h>

struct name_generator {
	const char *radix;
	int length;
	atomic_t serial;
};

#define DEFINE_NAME_GENERATOR(__name, __radix, __type, __member)	\
	struct name_generator __name = {				\
		.radix = __radix,					\
		.length = sizeof ((__type *)0)->__member,		\
		.serial = ATOMIC_INIT(0),				\
	}

#ifdef __cplusplus
extern "C" {
#endif

char *generate_name(char *buf, const char *radix,
		    struct name_generator *ngen);

#ifdef __cplusplus
}
#endif

#endif 
