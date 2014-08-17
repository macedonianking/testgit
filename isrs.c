#include "base.h"
#include "asm.h"
#include "terminal.h"

#include "idt.h"

extern void  _isr0();
extern void  _isr1();
extern void  _isr2();
extern void  _isr3();
extern void  _isr4();
extern void  _isr5();
extern void  _isr6();
extern void  _isr7();
extern void  _isr8();
extern void  _isr9();
extern void  _isr10();
extern void  _isr11();
extern void  _isr12();
extern void  _isr13();
extern void  _isr14();
extern void  _isr15();
extern void  _isr16();
extern void  _isr17();
extern void  _isr18();
extern void  _isr19();
extern void  _isr20();
extern void  _isr21();
extern void  _isr22();
extern void  _isr23();
extern void  _isr24();
extern void  _isr25();
extern void  _isr26();
extern void  _isr27();
extern void  _isr28();
extern void  _isr29();
extern void  _isr30();
extern void  _isr31();
extern void  _isr32();
extern void  _isr33();

void isrs_install()
{
	idt_set_gate(0, KERNEL_CODE_SELECTOR, (uint32_t)&_isr0, 0x8E);
	idt_set_gate(1, KERNEL_CODE_SELECTOR, (uint32_t)&_isr1, 0x8E);
	idt_set_gate(2, KERNEL_CODE_SELECTOR, (uint32_t)&_isr2, 0x8E);
	idt_set_gate(3, KERNEL_CODE_SELECTOR, (uint32_t)&_isr3, 0x8E);
	idt_set_gate(4, KERNEL_CODE_SELECTOR, (uint32_t)&_isr4, 0x8E);
	idt_set_gate(5, KERNEL_CODE_SELECTOR, (uint32_t)&_isr5, 0x8E);
	idt_set_gate(6, KERNEL_CODE_SELECTOR, (uint32_t)&_isr6, 0x8E);
	idt_set_gate(7, KERNEL_CODE_SELECTOR, (uint32_t)&_isr7, 0x8E);
	idt_set_gate(8, KERNEL_CODE_SELECTOR, (uint32_t)&_isr8, 0x8E);
	idt_set_gate(9, KERNEL_CODE_SELECTOR, (uint32_t)&_isr9, 0x8E);
	idt_set_gate(10, KERNEL_CODE_SELECTOR, (uint32_t)&_isr10, 0x8E);
	idt_set_gate(11, KERNEL_CODE_SELECTOR, (uint32_t)&_isr11, 0x8E);
	idt_set_gate(12, KERNEL_CODE_SELECTOR, (uint32_t)&_isr12, 0x8E);
	idt_set_gate(13, KERNEL_CODE_SELECTOR, (uint32_t)&_isr13, 0x8E);
	idt_set_gate(14, KERNEL_CODE_SELECTOR, (uint32_t)&_isr14, 0x8E);
	idt_set_gate(15, KERNEL_CODE_SELECTOR, (uint32_t)&_isr15, 0x8E);
	idt_set_gate(16, KERNEL_CODE_SELECTOR, (uint32_t)&_isr16, 0x8E);
	idt_set_gate(17, KERNEL_CODE_SELECTOR, (uint32_t)&_isr17, 0x8E);
	idt_set_gate(18, KERNEL_CODE_SELECTOR, (uint32_t)&_isr18, 0x8E);
	idt_set_gate(19, KERNEL_CODE_SELECTOR, (uint32_t)&_isr19, 0x8E);
	idt_set_gate(20, KERNEL_CODE_SELECTOR, (uint32_t)&_isr20, 0x8E);
	idt_set_gate(21, KERNEL_CODE_SELECTOR, (uint32_t)&_isr21, 0x8E);
	idt_set_gate(22, KERNEL_CODE_SELECTOR, (uint32_t)&_isr22, 0x8E);
	idt_set_gate(23, KERNEL_CODE_SELECTOR, (uint32_t)&_isr23, 0x8E);
	idt_set_gate(24, KERNEL_CODE_SELECTOR, (uint32_t)&_isr24, 0x8E);
	idt_set_gate(25, KERNEL_CODE_SELECTOR, (uint32_t)&_isr25, 0x8E);
	idt_set_gate(26, KERNEL_CODE_SELECTOR, (uint32_t)&_isr26, 0x8E);
	idt_set_gate(27, KERNEL_CODE_SELECTOR, (uint32_t)&_isr27, 0x8E);
	idt_set_gate(28, KERNEL_CODE_SELECTOR, (uint32_t)&_isr28, 0x8E);
	idt_set_gate(29, KERNEL_CODE_SELECTOR, (uint32_t)&_isr29, 0x8E);
	idt_set_gate(30, KERNEL_CODE_SELECTOR, (uint32_t)&_isr30, 0x8E);
	idt_set_gate(31, KERNEL_CODE_SELECTOR, (uint32_t)&_isr31, 0x8E);
	idt_set_gate(32, KERNEL_CODE_SELECTOR, (uint32_t)&_isr33, 0x8E);
}

void idt_install()
{
	idt_load();
	isrs_install();
	sti();
}

const char *exception_messages[] = 
{
	"Division By Zero",
	"Debug Exception",
	"No maskable Exception", 
	"Breakpoint Exception",
	"Overflow Exception", 
	"Out of Bounds Exception",
	"Invalid Opcode Exception",
	"No Coprocessor Exception", 
	"Double Fault Exception",
	"Coprocessor Segment Overrun Exception",
	"Bad TSS Exception",
	"Segment Not Present",
	"Stack fault Exception",
	"General protection",
	"Page fault",
	"Unkonw",
	"Coproessor Fault Exception",
	"Align Check Exception",
	"Machine Check Exception",
	"Resverd"
	"Resverd"
	"Resverd"
	"Resverd"
	"Resverd"
	"Resverd"
	"Resverd"
	"Resverd"
	"Resverd"
	"Resverd"
	"Resverd"
	"Resverd"
	"Resverd"
};

void fault_handler(struct idt_info* ptr)
{
	if (ptr->code < 32)
	{
		die("fault_handler:%s, code=%d, error=%d\n",
				exception_messages[ptr->code],
				ptr->code, ptr->error);
	}

	switch (ptr->code)
	{
		default:
			{
				terminal_printf("defualt isr handler:code=%d, error=%d\n",
						ptr->code, ptr->error);
			}
	}
}


