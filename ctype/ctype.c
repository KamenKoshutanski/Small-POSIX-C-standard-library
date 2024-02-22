#include "ctype.h"
#include <stdio.h>

int Digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int HexadecimalDigits[22] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};
int asciiFirstLetter = 'A';

int isalnum(int c)
{
    for(int i = 0; i < 10; i++)
    {
        if(c == Digits[i])
        {
            return 1;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(c == (asciiFirstLetter + i))
        {
            return 1;
        }
        if(c == (asciiFirstLetter + 32 + i))
        {
            return 1;
        }
    }
    return 0;
}

int isalpha(int c)
{
    for(int i = 0; i < 26; i++)
    {
        if(c == (asciiFirstLetter + i))
        {
            return 1;
        }
        if(c == (asciiFirstLetter + 32 + i))
        {
            return 1;
        }
    }
    return 0;
}

int iscntrl(int c)
{
    if(((c < 32) && (c >= 0)) || c == 127)
    {
        return 1;
    }
    return 0;
}

int isdigit(int c)
{
    for(int i = 0; i < 10; i++)
    {
        if(c == Digits[i])
        {
            return 1;
        }
    }
    return 0;
}

int isgraph(int c)
{
    if((c < 127) && (c > 32))
    {
        return 1;
    }
    return 0;
}

int islower(int c)
{
    for(int i = 0; i < 26; i++)
    {
        if(c == (asciiFirstLetter + 32 + i))
        {
            return 1;
        }
    }
    return 0;
}

int isprint(int c)
{
    if((c < 127) && (c > 32))
    {
        return 1;
    }
    return 0;
}

int ispunct(int c)
{
    if(isgraph(c))
    {
        if(isalnum(c))
        {
            return 0;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int isspace(int c)
{
    if((c == 32) || ((c >= 9) && (c <= 13)))
    {
        return 1;
    }
    return 0;
}

int isupper(int c)
{
    for(int i = 0; i < 26; i++)
    {
        if(c == (asciiFirstLetter + i))
        {
            return 1;
        }
    }
    return 0;
}

int isxdigit(int c)
{
    for(int i = 0; i < 22; i++)
    {
        if(c == HexadecimalDigits[i])
        {
            return 1;
        }
    }
    return 0;
}

int tolower(int c)
{
    if((c < asciiFirstLetter + 26) && (c >= asciiFirstLetter))
    {
        return c + 32;
    }
    return c;
}

int toupper(int c)
{
    if((c < asciiFirstLetter + 32 + 26) && (c >= asciiFirstLetter + 32))
    {
        return c - 32;
    }
    return c;
}