#include "atstdlib.h"
#include <stdio.h>
#include <stdlib.h>

I32 main(I32 argc, const I8 *argv){
    printf("HI\n");
    // LINEAR_ALLOCATOR STACK TEST
    U8 memory_block[1024]; // Memory block for linear allocator 1024
    LINEAR_ALLOCATOR la = create_linear_allocator(memory_block, sizeof(memory_block));
    printf("0x%lld\n", (unsigned long long)la.home_pointer);
    U0 *test = linear_allocation(1024, &la);
    if(test == NULLPTR){
        printf("Allocation failed!\n");
        return 1;
    }
    reset_linear_memory(&la);
    
    // LINEAR_ALLOCATOR HEAP TEST
    U64 memory_size = 1024;
    U0 *memory_blockh = malloc((size_t)memory_size);
    LINEAR_ALLOCATOR la2 = create_linear_allocator(memory_blockh, memory_size);
    test = linear_allocation(1024, &la);
    if(test == NULLPTR){
        printf("Allocation failed!\n");
        free_linear_memory(&la2);
        return 1;
    }
    reset_linear_memory(&la2);
    free_linear_memory(&la2);
    return 0;
}