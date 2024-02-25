all:
	aarch64-linux-gnu-gcc -c main.c -o objects/main.o -nostdlib -nostdinc -ffreestanding
	aarch64-linux-gnu-as -c start.S -o objects/start.o 
	aarch64-linux-gnu-as -c stdio/stdioArm.S -o objects/stdioArm.o 
	aarch64-linux-gnu-gcc -c stdio/stdio.c -o objects/stdio.o -nostdlib -nostdinc -ffreestanding 
	aarch64-linux-gnu-as -c stdlib/stdlibArm.S -o objects/stdlibArm.o 
	aarch64-linux-gnu-gcc -c stdlib/stdlib.c -o objects/stdlib.o -nostdlib -nostdinc -ffreestanding 
	aarch64-linux-gnu-gcc objects/main.o objects/threads.o objects/stdlibArm.o objects/stdlib.o objects/threadsArm.o objects/stdio.o objects/start.o objects/stdioArm.o -o runnable/main -nostdlib -static
run:
	./runnable/main
