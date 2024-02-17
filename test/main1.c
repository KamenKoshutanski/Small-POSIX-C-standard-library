#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

typedef signed int pid_t;

pid_t getpid1(void);
pid_t getppid1(void);

int clone1(int (*fn)(void *arg), void *stack, int flags, void *arg, ...);

int fn()
{
   printf("\nINFO: This code is running under child process. %d\n", getpid());

   int i = 0;

   for ( i = 1 ; i <= 10 ; i++ )
      printf("%d * %d = %d\n", 8, i, 8 * i);

   printf("\n");

   return 0;
}

void main(int argc, char *argv[])
{
   printf("Hello, World!\n");

   void *pchild_stack = malloc(1024 * 1024);
   if ( pchild_stack == NULL ) {
      printf("ERROR: Unable to allocate memory.\n");
      exit(EXIT_FAILURE);
   }

   int pid = clone(fn, pchild_stack + (1024 * 1024), SIGCHLD, NULL);
   printf("fn: %p\n", fn);
   printf("stack: %p\n", pchild_stack + (1024 * 1024));
   printf("sigchild: %d\n", SIGCHLD);
   //printf("argv: %s\n", argv[1]);
   //int pid = clone1(fn, pchild_stack + (1024 * 1024), 17, NULL);
   if ( pid < 0 ) {
        printf("ERROR: Unable to create the child process.\n");
        exit(EXIT_FAILURE);
   }

   wait(NULL);

   free(pchild_stack);

   printf("INFO: Child process terminated.%d\n", getpid());
}