#pragma once

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define STDIN 0
#define STDOUT 0
#define STDERR 0

typedef unsigned int size_t;
typedef int ssize_t;

ssize_t read(int fd, const void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);
void _exit(int status);