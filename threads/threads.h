#ifndef _THREADS_H
#define _THREADS_H

typedef signed int pid_t;

pid_t getpid1(void);
pid_t getppid1(void);

int clone1(int (*fn)(void *), void *stack, int flags, void *arg, pid_t *parent_tid, void *tls, pid_t *child_tid);
long clone2(unsigned long flags, void *stack, int *parent_tid, int *child_tid, void *tls);

int kill(pid_t pid, int sig);
pid_t wait(int *wstatus);

#endif