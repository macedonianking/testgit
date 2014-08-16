#include <stdint.h>

#include "base.h"
#include "terminal.h"
#include "gdt.h"

void kernel_main()
{
	gdt_install();
	terminal_initialize();
	terminal_clearscreen();
	terminal_printf("Hello world");
}
