#include "kdb.h"

#include "terminal.h"
#include "idt.h"
#include "system.h"

static char kbdus[128] =
{
	0, 27, '1', '2', '3', '4', '5', '6', '7', '8', /*9*/
	'9', '0', '-', '=', '\b', /*Backspace*/
	'\t', /*Tab*/
	'q', 'w', 'e', 'r', /*19*/
	't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', /*Enterkey*/
	0, /*29-Control*/
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', /*39*/
	'\'', '`', 0, /*Leftshift*/
	'\\', 'z', 'x', 'c', 'v', 'b', 'n', /*49*/
	'm', ',', '.', '/', 0, /*Rightshift*/
	'*', 
	0, /*Alt*/
	' ', /*Spacebar*/
	0, /*Capslock*/
	0, /*59-F1key...>*/
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, /*<...F10*/
	0, /*69-Numlock*/
	0, /*ScrollLock*/
	0, /*Homekey*/
	0, /*UpArrow*/
	0, /*PageUp*/
	'-', 
	0, /*LeftArrow*/
	0, 
	0, /*RightArrow*/
	'+', 
	0, /*79-Endkey*/
	0, /*DownArrow*/
	0, /*PageDown*/
	0, /*InsertKey*/
	0, /*DeleteKey*/
	0, 0, 0, 
	0, /*F11Key*/
	0, /*F12Key*/
	0, /*Allotherkeysareundefined*/
};

static void kdb_handler(struct idt_info *ptr);

void kdb_install()
{
	irq_set_handler(1, kdb_handler);
}

void kdb_handler(struct idt_info *ptr)
{
	uint8_t scancode;
	char ch;

	scancode = inportb(0x60);
	if (scancode & 0x80)
	{
	}
	else
	{
		ch = kbdus[scancode];
		if (ch)
		{
			terminal_putchar(ch);
		}
	}
}
