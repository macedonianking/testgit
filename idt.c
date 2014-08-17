#include "base.h"
#include "system.h"

#include "idt.h"

static struct idt_gate idts[256];
static struct idt_pointer idtp;

void idt_set_gate(int i, uint16_t selector, uint32_t base, uint8_t access)
{
	struct idt_gate *ptr;

	ptr = idts + i;
	ptr->base_low = (uint16_t)(base & 0xFFFF);
	ptr->base_high = (uint16_t)((base >> 16) & 0xFFFF);

	ptr->reserved = 0x00;
	ptr->selector = selector;
	ptr->access = access;
}

void idt_load()
{
	memset(&idts, 0, sizeof(idts));

	idtp.limit = 256 * sizeof(struct idt_gate) - 1;
	idtp.base = (uint32_t) &idts;
	__asm__ __volatile__("lidt %0"::"m"(idts));
}


