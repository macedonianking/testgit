#ifndef KERNEL_SYSTEM_H
#define KERNEL_SYSTEM_H

#include "base.h"

void memcpy(void *dst, void *src, size_t count);

void memset(uint8_t *ptr, uint8_t n, size_t count);

void memsetw(uint16_t *ptr, uint16_t n, size_t count);

uint8_t inportb(uint16_t port);
void outportb(uint16_t port, uint8_t n);

size_t strlen(const char *str);

#endif
