#include "stdlib.h"
#include "../stdbool.h"

char *heap ;
char *brkp = NULL;
char *endp = NULL;

static void init() __attribute__ ((constructor)) ;

typedef struct memory_block {
bool is_free ;
size_t size ;
void* mem_addr ;
struct memory_block *next ;
}memory_block;

void init()
{
    heap = (char *)mmap(NULL, MAX_HEAP, (PROT_READ | PROT_WRITE), (MAP_PRIVATE | MAP_ANONYMOUS), -1, 0);

    brkp = heap;
    endp = brkp + MAX_HEAP;
}

memory_block* allocate_memory_block(size_t size){
    
    void* mem_addr =sbrk(0); 
    memory_block* block ;
    void* allocate_memory = sbrk(sizeof(memory_block) + size); 
    if(allocate_memory != (void *)-1){
        block->is_free = false;
        block->size = size; 
        block->mem_addr = mem_addr; 
        block->next = NULL; 
        return block; 
    }
    else
    {
        return NULL; 
    }
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

void malloc(size_t size , memory_block** head){
    memory_block* current = * head; 
    void* mem_addr = (void *)sbrk(0);
    if(current == NULL){
        *head = allocate_memory_block(size); 
    }
    else{
        while(current->next != NULL){
            current = current->next; 
        }
        memory_block* block ;
        void* allocate_memory = sbrk(sizeof(memory_block) + size);
        if(allocate_memory != (void *)-1){
                block->is_free = false; 
                block->mem_addr = mem_addr;
                block->size = size; 
                block->next = NULL;
        current->next = block; 
        }
    }
}