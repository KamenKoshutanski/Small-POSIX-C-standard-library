#include <stdio.h>
//#include <sched.h>
//#include <stdlib.h>
//#include <sys/wait.h>
//#include <unistd.h>
#include "stdlib1.h"
#include "threads.h"

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

int fn(void *arg)
{
   printf("\nINFO: This code is running under child process. %d\n", getpid1());

   int i = 0;

   for ( i = 1 ; i <= 10 ; i++ )
      printf("%d * %d = %d\n", 6, i, (6*i));

   printf("\n");

   return 0;
}

void main(int argc, char *argv[])
{
   printf("Hello, World!\n");

   init();
   m_block* block = NULL ; 
   malloc1(1024*1024 , &block); 
   void *pchild_stack = block->mem_addr;
   if ( pchild_stack == NULL ) {
      printf("ERROR: Unable to allocate memory.\n");
   }

   int pid = clone(fn, pchild_stack, 17, argv[1]); //SIGCHILD
   if ( pid < 0 ) {
        printf("ERROR: Unable to create the child process.\n");
   }


   printf("INFO: Child process terminated.%d\n", getpid1());
}