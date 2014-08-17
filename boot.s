.set ALIGN,			1 << 0
.set MEMINFO,		1 << 1
.set FLAGS,			ALIGN | MEMINFO
.set MAGIC,			0x1BADB002
.set CHECKSUM,		-(FLAGS + MAGIC)

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bootstrap_stack, "aw", @nobits
stack_bootom:
.skip	16 * 1024
stack_top:

.section .text
.globl	_start
.type	_start, @function
_start:
	cli
	mov		$stack_top, %esp
	call	kernel_main

	cli
.Lhang:
	hlt
	jmp		.Lhang
.size _start, . - _start
