#include "terminal.h"

uint16_t *terminal_buffer;

static uint8_t make_color()
{
	return 0;
}

void terminal_initialize()
{
	uint8_t		color;
	uint8_t		ch;
	uint16_t	entry; 

	terminal_buffer = (uint16_t*) (0xB8000);
	color = 0x07;
	ch = 'a';
	entry = color << 8 | ch;
	terminal_buffer[0] = entry;
}
