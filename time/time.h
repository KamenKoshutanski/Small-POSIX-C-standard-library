#ifndef _TIME_H
#define _TIME_H

#include "../stdint.h"
typedef long clock_t;
typedef int32_t __time32_t;	
typedef int64_t __time64_t;	


struct timespec
{
  __time64_t tv_sec;
  int32_t tv_nsec;
  //The value of tv_nsec should be between 0 to 999999999 or else the program will give an error.
};

int nanosleep(const struct timespec *req, struct timespec *rem);
int nanoseconds(int nanoseconds);
int sleep(int seconds);

#endif