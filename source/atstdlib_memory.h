/*+++
    ATSTDLIB MEMORY HEADER - Antonako1
    
    Licensed under MIT
---*/
#ifndef ATSTDLIB_MEMORY_H
#define ATSTDLIB_MEMORY_H
#include <atstdlib_types.h>
#include <atstdlib_api.h>

/*+++
atstd_realloc usage
    U64 *old_contents = malloc(sizeof(U64));
    U64 *new_contents = atstd_realloc(old_contents, 2 * sizeof(U64));
    if (new_contents == NULLPTR) {
        free(old_contents);
        return 1;
    }
    old_contents = new_contents;
---*/

/// @brief Reallocetes memory
/// @param block Old memoryblock's address
/// @param size New size in bytes
/// @return NULLPTR -- When reallocation wasn't succesfull
ATSTDLIB_API U0 *atstd_realloc(U0 *block, U64 size);

#endif // ATSTDLIB_MEMORY_H