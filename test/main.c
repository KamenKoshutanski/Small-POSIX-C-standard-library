//#include <unistd.h>
#include <stdio.h>
//#include <stdlib.h>
#include "stdlib1.h"


int main()
{
    m_block* block = NULL ; 
    malloc1(100 , &block); 
    malloc1(1 , &block);
    malloc1(1 , &block);
    print_blocks(block);

    /*int* ptr;
    int n, i;
 
    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);
 
    // Dynamically allocate memory using malloc()
    init();
    m_block* block = NULL ; 
    malloc1(n * sizeof(int) , &block); 
    ptr = block->mem_addr;
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }*/
    return 0;
}
