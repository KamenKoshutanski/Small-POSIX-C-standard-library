#include <stdio.h>
#include <sched.h>
//#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "stdlib1.h"
#include "threads.h"

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

   m_block* block = NULL; 
   malloc1(1024*1024 , &block); 
   void *pchild_stack = block->mem_addr;
   if ( pchild_stack == NULL ) {
      printf("ERROR: Unable to allocate memory.\n");
   }

   int pid = clone1(fn, pchild_stack + (1024 * 1024), 17, NULL); //SIGCHILD
   printf("he: %d\n", pid);
   if ( pid < 0 ) {
        printf("ERROR: Unable to create the child process.\n");
   }


   printf("INFO: Child process terminated.%d\n", getpid1());
}