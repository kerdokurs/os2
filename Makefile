include ./template.mk

OBJDIRS = lib

FILES = $(foreach dir, $(OBJDIRS), $(dir)/*.o) \
	main.o \
	hal/io.o \
	hal/loader.o

all: os.iso

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R                    \
		-b boot/grub/stage2_eltorito    \
		-no-emul-boot                   \
		-boot-load-size 4               \
		-A os                           \
		-input-charset utf8             \
		-quiet                          \
		-boot-info-table                \
		-o os.iso                       \
		iso

kernel.elf: bin
	ld $(LDFLAGS) $(FILES) -o kernel.elf

bin: main.o
	@make -C hal
	@make -C lib

clean:
	rm -rf **/*.o kernel.elf os.iso
