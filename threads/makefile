all:
	aarch64-linux-gnu-gcc -c main.c -o main.o
	aarch64-linux-gnu-as arm.S -o arm.o
	aarch64-linux-gnu-gcc main.o arm.o -static