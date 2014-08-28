#include <stdint.h>

#include "base.h"
#include "terminal.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"

void kernel_main()
{
	gdt_install();
	idt_install();
	
	terminal_initialize();
	terminal_clearscreen();
	timer_install();
}
