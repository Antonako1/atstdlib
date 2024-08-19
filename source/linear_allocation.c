#include <atstdlib_linear_allocator.h>
#include <atstdlib_types.h>
#include <stdlib.h> // free()
#include <memory.h> // memset()

LINEAR_ALLOCATOR create_linear_allocator(U0 *home_pointer, U64 memory_size){
    LINEAR_ALLOCATOR res;
    res.current_endpoint    = home_pointer;
    res.home_pointer        = home_pointer;
    res.memory_size         = memory_size;
    return res;
}

U0 *linear_allocation(U64 size, LINEAR_ALLOCATOR *linear_allocator) {
    U64 used_memory = ((U64)linear_allocator->current_endpoint - (U64)linear_allocator->home_pointer);
    if (used_memory + size > linear_allocator->memory_size) {
        return NULLPTR;
    }
    U0 *memory_allocation = linear_allocator->current_endpoint;
    linear_allocator->current_endpoint = (U0 *)((U64)linear_allocator->current_endpoint + size);
    return memory_allocation;
}

U0 reset_linear_memory(LINEAR_ALLOCATOR *linear_allocator){
    memset(linear_allocator->home_pointer, 0, (size_t)linear_allocator->memory_size);
    linear_allocator->current_endpoint = linear_allocator->home_pointer;
}

U0 free_linear_memory(LINEAR_ALLOCATOR *linear_allocator){
    free(linear_allocator->home_pointer);
}