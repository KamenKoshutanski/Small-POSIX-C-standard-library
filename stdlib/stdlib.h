#ifndef _STDLIB_H
#define _STDLIB_H

#include "../stdbool.h"

typedef unsigned long int size_t;
typedef signed long int off_t;

#define NULL 0
#define MAX_HEAP 64*1024*4096

#define PROT_READ 1
#define PROT_WRITE 2
#define MAP_PRIVATE 2
#define MAP_ANONYMOUS 32

typedef struct memory_block{
    bool is_free;
    size_t size;
    void* mem_addr;
    struct memory_block *next;
}m_block;

static void init() __attribute__ ((constructor));

void *mmap(void *addr/*[.lenght]*/, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void *addr/*[.lenght]*/, size_t length);
void *malloc(size_t size);
void free_block(m_block** head);
void print_blocks(m_block* current);

#endif