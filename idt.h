#ifndef KERNEL_IDT_H
#define KERNEL_IDT_H

struct idt_gate
{
	uint16_t	base_low;
	uint16_t	selector;
	uint8_t		reserved;
	uint8_t		access;
	uint16_t	base_high;
}__attribute__((packed));

struct idt_pointer
{
	uint16_t	limit;
	uint32_t	base;
}__attribute__((packed));

extern void idt_set_gate(int i, uint16_t selector, uint32_t base, uint8_t access);
extern void idt_load();

#endif
