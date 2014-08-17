#ifndef KERNEL_VSNPRINTF_H
#define KERNEL_VSNPRINTF_H

#include <stdarg.h>

#include "base.h"


extern int vsnprintf(char *buf, size_t size, const char *fmt, va_list args);

extern int snprintf(char *buf, size_t size, const char *fmt, ...);

extern void vsscanf(const char *buf, const char *fmt, va_list args);

#endif
