#ifndef _STDLIB_H
#define _STDLIB_H

//#include "../stdbool.h"
#include <stdbool.h>

typedef unsigned long int size_t1;
typedef signed long int off_t;

#define NULL1 0
#define MAX_HEAP 64*1024*4096

#define PROT_READ 1
#define PROT_WRITE 2
#define MAP_PRIVATE 2
#define MAP_ANONYMOUS 32

typedef struct memory_block{
    bool is_free;
    size_t1 size;
    void* mem_addr;
    struct memory_block *next;
}m_block;

static void init() __attribute__ ((constructor));

void *mmap(void *addr/*[.lenght]*/, size_t1 length, int prot, int flags, int fd, off_t offset);
int munmap(void *addr/*[.lenght]*/, size_t1 length);
void malloc1(size_t1 size , m_block** head);
void free_block(m_block** head);
void print_blocks(m_block* current);

#endif