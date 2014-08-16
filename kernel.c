#include <stdint.h>

#include "base.h"
#include "terminal.h"
#include "gdt.h"
#include "idt.h"

void kernel_main()
{
	gdt_install();
	idt_load();
	
	terminal_initialize();
	terminal_clearscreen();
	terminal_printf("Hello world");
}
