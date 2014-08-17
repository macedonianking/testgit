#ifndef KERNEL_IDT_H
#define KERNEL_IDT_H

#include "base.h"
#include "gdt.h"

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

struct idt_info
{
	uint32_t	gs, fs, es, ds;
	uint32_t	edi, esi, ebp, esp;
	uint32_t	ebx, edx, ecx, eax;
	uint32_t	code, error;
	uint32_t	eip, cs, eflags, reeip, ress;
}__attribute__((packed));

extern void idt_set_gate(int i, uint16_t selector, uint32_t addr, uint8_t access);
extern void idt_load();
extern void idt_install();
extern void isrs_install();
extern void fault_handler(struct idt_info* ptr);

#endif
