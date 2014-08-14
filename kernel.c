#include <stdint.h>

#include "base.h"
#include "terminal.h"

void kernel_main()
{
	terminal_initialize();
	terminal_clearscreen();
}
