all:
	aarch64-linux-gnu-gcc -c main.c -o objects/main.o
	aarch64-linux-gnu-as -c start.s -o objects/start.o
	aarch64-linux-gnu-gcc main.o start.o -o runnable/main -nostdlib -nostdinc -ffreestanding -static
run:
	./runnable/main
