//#include <unistd.h>
#include <stdio.h>
//#include <stdlib.h>
#include "stdlib1.h"

typedef int bool;

#define false 0
#define true 1

typedef struct memory_block{
    bool is_free;
    size_t size;
    void* mem_addr;
    struct memory_block *next;
}m_block;

void init(){
    heap = (char *)mmap1(NULL, MAX_HEAP, (PROT_READ | PROT_WRITE) , (MAP_PRIVATE | MAP_ANONYMOUS) , -1, 0);
    brkp = heap;
    endp = brkp + MAX_HEAP;
}

void *sbrk1(size_t size)
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
    void* mem_addr = (void* )sbrk1(0); 
    m_block* block = (m_block*)sbrk1(0);
    void* allocate_memory = sbrk1(sizeof(m_block) + size);
    if(allocate_memory != (void *)-1){
        block->is_free = false;
        block->size = size;
        block->mem_addr = mem_addr;
        block->next = NULL;
        return block;
    }
    else{
        return NULL;
    }
}

void malloc1(size_t size , m_block** head){
    m_block* current = * head ; 
    void* mem_addr = (void *)sbrk1(0);
    if(current == NULL){
        *head = allocate_memory_block(size); 
    }
    else{
        while(current->next != NULL){
            current = current->next ; 
        }
        m_block* block = (m_block*) sbrk1(0); 
        void* allocate_memory = sbrk1(sizeof(m_block) + size);
        if(allocate_memory != (void *)-1){
            block->is_free = false; 
            block->mem_addr = mem_addr;
            block->size = size; 
            block->next = NULL;
            current->next = block; 
        }
    }
}

void free_block(m_block** head){
    if(*head == NULL){
    }
    else
    (*head)->is_free = true; 
}

void print_blocks(m_block* current){
    while( current != NULL){
        printf("is Free %d\n", current->is_free);
        printf("Mem Address %p\n", current->mem_addr);
        printf("Size %ld\n", current->size);
        printf("\n");
        current = current->next; 
    }
}


int main()
{
    init();
    m_block* block = NULL ; 
    malloc1(1024*1024 , &block); 
    malloc1(1 , &block);
    malloc1(1 , &block);
    print_blocks(block);

    /*int* ptr;
    int n, i;
 
    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);
 
    // Dynamically allocate memory using malloc()
    init();
    m_block* block = NULL ; 
    malloc1(n * sizeof(int) , &block); 
    ptr = block->mem_addr;
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }*/
    return 0;
}
