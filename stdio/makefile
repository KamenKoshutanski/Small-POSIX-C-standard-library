all:
	aarch64-linux-gnu-as -c arm.S -o ../objects/arm.o
	aarch64-linux-gnu-gcc -c main.c -o ../objects/main.o -nostdlib -nostdinc -ffreestanding
	aarch64-linux-gnu-gcc -c stdio.c -o ../objects/stdio.o -nostdlib -nostdinc -ffreestanding
	aarch64-linux-gnu-as -c ../unistd/unistd.S -o ../objects/unistd.o
	aarch64-linux-gnu-gcc ../objects/main.o ../objects/stdio.o ../objects/arm.o ../objects/unistd.o -o ../runnable/main -nostdlib -nostdinc -ffreestanding -static
run:
	./../runnable/main
