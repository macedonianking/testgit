	# file "asm.s"
.text
.globl	gdt_flush
.type	gdt_flush, @function
.equ	CODE_SELECTOR, 1 << 3
.equ	DATA_SELECTOR, 2 << 3
gdt_flush:
	mov	$DATA_SELECTOR, %eax
	mov	%ax, %es
	mov	%ax, %ds
	mov	%ax, %fs
	mov %ax, %gs
	mov	%ax, %ss
	jmp $CODE_SELECTOR, $.FLUSH
.FLUSH:
	ret	

