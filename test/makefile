all:
	aarch64-linux-gnu-gcc -c main1.c -o ../objects/main1.o 
	aarch64-linux-gnu-as -c threadsArm.S -o ../objects/threadsArm.o
	aarch64-linux-gnu-gcc ../objects/main1.o ../objects/threadsArm.o -o ../runnable/main -static
run:
	./../runnable/main 8
