CC		:= gcc
CFLAGS := -ffreestanding -nostdlib 
QEMU 	:= qemu-system-i386
CFLAGS	:= -m32 -ffreestanding -nostdlib -Wall

SRC_FILES := boot.s \
	kernel.c \
	terminal.c \
	system.c \
	vsprintf.c \
	ctypes.c

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
