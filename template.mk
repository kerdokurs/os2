CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

GPP = g++
CPPFLAGS =

AS = nasm
ASFLAGS = -f elf

LD = ld
LDFLAGS = -T link.ld -melf_i386

ROOT = /mnt/c/dev/os2/
INCDIR = -I$(ROOT)/include/ -I$(ROOT)/lib/include/ -I$(ROOT)/hal/include/
# LIB=$(ROOT)/lib/*.o
# API=$(ROOT)/api/*.o
# SAPI=$(ROOT)/servers/api_*.o

%.o: %.c
	@$(CC) $(INCDIR) $(CFLAGS) -o $@ $<
	@echo "  Compiling [C]   $<"

%.o: %.cpp
	@$(CPP) $(INCDIR) $(CPPFLAGS) -o $@ $<
	@echo "  Compiling [CPP] $<"

%.o: %.s
	@$(AS) $(ASFLAGS) $(INCDIR) -o $@ $<
	@echo "  Compiling [ASM] $<"
