
#ifndef _NECRO_INIT_H
#define _NECRO_INIT_H

#include <boilerplate/setup.h>
#include <boilerplate/ancillaries.h>

#ifdef __cplusplus
extern "C" {
#endif

void necro_init(int *argcp, char *const **argvp);

void necro_init_dso(int *argcp, char *const **argvp);

int necro_main(int argc, char *const argv[]);

void necro_usage(void);

void application_usage(void);

void application_version(void);

extern const char *necro_version_string;

extern const int necro_auto_bootstrap;
  
#ifdef __cplusplus
}
#endif

#endif 
