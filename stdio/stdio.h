#ifndef _STDIO_H
#define _STDIO_H

#define EOF -1
#define NULL 0

void putc(char c);
void puts(const char* str);
void printf(const char* fmt, ...);
int getchar(void);
char *gets(char *str);

#endif