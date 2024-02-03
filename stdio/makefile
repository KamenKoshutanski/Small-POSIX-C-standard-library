all:
	aarch64-linux-gnu-gcc -c main.c -o main.o
	aarch64-linux-gnu-as -c plus.S -o plus.o
	aarch64-linux-gnu-as -c minus.S -o minus.o
	aarch64-linux-gnu-gcc main.o plus.o minus.o -o start -static
run:
	./start
