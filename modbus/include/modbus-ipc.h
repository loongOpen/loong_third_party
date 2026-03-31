#ifndef MODBUS_IPC_H
#define MODBUS_IPC_H

#include "modbus.h"

MODBUS_BEGIN_DECLS

#define MODBUS_IPC_MAX_ADU_LENGTH 256

MODBUS_API modbus_t *
modbus_new_ipc(const char *deviceR, const char *deviceS);

MODBUS_END_DECLS

#endif