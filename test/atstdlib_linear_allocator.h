/*+++
    ATSTDLIB LINEAR ALLOCATOR HEADER - Antonako1
    
    Licensed under MIT
---*/
#ifndef ATSTDLIB_LINEAR_ALLOCATOR_H
#define ATSTDLIB_LINEAR_ALLOCATOR_H
#include <atstdlib_api.h>
#include <atstdlib_types.h>
#include <atstdlib_error.h>

/*+++
Linear allocator usage/definition

Using stack memory:
    {
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
        reset_linear_memory(&la);
    }
Using heap memory:
    {
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
---*/

typedef struct LINEAR_ALLOCATOR {
    U0 *home_pointer;       // Pointer to start of linear allocator
    U0 *current_endpoint;   // Pointer to the end of the memory stack
    U64 memory_size;        // Memory size
} LINEAR_ALLOCATOR;

/// @brief                  Creates a new linear allocator
/// @param home_pointer     Start of the linear allocator in stack or heap. End pointer will use the same.
/// @param memory_size      Size of the memory allocation
/// @param linear_allocator Pointer to linear allocator where it will be created
/// @return ERRCODE_SUCCESS on success, ERRCODE_FAILURE on failure
ATSTDLIB_API ERR32 create_linear_allocator(U0 *home_pointer, U64 memory_size, LINEAR_ALLOCATOR *linear_allocator);

/// @brief                      Allocate memory to linear allocator
/// @param size                 Memory amount to allocate
/// @param linear_allocator     Pointer to Linear Allocator
/// @return                     Pointer to mallocated type. NULLPTR on failure
ATSTDLIB_API U0 *linear_allocation(U64 size, LINEAR_ALLOCATOR *linear_allocator);

/// @brief                      Moves Linear allocator's endpoint pointer to home. Zeroes all memory to 0x0
/// @param linear_allocator     Pointer to linear allocator
ATSTDLIB_API U0 reset_linear_memory(LINEAR_ALLOCATOR *linear_allocator);

/// @brief                      Use if linear memory is heap allocated and needs to be freed. Freeing home pointer will also work
/// @param linear_allocator     pointer to linear allocator 
/// @note                       ONLY USE WHEN HEAP ALLOCATING
ATSTDLIB_API U0 free_linear_memory(LINEAR_ALLOCATOR *linear_allocator);
#endif // ATSTDLIB_LINEAR_ALLOCATOR_H