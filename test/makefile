all:
	aarch64-linux-gnu-gcc -c main.c -o ../objects/main.o 
	aarch64-linux-gnu-gcc -c stdlib.c -o ../objects/stdlib.o 
	aarch64-linux-gnu-as -c stdlibArm.S -o ../objects/stdlibArm.o
	aarch64-linux-gnu-gcc ../objects/main.o ../objects/stdlibArm.o ../objects/stdlib.o -o ../runnable/main -static
run:
	./../runnable/main 8
