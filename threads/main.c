#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include "threads.h"

int fn(void *arg)
{
   printf("\nINFO: This code is running under child process. %d\n", getpid1());
}

void main(int argc, char *argv[])
{
   printf("Hello, World!\n");

   void *pchild_stack = malloc(1024 * 1024);

   int pid = clone(fn, pchild_stack + (1024 * 1024), 1, argv[1]);

   free(pchild_stack);

   printf("INFO: Child process terminated. %d\n", getpid1());
}
