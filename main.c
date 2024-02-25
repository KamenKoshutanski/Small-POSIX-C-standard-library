#include "stdlib/stdlib.h"
#include "stdio/stdio.h"
#include "threads/threads.h"

int fn(void *arg)
{
   printf("\n\n\n\n\n");
   return 0;
}

int main(int argc, char *argv[])
{
   pid_t p;
   p = task_on_different_thread(fn);

   if ( p == 0)
      printf("Hello from Child!\n");
 
    // parent process because return value non-zero.
   else
      printf("Hello from Parent!\n");

   return 0;
}