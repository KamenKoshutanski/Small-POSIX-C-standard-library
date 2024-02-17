#pragma once

typedef unsigned int size_t1;
typedef signed long int off_t;

//#define NULL 0
#define MAX_HEAP 64*1024*4096

#define PROT_READ 1
#define PROT_WRITE 2
#define MAP_PRIVATE 2
#define MAP_ANONYMOUS 32

char *heap;
char *brkp = NULL;
char *endp = NULL;

void *mmap1(void *addr/*[.lenght]*/, size_t1 length, int prot, int flags, int fd, off_t offset);
int munmap(void *addr/*[.lenght]*/, size_t1 length);
