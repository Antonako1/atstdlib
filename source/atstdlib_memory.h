#ifndef ATSTDLIB_MEMORY_H
#define ATSTDLIB_MEMORY_H
#include <atstdlib_types.h>
#include <atstdlib_error.h>
#include <atstdlib_api.h>

/*+++
atstd_realloc
---*/

ATSTDLIB_API ERR32 atstd_realloc(U0 *block, U64 size);

#endif // ATSTDLIB_MEMORY_H