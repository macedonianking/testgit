#ifndef KERNLE_BASE_H
#define KERNLE_BASE_H

#ifdef _cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#ifndef _cplusplus
#include <stdbool.h>
#endif

#include <stdint.h>
#include <stddef.h>

#ifndef MAX_BUFFER_SIZE
#define MAX_BUFFER_SIZE 1024
#endif

#endif
