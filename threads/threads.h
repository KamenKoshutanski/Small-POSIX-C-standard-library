#pragma once

typedef signed int pid_t;

pid_t getpid1(void);
pid_t getppid1(void);

int clone1(int (*fn)(void *_Nullable), void *stack, int flags, void *arg, ...);
