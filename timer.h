#ifndef KERNEL_TIMER_H
#define KERNEL_TIMER_H

#include <stdint.h>

#define TIEMR_CHANNEL0	(0 << 5)
#define TIMER_CHANNEL1	(1 << 5)
#define TIMER_CHANNEL2	(2 << 5)

#define TIMER_RW_LSB	(1 << 3)
#define TIMER_RW_MSB	(2 << 3)
#define TIEMR_RW_LM		(TIMER_RW_LSB | TIMER_RW_MSB)

#define TIMER_MODE_SQURE	(3 << 1)

#define TIMER_FLAG_BCD		(1 << 0)

#define TIMER_MAX_HZ		1193180

extern uint8_t make_timer_cmd(uint8_t channel, uint8_t rwFlags,
		uint8_t mode, uint8_t isBcd);

extern void timer_phaze(int hz);

extern void timer_install();

#endif
