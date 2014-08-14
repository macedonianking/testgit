#include <stdint.h>
#include <stddef.h>

enum vga_color
{
	COLOR_BLACK,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_CYAN,
	COLOR_RED,
	COLOR_MEGENTA,
	COLOR_BROWN,
	COLOR_GREY,
	COLOR_DARK_GRAY,
	COLOR_LIGHT_GRAY,
	COLOR_LIGHT_GREEN,
	COLOR_LIGHT_CYAN,
	COLOR_LIGHT_RED,
	COLOR_LIGHT_MEGENTA,
	COLOR_LIGHT_BROWN,
	COLOR_WHITE,
};

#define VGA_W		80
#define VGA_H		25

uint8_t make_color(uint8_t fg, uint8_t bg);
uint16_t make_item(uint8_t ch, uint8_t color);

void terminal_initialize();
void terminal_clearscreen();

void terminal_write_cursor(uint16_t x, uint16_t y);
void terminal_putchar(char c);
void terminal_putstring(const char *str);
void terminal_settextcolor(uint8_t color);
