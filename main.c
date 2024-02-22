#include <stdio.h>

int main(int argc,char **argv)
{
    int x;
    int a = x;
    int b = x;
    int c = a + b;
    printf("%d\n", c);
    return 0;
}