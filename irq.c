#include "idt.h"

#include "system.h"
#include "terminal.h"

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

static irq_handler_impl irq_routines[16] =
{
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
};

static void test_irq0(struct idt_info *ptr);

void irq_handler(struct idt_info* ptr)
{
	if (irq_routines[ptr->code - 32])
	{
		irq_routines[ptr->code-32](ptr);
	}

	if (ptr->code >= 40)
	{
		outportb(0xa0, 0x20);
	}
	outportb(0x20, 0x20);
}

static void irq_remap()
{
	outportb(0x20, 0x11);
	outportb(0xa0, 0x11);
	outportb(0x21, 0x20);
	outportb(0xa1, 0x28);
	outportb(0x21, 0x04);
	outportb(0xa1, 0x02);
	outportb(0x21, 0x01);
	outportb(0xa1, 0x01);
	outportb(0x21, 0x00);
	outportb(0xa1, 0x00);
}

void irq_install()
{
	irq_remap();

	idt_set_gate(32, KERNEL_CODE_SELECTOR, (uint32_t)&irq0, 0x8e);
	idt_set_gate(33, KERNEL_CODE_SELECTOR, (uint32_t)&irq1, 0x8e);
	idt_set_gate(34, KERNEL_CODE_SELECTOR, (uint32_t)&irq2, 0x8e);
	idt_set_gate(35, KERNEL_CODE_SELECTOR, (uint32_t)&irq3, 0x8e);
	idt_set_gate(36, KERNEL_CODE_SELECTOR, (uint32_t)&irq4, 0x8e);
	idt_set_gate(37, KERNEL_CODE_SELECTOR, (uint32_t)&irq5, 0x8e);
	idt_set_gate(38, KERNEL_CODE_SELECTOR, (uint32_t)&irq6, 0x8e);
	idt_set_gate(39, KERNEL_CODE_SELECTOR, (uint32_t)&irq7, 0x8e);
	idt_set_gate(40, KERNEL_CODE_SELECTOR, (uint32_t)&irq8, 0x8e);
	idt_set_gate(41, KERNEL_CODE_SELECTOR, (uint32_t)&irq9, 0x8e);
	idt_set_gate(42, KERNEL_CODE_SELECTOR, (uint32_t)&irq10, 0x8e);
	idt_set_gate(43, KERNEL_CODE_SELECTOR, (uint32_t)&irq11, 0x8e);
	idt_set_gate(44, KERNEL_CODE_SELECTOR, (uint32_t)&irq12, 0x8e);
	idt_set_gate(45, KERNEL_CODE_SELECTOR, (uint32_t)&irq13, 0x8e);
	idt_set_gate(46, KERNEL_CODE_SELECTOR, (uint32_t)&irq14, 0x8e);
	idt_set_gate(47, KERNEL_CODE_SELECTOR, (uint32_t)&irq15, 0x8e);

	irq_set_handler(1, &test_irq0);
}

void irq_set_handler(int i, void (*handler)(struct idt_info*))
{
	if (i >= 0 && i < 16)
	{
		irq_routines[i] = handler;
	}
}

void test_irq0(struct idt_info *ptr)
{
	terminal_printf("test_irq0");
}
