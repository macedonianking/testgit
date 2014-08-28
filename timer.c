#include "timer.h"

#include "idt.h"
#include "system.h"
#include "terminal.h"

static int g_ticks;

uint8_t make_timer_cmd(uint8_t channel, uint8_t rwFlags, uint8_t mode, 
		uint8_t isBcd)
{
	return channel | rwFlags | mode | isBcd;
}

void timer_phaze(int hz)
{
	int divisor = TIMER_MAX_HZ / hz;
	uint8_t cmd = make_timer_cmd(TIEMR_CHANNEL0, TIEMR_RW_LM,
		TIMER_MODE_SQURE, 0);	
	outportb(0x43, cmd);
	outportb(0x40, divisor & 0xFF);
	outportb(0x40, (divisor >> 8) & 0xFF);
}

static void timer_handler(struct idt_info *reg)
{
	if (!(++g_ticks % 18))
	{
		terminal_printf("timer_handler:tick=%d\n", g_ticks);
	}
}

void timer_install()
{
	g_ticks = 0;
	irq_set_handler(0, timer_handler);
}
