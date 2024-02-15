#include "time.h"

int nanoseconds(int nanoseconds)
{
    struct timespec remaining, request = { 0, nanoseconds }; 

    return nanosleep(&request, &remaining);
}
int sleep(int seconds)
{
    struct timespec remaining, request = { seconds, 0 }; 

    return nanosleep(&request, &remaining);
}