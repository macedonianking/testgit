#include <stdint.h>

#include "base.h"
#include "terminal.h"

void kernel_main()
{
	uint16_t* buffer;
	uint8_t color;
	uint8_t ch;
	uint16_t item;

	buffer = (uint16_t*) 0xB8000;

	color = 0x07;
	ch = 'a';
	item = color << 8 | ch;
	buffer[0] = item;
Lhang:
	goto Lhang;
}
