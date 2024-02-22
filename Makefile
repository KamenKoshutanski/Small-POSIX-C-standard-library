all:
	aarch64-linux-gnu-gcc -c main.c -o objects/main.o 
	aarch64-linux-gnu-gcc -c math/math.c -o objects/math.o 
	aarch64-linux-gnu-gcc -c stdarg/stdarg.c -o objects/stdarg.o 
	aarch64-linux-gnu-gcc objects/main.o objects/math.o objects/stdarg.o -o runnable/main -static
run:
	./runnable/main
