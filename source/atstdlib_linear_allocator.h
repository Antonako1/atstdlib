/*+++
    ATSTDLIB LINEAR ALLOCATOR HEADER - Antonako1
    
    Licensed under MIT
---*/
#ifndef ATSTDLIB_LINEAR_ALLOCATOR_H
#define ATSTDLIB_LINEAR_ALLOCATOR_H
#include <atstdlib_api.h>
#include <atstdlib_types.h>

typedef struct LINEAR_ALLOCATOR {
    U0 *home_pointer;       // Pointer to start of linear allocator
    U0 *current_endpoint;   // Pointer to the end of the memory stack
    U64 memory_size;        // Memory size
} LINEAR_ALLOCATOR;

/// @brief              Creates a new linear allocator
/// @param home_pointer Start of the linear allocator stack. End pointer will use the same
/// @param memory_size  Size of the memory allocation
/// @return             Linear allocator with initialized with given values
ATSTDLIB_API LINEAR_ALLOCATOR create_linear_allocator(U0 *home_pointer, U64 memory_size);

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