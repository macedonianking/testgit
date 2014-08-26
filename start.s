.file "start.s"
.equ	KERNEL_CODE_SEL, 0x10
.text
.globl _isr0
.globl _isr1
.globl _isr2
.globl _isr3
.globl _isr4
.globl _isr5
.globl _isr6
.globl _isr7
.globl _isr8
.globl _isr9
.globl _isr10
.globl _isr11
.globl _isr12
.globl _isr13
.globl _isr14
.globl _isr15
.globl _isr16
.globl _isr17
.globl _isr18
.globl _isr19
.globl _isr20
.globl _isr21
.globl _isr22
.globl _isr23
.globl _isr24
.globl _isr25
.globl _isr26
.globl _isr27
.globl _isr28
.globl _isr29
.globl _isr30
.globl _isr31
.globl _isr32
.globl _isr33
.globl fault_handler

.globl irq0
.globl irq1
.globl irq2
.globl irq3
.globl irq4
.globl irq5
.globl irq6
.globl irq7
.globl irq8
.globl irq9
.globl irq10
.globl irq11
.globl irq12
.globl irq13
.globl irq14
.globl irq15
.globl irq_handler

isr_common_stub:
	cli
	pusha
	push	%ds
	push	%es
	push	%fs
	push	%gs
	mov		$KERNEL_CODE_SEL, %ax
	mov		%ax, %ds
	mov		%ax, %es
	mov		%ax, %fs
	mov		%ax, %gs
	mov		%esp, %eax
	push	%eax
	mov		$fault_handler, %eax
	call	*%eax
	pop		%eax
	pop		%gs
	pop		%fs
	pop		%es
	pop		%ds
	popa
# pop error code and exception number.
	add		$8, %esp
	sti
	iret

_isr0:
	push	$0x00
	push	$0x00
	jmp		isr_common_stub

_isr1:
	push	$0x00
	push	$1
	jmp		isr_common_stub

_isr2:
	push	$0x00
	push	$2
	jmp		isr_common_stub

_isr3:
	push	$0x00
	push	$3
	jmp		isr_common_stub

_isr4:
	push	$0x00
	push	$4
	jmp		isr_common_stub

_isr5:
	push	$0x00
	push	$5
	jmp		isr_common_stub

_isr6:
	push	$0x00
	push	$6
	jmp		isr_common_stub

_isr7:
	push	$0x00
	push	$7
	jmp		isr_common_stub

_isr8: # double fault, has error code
	push	$8
	jmp		isr_common_stub

_isr9:
	push	$0x00
	push	$9
	jmp		isr_common_stub

_isr10: # bad bss, has error code
	push	$10
	jmp		isr_common_stub

_isr11: # has error code
	push	$11
	jmp		isr_common_stub

_isr12:
	push	$12
	jmp		isr_common_stub

_isr13:
	push	$13
	jmp		isr_common_stub

_isr14:
	push	$14
	jmp		isr_common_stub

_isr15:
	push	$0x00
	push	$15
	jmp		isr_common_stub

_isr16:
	push	$0x00
	push	$16
	jmp		isr_common_stub

_isr17:
	push	$0x00
	push	$17
	jmp		isr_common_stub

_isr18:
	push	$0x00
	push	$18
	jmp		isr_common_stub

_isr19:
	push	$0x00
	push	$19
	jmp		isr_common_stub

_isr20:
	push	$0x00
	push	$20
	jmp		isr_common_stub

_isr21:
	push	$0x00
	push	$21
	jmp		isr_common_stub

_isr22:
	push	$0x00
	push	$22
	jmp		isr_common_stub

_isr23:
	push	$0x00
	push	$23
	jmp		isr_common_stub

_isr24:
	push	$0x00
	push	$24
	jmp		isr_common_stub

_isr25:
	push	$0x00
	push	$25
	jmp		isr_common_stub

_isr26:
	push	$0x00
	push	$26
	jmp		isr_common_stub

_isr27:
	push	$0x00
	push	$27
	jmp		isr_common_stub

_isr28:
	push	$0x00
	push	$28
	jmp		isr_common_stub

_isr29:
	push	$0x00
	push	$29
	jmp		isr_common_stub

_isr30:
	push	$0x00
	push	$30
	jmp		isr_common_stub

_isr31:
	push	$0x00
	push	$31
	jmp		isr_common_stub

_isr32:
	push	$0x00
	push	$32
	jmp		isr_common_stub

_isr33:
	push	$0x00
	push	$33
	jmp		isr_common_stub

irq_common_stub:
	cli
	pusha
	push	%ds
	push	%es
	push	%fs
	push	%gs
	mov		$KERNEL_CODE_SEL, %ax
	mov		%ax, %ds
	mov		%ax, %es
	mov		%ax, %fs
	mov		%ax, %gs
	mov		%esp, %eax
	push	%eax
	mov		$irq_handler, %eax
	call	*%eax
	pop		%eax
	pop		%gs
	pop		%fs
	pop		%es
	pop		%ds
	popa
	add		$8, %esp
	iret

irq0:
	push	$0x00
	push	$32
	jmp		irq_common_stub

irq1:
	push	$0x00
	push	$33
	jmp		irq_common_stub

irq2:
	push	$0x00
	push	$34
	jmp		irq_common_stub

irq3:
	push	$0x00
	push	$35
	jmp		irq_common_stub

irq4:
	push	$0x00
	push	$36
	jmp		irq_common_stub

irq5:
	push	$0x00
	push	$37
	jmp		irq_common_stub

irq6:
	push	$0x00
	push	$38
	jmp		irq_common_stub

irq7:
	push	$0x00
	push	$39
	jmp		irq_common_stub

irq8:
	push	$0x00
	push	$40
	jmp		irq_common_stub

irq9:
	push	$0x00
	push	$41
	jmp		irq_common_stub

irq10:
	push	$0x00
	push	$42
	jmp		irq_common_stub

irq11:
	push	$0x00
	push	$43
	jmp		irq_common_stub

irq12:
	push	$0x00
	push	$44
	jmp		irq_common_stub

irq13:
	push	$0x00
	push	$45
	jmp		irq_common_stub

irq14:
	push	$0x00
	push	$46
	jmp		irq_common_stub

irq15:
	push	$0x00
	push	$47
	jmp		irq_common_stub

