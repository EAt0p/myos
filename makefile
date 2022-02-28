C_SOURCES =$(wildcard kernel/*.c drivers/*.c)
OBJ=${C_SOURCES:.c=.o}
all: boot.bin krnl.bin
	cd bin;\
	 cat $^ > fd.bin;\
	 qemu-system-i386 -fda fd.bin -vnc 127.0.0.1:1
krnl.bin: pkrnl.o ${OBJ}
	i386-elf-ld -Ttext 0x1000 -o bin/$@ $^ --oformat binary
	rm -rf $^
boot.bin: boot.asm
	nasm -f bin -o bin/$@ $<
pkrnl.o: pkrnl.asm
	nasm -f elf pkrnl.asm -o pkrnl.o
%.o: %.c
	i386-elf-gcc -ffreestanding -c $< -o $@
