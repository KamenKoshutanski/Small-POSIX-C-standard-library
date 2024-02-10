#include "unistd.h"

int main(){
    char* buf = "Hello\n";
    int fd = write(STDOUT, buf, 6);
    return 0;
}
void _start(){
    int main_ret = main();
    _exit(main_ret);
}