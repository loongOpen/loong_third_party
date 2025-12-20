#ifndef _BOILERPLATE_SETUP_H
#define _BOILERPLATE_SETUP_H

#include <boilerplate/list.h>
#include <boilerplate/wrappers.h>
#include <string.h>
#include <sched.h>

struct base_setup_data {
	cpu_set_t cpu_affinity;
	int no_mlock;
	int no_sanity;
	int verbosity_level;
	int trace_level;
	const char *arg0;
};

struct option;

struct setup_descriptor {
	const char *name;
	int (*tune)(void);
	int (*parse_option)(int optnum, const char *optarg);
	void (*help)(void);
	int (*init)(void);
	const struct option *options;
	struct {
		int id;
		int opt_start;
		int opt_end;
		struct pvholder next;
		int done;
	} __reserved;
};


#define __setup_ctor		__attribute__ ((constructor(200)))
#define __early_ctor		__attribute__ ((constructor(210)))
#define __bootstrap_ctor	__attribute__ ((constructor(220)))

#define __setup_call(__name, __id)			\
static __setup_ctor void __declare_ ## __name(void)	\
{							\
	__register_setup_call(&(__name), __id);		\
}

#define core_setup_call(__name)		__setup_call(__name, 0)
#define boilerplate_setup_call(__name)	__setup_call(__name, 1)
#define copperplate_setup_call(__name)	__setup_call(__name, 2)
#define interface_setup_call(__name)	__setup_call(__name, 3)
#define post_setup_call(__name)		__setup_call(__name, 4)
#define user_setup_call(__name)		__setup_call(__name, 5)

#ifdef __cplusplus
extern "C" {
#endif

void __register_setup_call(struct setup_descriptor *p, int id);

extern pid_t __node_id;

extern int __config_done;

extern struct base_setup_data __base_setup_data;

const char *get_program_name(void);

void __trace_me(const char *fmt, ...);

#define trace_me(__fmt, __args...)			\
	do {						\
		if (__base_setup_data.trace_level > 0)	\
			__trace_me(__fmt, ##__args);	\
	} while (0)

#ifdef __cplusplus
}
#endif

#endif 
