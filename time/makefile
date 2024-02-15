all:
	aarch64-linux-gnu-gcc -c main.c -o ../objects/main.o
	aarch64-linux-gnu-as -c arm.S -o ../objects/arm.o
	aarch64-linux-gnu-gcc ../objects/main.o ../objects/arm.o -o ../runnable/main -static
run:
	./../runnable/main
