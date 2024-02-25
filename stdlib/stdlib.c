#include "stdlib.h"
#include "../stdio/stdio.h"

char* heap;
char* brkp = NULL;
char* endp = NULL;
m_block *block = NULL;
bool constructor = false;

void init(){
    heap = (char *)mmap(NULL, MAX_HEAP, (PROT_READ | PROT_WRITE) , (MAP_PRIVATE | MAP_ANONYMOUS) , -1, 0);
    brkp = heap;
    endp = brkp + MAX_HEAP;
}

void *sbrk(size_t size)
{
    if(size == 0)
    {
        return (void *)brkp;
    }
    void *free = (void *)brkp;

    brkp += size;
    if(brkp >= endp){
        return NULL;
    }
    return free;
}

m_block* allocate_memory_block(size_t size){
    void* mem_addr = (void* )sbrk(0); 
    m_block* block = (m_block*)sbrk(0);
    void* allocate_memory = sbrk(sizeof(m_block) + size);
    if(allocate_memory != (void *)-1){
        block->is_free = true;
        block->size = size;
        block->mem_addr = mem_addr;
        block->next = NULL;
        return block;
    }
    else{
        return NULL;
    }
}

void malloc_block(size_t size , m_block** head)
{
    if(constructor == false)
    {
        init();
        constructor = true;
    }
    m_block* current = * head ; 
    void* mem_addr = (void *)sbrk(0);
    if(current == NULL){
        *head = allocate_memory_block(size); 
    }
    else{
        while(current->next != NULL){
            current = current->next ; 
        }
        m_block* block = (m_block*) sbrk(0); 
        void* allocate_memory = sbrk(sizeof(m_block) + size);
        if(allocate_memory != (void *)-1){
            block->is_free = true; 
            block->mem_addr = mem_addr;
            block->size = size; 
            block->next = NULL;
            current->next = block; 
        }
    }
}

void *malloc(size_t size){
    malloc_block(size, &block);
    while(true)
    {
        if(block->is_free == false)
        {
            block = block->next;
        }
        else{
            block->is_free = false;
            break;
        }
    }
    return block->mem_addr;
}

void free_block(m_block** head)
{
    if(*head == NULL){
    }
    else
    (*head)->is_free = true; 
}

void print_blocks(m_block* current)
{
    while( current != NULL){
        printf("is Free %d\n", current->is_free);
        printf("Mem Address %p\n", current->mem_addr);
        printf("Size %ld\n", current->size);
        printf("\n");
        current = current->next; 
    }
}

void print_current_block()
{
    print_blocks(block);
}