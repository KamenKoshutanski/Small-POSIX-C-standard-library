all:
	aarch64-linux-gnu-gcc -c main.c -o objects/main.o -nostdlib -nostdinc -ffreestanding -static
	aarch64-linux-gnu-as -c start.S -o objects/start.o
	aarch64-linux-gnu-as -c stdio/stdioArm.S -o objects/stdioArm.o
	aarch64-linux-gnu-gcc -c stdio/stdio.c -o objects/stdio.o -nostdlib -nostdinc -ffreestanding -static
	aarch64-linux-gnu-as -c time/timeArm.S -o objects/timeArm.o
	aarch64-linux-gnu-gcc -c time/time.c -o objects/time.o -nostdlib -nostdinc -ffreestanding -static
	aarch64-linux-gnu-as -c unistd/unistdArm.S -o objects/unistdArm.o
	aarch64-linux-gnu-gcc -c unistd/unistd.c -o objects/unistd.o -nostdlib -nostdinc -ffreestanding -static
	aarch64-linux-gnu-gcc -c string/string.c -o objects/string.o -nostdlib -nostdinc -ffreestanding -static
	aarch64-linux-gnu-gcc -c ctype/ctype.c -o objects/ctype.o -nostdlib -nostdinc -ffreestanding -static
	aarch64-linux-gnu-gcc -c math/math.c -o objects/math.o -nostdlib -nostdinc -ffreestanding -static
	aarch64-linux-gnu-as -c stdlib/stdlibArm.S -o objects/stdlibArm.o
	aarch64-linux-gnu-gcc -c stdlib/stdlib.c -o objects/stdlib.o -nostdlib -nostdinc -ffreestanding -static
	aarch64-linux-gnu-as -c threads/threadsArm.S -o objects/threadsArm.o
	aarch64-linux-gnu-gcc -c stdarg/stdarg.c -o objects/stdarg.o -nostdlib -nostdinc -ffreestanding -static

build:
	aarch64-linux-gnu-gcc objects/main.o objects/start.o objects/stdarg.o objects/threadsArm.o objects/stdlib.o objects/stdlibArm.o objects/ctype.o objects/string objects/unistd.o objects/unistdArm.o objects/stdioArm.o objects/stdio.o objects/math.o objects/time.o objects/timeArm.o -o runnable/main -nostdlib -nostdinc -ffreestanding -static

run:
	./runnable/main
