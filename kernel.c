#include <stdint.h>

#include "base.h"
#include "terminal.h"
#include "gdt.h"
#include "idt.h"

void kernel_main()
{
	char ch;
	char n;

	gdt_install();
	idt_install();
	
	terminal_initialize();
	terminal_clearscreen();

	ch = 'A';
	n = 0;
	terminal_putchar(ch / n);
	terminal_printf("Hello world");
}
