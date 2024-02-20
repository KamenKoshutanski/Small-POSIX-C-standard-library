#include "stdlib1.h"
#include <stdio.h>

char* heap;
char* brkp = NULL;
char* endp = NULL;

void init(){
    heap = (char *)mmap(NULL1, MAX_HEAP, (PROT_READ | PROT_WRITE) , (MAP_PRIVATE | MAP_ANONYMOUS) , -1, 0);
    brkp = heap;
    endp = brkp + MAX_HEAP;
}

void *sbrk1(size_t1 size)
{
    if(size == 0)
    {
        return (void *)brkp;
    }
    void *free = (void *)brkp;

    brkp += size;
    if(brkp >= endp){
        return NULL1;
    }
    return free;
}

m_block* allocate_memory_block(size_t1 size){
    void* mem_addr = (void* )sbrk1(0); 
    m_block* block = (m_block*)sbrk1(0);
    void* allocate_memory = sbrk1(sizeof(m_block) + size);
    if(allocate_memory != (void *)-1){
        block->is_free = false;
        block->size = size;
        block->mem_addr = mem_addr;
        block->next = NULL1;
        return block;
    }
    else{
        return NULL1;
    }
}

void malloc1(size_t1 size , m_block** head){
    m_block* current = * head ; 
    void* mem_addr = (void *)sbrk1(0);
    if(current == NULL1){
        *head = allocate_memory_block(size); 
    }
    else{
        while(current->next != NULL1){
            current = current->next ; 
        }
        m_block* block = (m_block*) sbrk1(0); 
        void* allocate_memory = sbrk1(sizeof(m_block) + size);
        if(allocate_memory != (void *)-1){
            block->is_free = false; 
            block->mem_addr = mem_addr;
            block->size = size; 
            block->next = NULL1;
            current->next = block; 
        }
    }
}

void free_block(m_block** head){
    if(*head == NULL1){
    }
    else
    (*head)->is_free = true; 
}

void print_blocks(m_block* current){
    while( current != NULL1){
        printf("is Free %d\n", current->is_free);
        printf("Mem Address %p\n", current->mem_addr);
        printf("Size %ld\n", current->size);
        printf("\n");
        current = current->next; 
    }
}