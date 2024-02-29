#include "threads.h"
#include "../stdio/stdio.h"

int fork()
{
    return clone_kernel(17, NULL, NULL, NULL, NULL);
}

int clone(int (*fn)(void *), void *stack, int flags, void *arg, pid_t *parent_tid, void *tls, pid_t *child_tid)
{
    int id = clone_kernel(flags, stack, parent_tid, child_tid, tls);
    if(id == 0)
    {
        int result = fn(arg);
        kill(getpid(), 1);
    }
    return id;
}

int task_on_different_thread(int (*fn)(void *)){
    return clone(fn, NULL, 17, NULL, NULL, NULL, NULL);
}