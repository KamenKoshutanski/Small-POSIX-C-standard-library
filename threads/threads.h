#ifndef _THREADS_H
#define _THREADS_H

typedef signed int pid_t;
#define NULL 0

pid_t getpid(void);
pid_t getppid(void);

int clone(int (*fn)(void *), void *stack, int flags, void *arg, pid_t *parent_tid, void *tls, pid_t *child_tid);
long clone_kernel(unsigned long flags, void *stack, int *parent_tid, int *child_tid, void *tls);
int fork();
int task_on_different_thread(int (*fn)(void *));

int kill(pid_t pid, int sig);
pid_t wait(int *wstatus);

#endif