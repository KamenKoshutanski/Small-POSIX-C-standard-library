all:
	aarch64-linux-gnu-gcc -c main.c -o ../objects/main.o
	aarch64-linux-gnu-as -c unistd.S -o ../objects/unistd.o
	aarch64-linux-gnu-gcc ../objects/main.o ../objects/unistd.o -o ../runnable/main -nostdlib -nostdinc -ffreestanding -static
run:
	./../runnable/main
