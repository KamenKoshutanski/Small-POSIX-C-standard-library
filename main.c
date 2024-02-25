//#include <stdio.h>
#include "stdio/stdio.h"
//#include <stdbool.h>

/*#define PRINTF_STATE_DEFAULT        0
#define PRINTF_STATE_LENGTH         1
#define PRINTF_STATE_LENGTH_SHORT   2
#define PRINTF_STATE_LENGTH_LONG    3
#define PRINTF_STATE_SPEC           4

#define PRINTF_LENGTH_DEFAULT       0
#define PRINTF_LENGTH_SHORT_SHORT   1
#define PRINTF_LENGTH_SHORT         2
#define PRINTF_LENGTH_LONG          3
#define PRINTF_LENGTH_LONG_LONG     4

int putToStdOut(const void *c);

void putc1(char c)
{
    putToStdOut(&c);
}

void puts1(const char* str)
{
    while(*str)
    {
        putc1(*str);
        str++;
    }
}

/*void printf1(const char* fmt, ...)
{
    int* arg = (int*)&fmt;
    arg+=40;
    char* n = (char *)*arg;
    puts1(n);
}*/

/*void printf1(const char* fmt, ...)
{
    int* arg = (int*)&fmt;
    int state = PRINTF_STATE_DEFAULT;
    int length = PRINTF_LENGTH_DEFAULT;
    int numSystem = 10;
    bool sign = false;
    arg+=48;
    while (*fmt)
    {
        switch (state)
        {
            case PRINTF_STATE_DEFAULT:
                switch (*fmt)
                {
                    case '%':   
                        state = PRINTF_STATE_LENGTH;
                        break;
                    default:  
                        putc1(*fmt);
                        break;
                }
                break;

            case PRINTF_STATE_LENGTH:
                switch (*fmt)
                {
                    case 'h':   
                        length = PRINTF_LENGTH_SHORT;
                        state = PRINTF_STATE_LENGTH_SHORT;
                        break;
                    case 'l':   
                        length = PRINTF_LENGTH_LONG;
                        state = PRINTF_STATE_LENGTH_LONG;
                        break;
                    default:    
                        goto PRINTF_STATE_SPEC_;
                }
                break;

            case PRINTF_STATE_LENGTH_SHORT:
                if (*fmt == 'h')
                {
                    length = PRINTF_LENGTH_SHORT_SHORT;
                    state = PRINTF_STATE_SPEC;
                }
                else
                {
                   goto PRINTF_STATE_SPEC_; 
                }
                break;

            case PRINTF_STATE_LENGTH_LONG:
                if (*fmt == 'l')
                {
                    length = PRINTF_LENGTH_LONG_LONG;
                    state = PRINTF_STATE_SPEC;
                }
                else
                {
                   goto PRINTF_STATE_SPEC_; 
                }
                break;

            case PRINTF_STATE_SPEC:
            PRINTF_STATE_SPEC_:
                switch (*fmt)
                {
                    case 'c':   
                        putc1((char)*arg);
                        arg+=2;
                        break;

                    case 's':   
                        if (length == PRINTF_LENGTH_LONG || length == PRINTF_LENGTH_LONG_LONG) 
                        {
                            //int count = strlen_printf(arg);
                            //unsigned int memory_alocated = count / 8;
                            //arg = arg - (8 * memory_alocated);
                            arg-=16;
                            puts1(*(const char**)arg);
                            arg+=2;
                        }
                        else 
                        {
                            char *n = (char *)*(arg-4);
                            puts1(n);
                            arg+=2;
                        }
                        break;

                    case '%':
                        putc1('%');
                        break;
                    
                    default:    
                        break;
                }
                state = PRINTF_STATE_DEFAULT;
                length = PRINTF_LENGTH_DEFAULT;
                numSystem = 10;
                sign = false;
                break;
        }

        fmt++;
    }
}*/

void aa(int* str)
{
    char *d = (char *)str;
    puts(d);
}
int main(int argc,char **argv)
{
    //printf1("%d", 15);    
    //puts("Hellodfsfsd\n");
    int *str = "Hello\n";
    int *dup = "There\n";
    //printf("str: %d\n", str);
    //puts1(str);
    printf("%s %s %d %d", dup, str, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 14);
    //aa(str);
    //printf("%s\n", 43);
    return 0;
}