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
    ARRAY arr = create_arr(sizeof(U8)); 
---*/

typedef struct ARRAY {
    U0 **contents;
    U64 length;
    U64 item_entry_size;
} ARRAY;

/// @brief Creates a dynamic array
/// @param size_of_item_entry Size of items the array will hold in bytes
/// @return NULLPTR initialzied empty array
ATSTDLIB_API ARRAY create_arr(U64 size_of_item_entry);

/// @brief Pushes back an item to given array. For arrays that hold unsigned values
/// @param arr Pointer to array
/// @param value Value to be pushed back
/// @return ERRCODE_INVALID_VALUE_SIZE  -- Value you are trying to push is over the array limit
///         ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_SUCCESS             -- Succesfully pushed back
ATSTDLIB_API ERR32 uarr_push_back(ARRAY *arr, U64 value);

/// @brief Pushes back an item to given array. For arrays that hold signed values
/// @param arr Pointer to array
/// @param value Value to be pushed back
/// @return ERRCODE_INVALID_VALUE_SIZE  -- Value you are trying to push is over the array limit
///         ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_SUCCESS             -- Succesfully pushed back
ATSTDLIB_API ERR32 iarr_push_back(ARRAY *arr, I64 value);

/// @brief Frees array's contents
/// @param arr Pointer to array
ATSTDLIB_API U0 arr_free(ARRAY *arr);

ATSTDLIB_API U64 arr_length(U0 **arr);

#endif //  ATSTDLIB_ARRAY_H