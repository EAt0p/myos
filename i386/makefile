C_SOURCES=$(wildcard kernel/*.c drivers/*.c)
OBJ=${C_SOURCES:.c=.o}
all: boot.bin krnl.bin
	rm kernel/main.o krnlentry.o
	cd bin;\
	 cat $^ > fd.bin;\
	 qemu-system-i386 -fda fd.bin
boot.bin: boot.asm
	nasm -f bin boot.asm -o bin/boot.bin
krnl.bin: krnlentry.o ${OBJ}
	i386-elf-ld -Ttext 0x1000 -o bin/$@ $^ --oformat binary
krnlentry.o: krnlentry.asm
	nasm -f elf $< -o $@
%.o: %.c
	i386-elf-gcc -ffreestanding -c $< -o $@
