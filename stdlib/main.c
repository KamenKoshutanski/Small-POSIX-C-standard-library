#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct memory_block {
bool is_free ;
size_t size ;
void* mem_addr ;
struct memory_block *next ;
}memory_block;

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

void free_block(memory_block** head){
    if(*head == NULL)
    {

    }else{
        (*head)->is_free = true;
    }
}
    void print_blocks(memory_block* current)
    {
        while(current != NULL){
            printf("is Free %d\n", current->is_free);
            printf("is Free %p\n", current->mem_addr);
            printf("is Free %ld\n", current->size);
        }
    }

int main(){

    memory_block* block = NULL;
    malloc(10, &block);
    malloc(20, &block);
    malloc(30, &block);
    print_blocks(block);
    return 0;
}
