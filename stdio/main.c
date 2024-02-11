#include "stdio.h"
#include "../unistd/unistd.h"

int main(){
    printf("Hello\n");
    //printf("%ls %c", "Hello world Yey\n" "\n");
    //printf("%s", "AHell\n");
    //printf("%c", "B");
    printf("%d\n", 2);
    return 0;
}
void _start(){
    int main_ret = main();
    _exit(main_ret);
}