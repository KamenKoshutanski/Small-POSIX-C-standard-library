#ifndef _THREADS_H
#define _THREADS_H

typedef signed int pid_t;

pid_t getpid1(void);
pid_t getppid1(void);

int clone1(int (*fn)(void *arg), void *stack, int flags, void *arg, pid_t *ptid, void *newtls, pid_t *ctid);

#endif