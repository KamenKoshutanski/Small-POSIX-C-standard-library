SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)


all: 
	aarch64-linux-gnu-gcc -c main.c -o main.o -lc
	aarch64-linux-gnu-as start.S -o start.o
	aarch64-linux-gnu-ld start.o main.o -T link.ld -o start

run:
	./start
