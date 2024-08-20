/*+++
    ATSTDLIB ARRAY HEADER - Antonako1
    
    Licensed under MIT
---*/
#ifndef ATSTDLIB_ARRAY_H
#define ATSTDLIB_ARRAY_H
#include <atstdlib_types.h>
#include <atstdlib_error.h>
#include <atstdlib_api.h>
/*+++
Dynamic array

Array usage/definition:
(cast)U0 **arr = create_array();
ERR32 arr_push_back(arr, 80);
ERR32 arr_pop(arr);           // Remove from back
ERR32 arr_shift(arr);         // Remove from front
U64 arr_len(arr);
arr_free(arr);
---*/

/// @brief Creates array
/// @return Returns only a NULLPTR.
ATSTDLIB_API U0 **create_arr();

ATSTDLIB_API ERR32 arr_push_back(U0 **arr, U64 value);

ATSTDLIB_API U0 arr_free(U0 **arr);

#endif //  ATSTDLIB_ARRAY_H