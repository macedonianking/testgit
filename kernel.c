#include <stdint.h>

#include "base.h"
#include "terminal.h"
#include "gdt.h"
#include "idt.h"

void kernel_main()
{
	gdt_install();
	idt_install();
	
	terminal_initialize();
	terminal_clearscreen();
	terminal_test();
}
