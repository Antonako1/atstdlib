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
        // dynamic array test
        ARRAY arr = create_arr(sizeof(I32));
        uarr_push_back(&arr, 32);
        iarr_push_back(&arr, -64);
        uarr_push_back(&arr, 128);
        uarr_push_back(&arr, 256);
        for(int i = 0; i < arr_length(&arr);i++){
            printf("%d. %lld\n", i, *arr.contents[i]);
        }
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        arr_pop(&arr);
        arr_shift(&arr);
        for(int i = 0; i < arr_length(&arr);i++){
            printf("%d. %lld\n", i, *arr.contents[i]);
        }
        arr_free(&arr);
---*/

typedef struct ARRAY {
    U64 **contents;
    U64 length;
    U64 item_entry_size;    // SIZE HELD IN BYTES
} ARRAY;

/// @brief Creates a dynamic array
/// @param size_of_item_entry Size of items the array will hold in bytes
/// @return NULLPTR initialzied empty array
ATSTDLIB_API ARRAY create_arr(U64 size_of_item_entry);

/// @brief Pushes back an item to given array. For unsigned values
/// @param arr Pointer to array
/// @param value Value to be pushed back
/// @return ERRCODE_INVALID_VALUE_SIZE  -- Value you are trying to push is over the array limit
///         ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_SUCCESS             -- Succesfully pushed back
ATSTDLIB_API ERR32 uarr_push_back(ARRAY *arr, U64 value);

/// @brief Pushes back an item to given array. For signed values
/// @param arr Pointer to array
/// @param value Value to be pushed back
/// @return ERRCODE_INVALID_VALUE_SIZE  -- Value you are trying to push is over the array limit
///         ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_SUCCESS             -- Succesfully pushed back
ATSTDLIB_API ERR32 iarr_push_back(ARRAY *arr, I64 value);

/// @brief Frees array's contents
/// @param arr Pointer to array
ATSTDLIB_API U0 arr_free(ARRAY *arr);

/// @brief Returns array's length
/// @param arr Pointer to ARRAY
/// @return Returns array's length
ATSTDLIB_API U64 arr_length(ARRAY *arr);

/// @brief Returns single item size in bytes
/// @param arr Pointer to ARRAY
/// @return single item size in bytes
ATSTDLIB_API U64 arr_item_size(ARRAY *arr);

/// @brief Removes element from the start of the array
/// @param arr Array where to delete from
/// @return ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_SUCCESS             -- Succesfully shifted
///         ERRCODE_FAILURE             -- Shifting from an empty array
ATSTDLIB_API ERR32 arr_shift(ARRAY *arr);

/// @brief Removes element from the end of the array
/// @param arr Array where to delete from
/// @return ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_SUCCESS             -- Succesfully popped
///         ERRCODE_FAILURE             -- Popping from an empty array
ATSTDLIB_API ERR32 arr_pop(ARRAY *arr);

/// @brief Returns unsigned value at index
/// @param arr Pointer to ARRAY
/// @param index Index
/// @return Value at location. Will not check for overflow
ATSTDLIB_API U64 uarr_at_index(ARRAY *arr, U64 index);

/// @brief Returns signed value at index
/// @param arr Pointer to ARRAY
/// @param index Index
/// @return Value at location. Will not check for overflow
ATSTDLIB_API I64 iarr_at_index(ARRAY *arr, U64 index);

/// @brief Replaces value of element at given index with unsigned value
/// @param arr Pointer to ARRAY
/// @param index Index
/// @param value Value to replace with
/// @return ERRCODE_SUCCESS             -- Succesfully replaced
///         ERRCODE_FAILURE             -- Invalid index
ATSTDLIB_API ERR32 ureplace_value_to_index(ARRAY *arr, U64 index, U64 value);


/// @brief Replaces value of element at given index with signed value
/// @param arr Pointer to ARRAY
/// @param index Index
/// @param value Value to replace with
/// @return ERRCODE_SUCCESS             -- Succesfully replaced
///         ERRCODE_FAILURE             -- Invalid index
ATSTDLIB_API ERR32 ireplace_value_to_index(ARRAY *arr, U64 index, I64 value);

/// @brief Pushes value to the index given. Values to the right of index will be pushed right
/// @param arr Pointer to ARRAY
/// @param index Index where to insert. NOTE: IF LARGER THAN ARRAY SIZE, NULLPTR ENTRIES WILL BE CREATED AS BUFFER
/// @param value Value of new entry
/// @return ERRCODE_SUCCESS             -- Succesfully replaced
///         ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_FAILURE             -- TODO:
ATSTDLIB_API ERR32 upush_value_to_index(ARRAY *arr, U64 index, I64 value);

ATSTDLIB_API ERR32 ipush_value_to_index(ARRAY *arr, U64 index, U64 value);
#endif //  ATSTDLIB_ARRAY_H