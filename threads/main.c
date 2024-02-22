#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>
#include "stdlib.h"
#include "threads.h"

int fn(void *arg)
{
   printf("\nINFO: This code is running under child process. %d\n", getpid1());

   int i = 0;

   for ( i = 1 ; i <= 10 ; i++ )
      printf("%d * %d = %d\n", 7, i, (7*i));

   printf("\n");

   return 0;
}

int main(int argc, char *argv[])
{
   printf("Hello, World!\n");
   void *pchild_stack = malloc(1080 * 1080);
   if ( pchild_stack == NULL ) {
      printf("ERROR: Unable to allocate memory.\n");
   }
   int *parent_tid = (int *)43565;
   int *child_tid = (int *)43566;
   int pid = clone2(17, pchild_stack, parent_tid, child_tid, NULL); //SIGCHILD
   printf("he: %d\n", pid);
   if ( pid < 0 ) {
        printf("ERROR: Unable to create the child process.\n");
   }
   if(getpid1() - 2 == pid)
   {
      kill(getpid1(), 2);
   }
   
   //kill(getpid1(), 2);
   printf("INFO: Child process terminated.%d\n", getpid1());
   return 0;
}