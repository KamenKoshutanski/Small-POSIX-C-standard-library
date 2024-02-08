#include "unistd.h"

int main(){
    int fd = write(STDOUT, "Hello", 6);
    const void* buf;
    int d1 = read(STDIN, buf, 100);
    return 0;
}
void _start(){
    int main_ret = main();
    _exit(main_ret);
}