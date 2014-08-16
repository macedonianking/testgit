#include "asm.h"

#include "gdt.h"

static struct gdt_entry	gdt[3];
static struct gdt_pointer	gp;

void gdt_set_gate(int i, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
	struct gdt_entry *ptr;

	ptr = gdt + i;
	ptr->base_low = base & 0xFFFF;
	ptr->base_middle = (base >> 16) & 0x00FF;
	ptr->base_high	= (base >> 24) & 0x00FF;

	ptr->limit_low = limit & 0xFFFF;
	ptr->granularity = (limit >> 16) & 0x0F;

	ptr->access = access;
	ptr->granularity |= gran & 0xF0;
}

void gdt_install()
{
	gdt_set_gate(0, 0, 0, 0, 0);
	gdt_set_gate(1, 0, 0xFFFFF, 0x9A, 0xCF); // kernel code segment.
	gdt_set_gate(2, 0, 0xFFFFF, 0x92, 0xCF); // kernel data segment.

	gp.limit = 3 * sizeof(struct gdt_entry) - 1;
	gp.base = (uint32_t)gdt;
	__asm__ __volatile__("lgdt %0"::"m"(gp));

	gdt_flush();
}
