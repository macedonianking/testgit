CC		:= gcc
CFLAGS := -ffreestanding -nostdlib 
QEMU 	:= qemu-system-i386
CFLAGS	:= -m32 -ffreestanding -nostdlib -Wall -std=gnu99

SRC_FILES := boot.s \
	asm.s \
	start.s \
	kernel.c \
	isrs.c \
	irq.c \
	terminal.c \
	system.c \
	vsprintf.c \
	ctypes.c \
	gdt.c \
	idt.c \
	timer.c 

OBJ_FILES := $(patsubst %.c,%.o,$(patsubst %.s,%.c,$(SRC_FILES)))
BIN_FILES := myos.bin

.PHONY: all
all: $(BIN_FILES)
	# $(SRC_FILES)
	# $(OBJ_FILES)
	$(QEMU) -kernel $(BIN_FILES)

$(BIN_FILES) : $(OBJ_FILES) linker.ld
	ld -m elf_i386 -T linker.ld $(OUTPUT_OPTION) $(OBJ_FILES)

%.o : %.s
	$(CC) $(CFLAGS) -c $(OUTPUT_OPTION) $<

%.o : %.c
	$(CC) $(CFLAGS) -c $(OUTPUT_OPTION) $<

.PHONY: clean
clean:
	rm -rf *.o myos.bin
