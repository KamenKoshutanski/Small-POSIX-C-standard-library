// C Program to demonstrate 
// use of nanosleep 
#include <stdio.h> 
#include "time.h"


int main() 
{ 
    struct timespec remaining, request = { 10, 0 }; 
    printf("Running\n"); 
  
    for (int i = 0; i < 10; ++i) { 
  
        printf("loop  %d\n", i); 
        if (i == 4) { 
            printf("Nap time ...\n"); 
            sleep(10);
        } 
    } 
  
    return 0;
}