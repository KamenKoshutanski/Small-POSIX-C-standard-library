#include "string.h"

char *strcchr(const char *str, int c){
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == c){
            return ((char*)(str) + i);
        }
    }
    return NULL;
}

size_t strlen(const char *str)
{
    unsigned int count = 0;
    while(*str!='\0')
    {
        count++;
        str++;
    }
    return count;
}

char *strcat(char *dest, const char *src)
{
    unsigned int lenght = strlen(dest);
    for(int i = 0; i < strlen(src); i++){
        dest[lenght + i] = src[i];
    }
    dest[strlen(dest) + strlen(src)] = '\0';
    return dest;
}

char *strncat(char *dest, const char *src, size_t n) 
{
    unsigned int lenght = strlen(dest);
    for(int i = 0; i < n; i++)
    {
        dest[lenght + i] = src[i];
    }
    dest[strlen(dest) + strlen(src)] = '\0';
    return dest;
}

int strcmp(const char *str1, const char *str2)
{
    for(int i = 0; i < strlen(str1) && i < strlen(str2); i++)
    {
        if(str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
    }

    if(strlen(str1) > strlen(str2)){
        return str1[strlen(str2)];
    }
    else if(strlen(str1) < strlen(str2))
    {
        return 0 - str2[strlen(str1)];
    }

    return 0;
}

int strncmp(const char *str1, const char *str2, size_t n)
{
    for(int i = 0; i < strlen(str1) && i < strlen(str2) && i < n; i++)
    {
        if(str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
    }

    if(strlen(str1) > strlen(str2) && n > strlen(str1) && n > strlen(str2)){
        return str1[strlen(str2)];
    }
    else if(strlen(str1) < strlen(str2) && n > strlen(str2))
    {
        return 0 - str2[strlen(str1)];
    }

    return 0;
}

char *strcpy(char *dest, const char *src){
    for(int i = 0; i < strlen(src); i++)
    {
        dest[i] = src[i];
    }
    dest[strlen(src)] = '\0';
    return dest; 
}

char *strncpy(char *dest, const char *src, size_t n)
{
    for(int i = 0; i < strlen(src) && i < n; i++)
    {
        dest[i] = src[i];
    }
    dest[strlen(src)] = '\0';
    return dest; 
}

size_t strcspn(const char *str1, const char *str2)
{
    for(int i = 0; i < strlen(str1); i++)
    {
        for(int j = 0; j < strlen(str2); j++)
        {
            if(str1[i] == str2[j])
            {
                return i;
            }
        }
    }
    return strlen(str1);
}

char *strpbrk(const char *str1, const char *str2)
{
    for(int i = 0; i < strlen(str1); i++)
    {
        for(int j = 0; j < strlen(str2); j++)
        {
            if(str1[i] == str2[j])
            {
                return ((char *)(str1) + i);
            }
        }
    }
    return NULL;
}

char *strrchr(const char *str, int c)
{
    char *curLast = NULL; 
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == c){
           curLast = (char*)(str + i);
        }
    }
    return curLast;
}

size_t strspn(const char *str1, const char *str2)
{
    unsigned int count = 0;
    unsigned int consecutive_flag = 0;
    for(int i = 0; i < strlen(str1); i++)
    {
        for(int j = 0; j < strlen(str2); j++)
        {
            if(str1[i] == str2[j])
            {
                consecutive_flag = 1;
                count++;
            }
        }
        if(consecutive_flag == 0){
            return count;
        }
        consecutive_flag = 0;
    }
    return count;
}

char *strstr(const char *haystack, const char *needle)
{
    unsigned int consecutive = 0;
    char *ret;
    for(int i = 0; i < strlen(haystack); i++)
    {
        if(haystack[i] == needle[0]){
            ret = (char *)(haystack + i);
            for(int j = 0; j < strlen(needle); j++)
            {
                if(haystack[i+j] == needle[j])
                {
                    consecutive++;
                    if(consecutive == strlen(needle))
                    {
                        return ret;
                    }
                }
            }
        }
    }
    return NULL;
}

unsigned int is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}

char *strtok(char *str, const char *delim){
    char *backup_string;
    if(!str)
    {
        str = backup_string;
    }
    if(!str)
    {
        return NULL;
    }
    while(1)
    {
        if(is_delim(*str, (char*)delim))
        {
            str++;
            continue;
        }
        if(*str == '\0')
        {
            return NULL; 
        }
        break;
    }
    char *ret = str;
    while(1)
    {
        if(*str == '\0')
        {
            backup_string = str;
            return ret;
        }
        if(is_delim(*str, (char*)delim))
        {
            *str = '\0';
            backup_string = str + 1;
            return ret;
        }
        str++;
    }
}