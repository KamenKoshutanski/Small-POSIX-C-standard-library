#include "stdio.h"
#include "arm.h"
#include "../stdint.h"
#include "../stdbool.h"

#define PRINTF_STATE_DEFAULT        0
#define PRINTF_STATE_LENGTH         1
#define PRINTF_STATE_LENGTH_SHORT   2
#define PRINTF_STATE_LENGTH_LONG    3
#define PRINTF_STATE_SPEC           4

#define PRINTF_LENGTH_DEFAULT       0
#define PRINTF_LENGTH_SHORT_SHORT   1
#define PRINTF_LENGTH_SHORT         2
#define PRINTF_LENGTH_LONG          3
#define PRINTF_LENGTH_LONG_LONG     4

void putc(char c)
{
    putToStdOut(&c);
}

void puts(const char* str)
{
    while(*str)
    {
        putc(*str);
        str++;
    }
}

const char* printf_number(const char* arg, int length, bool sign, int numSystem);

unsigned int strlen_printf(const char *s)
{
    unsigned int count = 0;
    while(*s!='\0')
    {
        count++;
        s--;
    }
    return count;
}

/*void printf(const char* fmt, ...)
{
    const char* arg = fmt;
    int state = PRINTF_STATE_DEFAULT;
    int length = PRINTF_LENGTH_DEFAULT;
    int numSystem = 10;
    bool sign = false;
    arg-=8;
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
                        putc(*fmt);
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
                        putc((char)*arg);
                        arg-=8;
                        break;

                    case 's':   
                        if (length == PRINTF_LENGTH_LONG || length == PRINTF_LENGTH_LONG_LONG) 
                        {
                            int count = strlen_printf(arg);
                            unsigned int memory_alocated = count / 8;
                            arg = arg - (8 * memory_alocated);
                            puts(arg);
                            arg-=16;
                        }
                        else 
                        {
                            puts(arg);
                            arg-=8;
                        }
                        break;

                    case '%':
                        putc('%');
                        break;
                    
                    //Not working still
                    case 'd':
                    case 'i':   
                        numSystem = 10; sign = true;
                        arg = printf_number(arg, length, sign, numSystem);
                        break;

                    case 'u':   
                        numSystem = 10; sign = false;
                        arg = printf_number(arg, length, sign, numSystem);
                        break;

                    case 'X':
                    case 'x':
                    case 'p':   
                        numSystem = 16; sign = false;
                        arg = printf_number(arg, length, sign, numSystem);
                        break;

                    case 'o':   
                        numSystem = 8; sign = false;
                        arg = printf_number(arg, length, sign, numSystem);
                        break;
                    
                    //not implemented
                    case 'f':
                        numSystem = 10; sign = true;
                        arg = printf_number(arg, length, sign, numSystem);
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
    arg = "";
}
*/
const char g_HexChars[] = "0123456789abcdef";

const char* printf_number(const char* arg, int length, bool sign, int numSystem)
{
    char buffer[32];
    unsigned long long number;
    int number_sign = 1;
    int pos = 0;
    switch (length)
    {
        case PRINTF_LENGTH_SHORT_SHORT:
        case PRINTF_LENGTH_SHORT:
        case PRINTF_LENGTH_DEFAULT:
            if (sign)
            {
                int n = (int)*arg;
                if (n < 0)
                {
                    n = -n;
                    number_sign = -1;
                }
                number = (unsigned long long)n;
            }
            else
            {
                number = *(unsigned int*)arg;
            }
            arg -= 8;
            break;

        case PRINTF_LENGTH_LONG:
            if (sign)
            {
                long int n = *(long int*)arg;
                if (n < 0)
                {
                    n = -n;
                    number_sign = -1;
                }
                number = (unsigned long long)n;
            }
            else
            {
                number = *(unsigned long int*)arg;
            }
            arg -= 16;
            break;

        case PRINTF_LENGTH_LONG_LONG:
            if (sign)
            {
                long long int n = *(long long int*)arg;
                if (n < 0)
                {
                    n = -n;
                    number_sign = -1;
                }
                number = (unsigned long long)n;
            }
            else
            {
                number = *(unsigned long long int*)arg;
            }
            arg -= 32;
            break;
    }

    do 
    {
        uint32_t remain = number % numSystem;
        number = number / numSystem;
        buffer[pos++] = g_HexChars[remain];
    } while (number > 0);

    if (sign && number_sign < 0)
    {
        buffer[pos++] = '-';
    }

    while (--pos >= 0)
    {
        putc(buffer[pos]);
    }
        

    return arg;
}

//needs testing
/*int getchar(void){
    getFromStdIn();
}

char *gets(char *str){
    while(getchar() != EOF || getchar() != "\n")
    {
        *str = getchar();
        str++;
    }
    return str;
}*/


void printf(const char* fmt, ...)
{
    int* arg = (int*)&fmt;
    int state = PRINTF_STATE_DEFAULT;
    int length = PRINTF_LENGTH_DEFAULT;
    int numSystem = 10;
    bool sign = false;
    puts("First:\n");
    for(int i = 0; i < 240; i++){
        puts(*(const char**)arg-i);
    }
    arg-=8;
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
                        putc(*fmt);
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
                        putc((char)*arg);
                        arg-=8;
                        break;

                    case 's':   
                        if (length == PRINTF_LENGTH_LONG || length == PRINTF_LENGTH_LONG_LONG) 
                        {
                            /*int count = strlen_printf(arg);
                            unsigned int memory_alocated = count / 8;
                            arg = arg - (8 * memory_alocated);*/
                            arg-=16;
                            puts(*(const char**)arg);
                            arg-=16;
                        }
                        else 
                        {
                            puts(*(const char**)arg);
                            arg-=8;
                        }
                        break;

                    case '%':
                        putc('%');
                        break;
                    
                    //Not working still
                    /*case 'd':
                    case 'i':   
                        numSystem = 10; sign = true;
                        arg = printf_number(arg, length, sign, numSystem);
                        break;

                    case 'u':   
                        numSystem = 10; sign = false;
                        arg = printf_number(arg, length, sign, numSystem);
                        break;

                    case 'X':
                    case 'x':
                    case 'p':   
                        numSystem = 16; sign = false;
                        arg = printf_number(arg, length, sign, numSystem);
                        break;

                    case 'o':   
                        numSystem = 8; sign = false;
                        arg = printf_number(arg, length, sign, numSystem);
                        break;
                    
                    //not implemented
                    case 'f':
                        numSystem = 10; sign = true;
                        arg = printf_number(arg, length, sign, numSystem);
                        break;*/

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
}