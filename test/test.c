#include "atstdlib.h"
#include <stdio.h>
#include <stdlib.h>

I32 main(I32 argc, const I8 *argv){
    printf("HI\n");
    {
        // LINEAR_ALLOCATOR STACK TEST
        U8 memory_block[1024];
        LINEAR_ALLOCATOR la;
        ERR32 err = create_linear_allocator(memory_block, sizeof(memory_block), &la);
        if(err == ERRCODE_FAILURE){
            printf("Creation failed!\n");
            return 1;
        }
        printf("0x%lld\n", (unsigned long long)la.home_pointer);
        U64 *test = linear_allocation(sizeof(U64), &la);
        if(test == NULLPTR){
            printf("Allocation failed!\n");
            return 1;
        }
        *test = U64_MAX;
        printf("%llx\n", *test);
        reset_linear_memory(&la);
    }

    {
        // LINEAR_ALLOCATOR HEAP TEST
        LINEAR_ALLOCATOR la;
        ERR32 err = create_linear_allocator(malloc(1024), 1024, &la);
        if(err = ERRCODE_FAILURE){
            printf("Creation failed!\n");
            return 1;
        }
        U16 *test = linear_allocation(1024, &la);
        if(test == NULLPTR){
            printf("Allocation failed!\n");
            free_linear_memory(&la);
            return 1;
        }
        free_linear_memory(&la);
    }

    {
        // dynamic array test
        ARRAY arr = create_arr(sizeof(I32));
        uarr_push_back(&arr, 32);
        iarr_push_back(&arr, -64);
        uarr_push_back(&arr, 128);
        uarr_push_back(&arr, 256);
        for(int i = 0; i < arr_length(&arr);i++){
            printf("%d. %lld\n", i, *arr.contents[i]);
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        arr_pop(&arr);
        arr_shift(&arr);
        for(int i = 0; i < arr_length(&arr);i++){
            printf("%d. %lld\n", i, *arr.contents[i]);
        }
        arr_free(&arr);
    }
    return 0;
}