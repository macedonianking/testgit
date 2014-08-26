#include "system.h"
#include "vsnprintf.h"

#include "terminal.h"


#define VGA_PORT_CMMD			0x3D4
#define VGA_PORT_DATA			0x3D5
#define VGA_CMMD_CURSOR_HIGH	14
#define VGA_CMMD_CURSOR_LOW		15

static uint16_t g_cursor_x;
static uint16_t g_cursor_y;

uint16_t *terminal_buffer;
uint8_t	 terminal_color;

uint8_t make_color(uint8_t fg, uint8_t bg)
{
	return fg | bg << 4;
}

uint16_t make_item(uint8_t ch, uint8_t color)
{
	return color << 8 | ch;
}

void terminal_initialize()
{
	terminal_buffer = (uint16_t*) (0xB8000);
	terminal_settextcolor(make_color(COLOR_GREY, COLOR_BLACK));
}

void terminal_write_cursor(uint16_t x, uint16_t y)
{
	uint16_t n;

	g_cursor_x = x;
	g_cursor_y = y;

	n = g_cursor_y * VGA_W + x;
	outportb(VGA_PORT_CMMD, VGA_CMMD_CURSOR_HIGH);
	outportb(VGA_PORT_DATA, n >> 8);
	outportb(VGA_PORT_CMMD, VGA_CMMD_CURSOR_LOW);
	outportb(VGA_PORT_DATA, n);
}

void terminal_clearscreen()
{
	uint16_t blank;

	blank = make_item(' ', make_color(COLOR_GREY, COLOR_BLACK));
	memsetw(terminal_buffer, blank, VGA_W * VGA_H);
	terminal_write_cursor(0, 0);
}

void terminal_settextcolor(uint8_t color)
{
	terminal_color = color;
}

static void terminal_moveup()
{
	uint16_t blank;
	int m;

	blank = make_item(' ', terminal_color);
	m = (VGA_H - 1) * VGA_W;
	for (int i = 0; i < m; ++i)
	{
		terminal_buffer[i] = terminal_buffer[i + VGA_W];
	}
	for (int i = m; i < VGA_W * VGA_H; ++i)
	{
		terminal_buffer[i] = blank;
	}
}

static void terminal_movescreen()
{
	if (g_cursor_x < 0)
	{
		g_cursor_x = 0;
	} 
	else if (g_cursor_x >= VGA_W)
	{
		g_cursor_x = VGA_W - 1;
	}

	if (g_cursor_y < 0)
	{
		g_cursor_y = 0;
	}
	else if (g_cursor_y >= VGA_H)
	{
		while (g_cursor_y >= VGA_H)
		{
			terminal_moveup();
			--g_cursor_y;
		}
	}
}

void terminal_putchar(char c)
{
	uint16_t n;
	int index;

	switch(c)
	{
		case '\b':
			{
				if (g_cursor_x == 0 && g_cursor_y == 0)
				{
					return;
				}
				if (g_cursor_x-- == 0)
				{
					g_cursor_x = VGA_W - 1;
					--g_cursor_y;
				}
				break;
			}
		case '\t':
			{
				g_cursor_x = (g_cursor_x + 8) & ~7;
				if (g_cursor_x >= VGA_W)
				{
					g_cursor_x -= VGA_W;
					++g_cursor_y;
				}
				break;
			}
		case '\n':
			{
				g_cursor_x = 0;
				++g_cursor_y;
				break;
			}
		default:
			{
				n = make_item(c, terminal_color);
				index = VGA_W * g_cursor_y + g_cursor_x;
				terminal_buffer[index] = n;
				
				if (++g_cursor_x == VGA_W)
				{
					g_cursor_x = 0;
					++g_cursor_y;
				}	
				break;
			}
	}
	terminal_movescreen();
	terminal_write_cursor(g_cursor_x, g_cursor_y);
}

void terminal_putstring(const char *str)
{
	while (*str)
	{
		terminal_putchar(*str++);
	}
}

int terminal_printf(const char *format, ...)
{
	va_list args;
	char buf[MAX_BUFFER_SIZE];
	int n;

	va_start(args, format);
	n = vsnprintf(buf, MAX_BUFFER_SIZE, format, args);
	va_end(args);

	terminal_putstring(buf);
	return n;
}

void terminal_show_cursor()
{
	terminal_printf("x=%d, y=%d", g_cursor_x, g_cursor_y);
}

void terminal_test()
{
	for (int i =0; i < VGA_H; ++i)
	{
		terminal_printf("Hello world:%d\n", i);
	}
}
