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
        // dynamic list test
        LIST list = create_list(sizeof(I32));
        ulist_push_back(&list, 32);
        ilist_push_back(&list, -64);
        ulist_push_back(&list, 128);
        ulist_push_back(&list, 256);
        for(int i = 0; i < list_length(&list);i++){
            printf("%d. %lld\n", i, *list.contents[i]);
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        list_pop(&list);
        list_shift(&list);
        for(int i = 0; i < list_length(&list);i++){
            printf("%d. %lld\n", i, *list.contents[i]);
        }

        printf("%lld\n", ilist_at_index(&list, 0));
        ireplace_value_at_index(&list, 0, 0xFF);
        printf("%lld\n", ilist_at_index(&list, 0));
        upush_value_to_index(&list, 1, 13);
        upush_value_to_index(&list, 2, 11);
        upush_value_to_index(&list, 5, 88);
        pop_from_index(&list, 4);
        for(int i = 0; i < list_length(&list);i++){
            printf("%d. %lld\n", i, *list.contents[i]);
        }
        list_free(&list);
    }
    {
        // crypt header tests
        // randseed(1000);
        printf("Random number: %lu, %lu\n", urand(), urand_range(10, 1000));

        U32 *key = generate_256_key("a");
            printf("256-bit key: 0x");
        for(int i = 0; i < WORDCOUNT; i++){
            printf("%lx", key[i]);
        }
        printf("\n");
        free(key);
    }
    printf("END\n");
    return 0;
}