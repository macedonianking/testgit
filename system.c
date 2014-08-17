#include "terminal.h"
#include "asm.h"
#include "vsnprintf.h"

#include "system.h"

void memcpy(void *dst, void *src, size_t count)
{
	uint8_t *d;
	uint8_t *s;

	d = (uint8_t*) dst;
	s = (uint8_t*) src;
	while (count-- != 0)
	{
		*d++ = *s++;
	}
}

void memset(void *p, int n, size_t count)
{
	uint8_t *ptr;

	ptr = (uint8_t*)p;	
	while (count-- != 0)
	{
		*ptr++ = n;
	}
}

void memsetw(void *p, int n, size_t count)
{
	uint16_t *ptr = (uint16_t*)p; 
	while (count-- != 0)
	{
		*ptr++ = n;
	}
}

uint8_t inportb(uint16_t port)
{
	uint8_t r;
	__asm__ __volatile__("inb %1, %0":"=a"(r):"d"(port));

	return r;
}

void outportb(uint16_t port, uint8_t n)
{
	__asm__ __volatile__("outb %0, %1"::"a"(n), "d"(port));
}

size_t strlen(const char *str)
{
	const char *ptr;
	for (ptr = str; *ptr != '\0'; ++ptr)
		;
	return ptr - str;
}

void die(const char *format, ...)
{
	char buf[MAX_BUFFER_SIZE];
	va_list args;

	va_start(args, format);
	vsnprintf(buf, MAX_BUFFER_SIZE, format, args);
	va_end(args);

	terminal_putstring(buf);
	for(;;)
	{
		hlt();
	}
}
