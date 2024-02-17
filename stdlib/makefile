all:
	aarch64-linux-gnu-gcc -c main.c -o ../objects/main.o -nostdlib -nostdinc -ffreestanding
	aarch64-linux-gnu-as -c ../stdio/arm.S -o ../objects/arm.o
	aarch64-linux-gnu-gcc -c ../stdio/stdio.c -o ../objects/stdio.o -nostdlib -nostdinc -ffreestanding
	aarch64-linux-gnu-as -c ../unistd/unistd.S -o ../objects/unistd.o
	aarch64-linux-gnu-gcc -c ../time/time.c -o ../objects/time.o -nostdlib -nostdinc -ffreestanding
	aarch64-linux-gnu-as -c ../time/timeArm.S -o ../objects/timeArm.o
	aarch64-linux-gnu-gcc -c ../string/string.c -o ../objects/string.o -nostdlib -nostdinc -ffreestanding
	aarch64-linux-gnu-gcc ../objects/main.o ../objects/arm.o ../objects/stdio.o ../objects/unistd.o ../objects/time.o ../objects/timeArm.o ../objects/string.o -o ../runnable/main -nostdlib -nostdinc -ffreestanding -static
run:
	./../runnable/main
