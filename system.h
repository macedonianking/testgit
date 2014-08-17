#ifndef KERNEL_SYSTEM_H
#define KERNEL_SYSTEM_H

#include "base.h"

void memcpy(void *dst, void *src, size_t count);

void memset(void *ptr, int n, size_t count);

void memsetw(void *ptr, int n, size_t count);

uint8_t inportb(uint16_t port);
void outportb(uint16_t port, uint8_t n);

extern size_t strlen(const char *str);

extern void die(const char *format, ...);
#endif
