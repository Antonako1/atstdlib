#include "atstdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        U32 *key = generate_256_key("TESTHASH123");
        if(key != NULLPTR){
            printf("256-bit key: 0x");
            for(int i = 0; i < WORDCOUNT; i++){
                printf("%lx", key[i]);
            }
            printf("\n");
            free(key);
        }
    }
    {
        // regex
        /*
        Example 1:
            Input: a+b*(c^d-e)^(f+g*h)-i
            Output: abcd^e-fgh*+^*+i-
            Explanation: Infix to postfix

        Example 2:
            Input: (p+q)*(m-n)
            Output: pq+mn-*
            Explanation: Infix to postfix
        */
        U8 *regex = "(p+q)*(m-n)";
        U8 *input = "Hello, World!";
        BOOLEAN test = check_str_against_regex(regex, input);
    }
    {
        // str tests
        printf("STRLEN: %llu, %zd\n", ustrlen("Hi"), strlen("Hi"));
        printf("WSTRLEN: %llu, %zd\n", uwstrlen(L"Hi"), wcslen(L"Hi"));
        printf("STRNLEN: %llu, %zd\n", ustrnlen("Hi12345", 5), strnlen("Hi12345", 5));
        printf("WSTRNLEN: %llu, %zd\n", uwstrnlen(L"Hi", 5), wcsnlen(L"Hi", 5));

    }
    printf("END\n");
    return 0;
}