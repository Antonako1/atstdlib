#ifndef ATSTDLIB_MEMORY_H
#define ATSTDLIB_MEMORY_H
#include <atstdlib_types.h>
#include <atstdlib_api.h>

/*+++
atstd_realloc
---*/

/// @brief 
/// @param block 
/// @param size 
/// @return NULLPTR -- When reallocation wasn't succesfull
ATSTDLIB_API U0 *atstd_realloc(U0 *block, U64 size);

#endif // ATSTDLIB_MEMORY_H