all:
	aarch64-linux-gnu-gcc -c main.c -o ../objects/main.o
	aarch64-linux-gnu-as -c timeArm.S -o ../objects/timeArm.o
	aarch64-linux-gnu-gcc ../objects/main.o ../objects/timeArm.o -o ../runnable/main -static
run:
	./../runnable/main
