all:
	aarch64-linux-gnu-as -c threadsArm.S -o ../objects/threadsArm.o
	aarch64-linux-gnu-gcc -c main.c -o ../objects/main.o 
	aarch64-linux-gnu-as -c stdlibArm.S -o ../objects/stdlibArm.o
	aarch64-linux-gnu-gcc ../objects/main.o ../objects/threadsArm.o ../objects/stdlibArm.o -o ../runnable/main -static

run:
	./../runnable/main
