/*+++
    ATSTDLIB LIST HEADER - Antonako1
    
    Licensed under MIT
---*/
#ifndef ATSTDLIB_LIST_H
#define ATSTDLIB_LIST_H
#include <atstdlib_types.h>
#include <atstdlib_error.h>
#include <atstdlib_api.h>


/*+++
    Dynamic list
        Each entry in the list is allocated. Unlike vector, list is not a continuous chunk of memory.
        Dynamic list needs to have item size defined in bytes.
        It can hold both unsigned and signed values at the same time.
        You need to use the approriate functions for these (prefexied with "u" for unsigned, "i" for signed).
        You need to free the list after usage using list_free() function.
        ERR32 checks are not necessary, neither are they discouraged.

    List usage/definition:
        // dynamic List test
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
        list_free(&list);
---*/

typedef struct LIST {
    U64 **contents;
    U64 length;
    U64 item_entry_size;    // SIZE HELD IN BYTES
} LIST;

/// @brief Creates a dynamic list
/// @param size_of_item_entry Size of items the list will hold in bytes
/// @return NULLPTR initialzied empty list
ATSTDLIB_API LIST create_list(U64 size_of_item_entry);

/// @brief Pushes back an item to given list. For unsigned values
/// @param list Pointer to list
/// @param value Value to be pushed back
/// @return ERRCODE_INVALID_VALUE_SIZE  -- Value you are trying to push is over the list limit
///         ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_SUCCESS             -- Succesfully pushed back
ATSTDLIB_API ERR32 ulist_push_back(LIST *list, U64 value);

/// @brief Pushes back an item to given list. For signed values
/// @param list Pointer to list
/// @param value Value to be pushed back
/// @return ERRCODE_INVALID_VALUE_SIZE  -- Value you are trying to push is over the list limit
///         ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_SUCCESS             -- Succesfully pushed back
ATSTDLIB_API ERR32 ilist_push_back(LIST *list, I64 value);

/// @brief Frees list's contents
/// @param list Pointer to list
ATSTDLIB_API U0 list_free(LIST *list);

/// @brief Returns list's length
/// @param list Pointer to LIST
/// @return Returns list's length
ATSTDLIB_API U64 list_length(LIST *list);

/// @brief Returns single item size in bytes
/// @param list Pointer to LIST
/// @return single item size in bytes
ATSTDLIB_API U64 list_item_size(LIST *list);

/// @brief Removes element from the start of the list
/// @param list List where to delete from
/// @return ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_SUCCESS             -- Succesfully shifted
///         ERRCODE_FAILURE             -- Shifting from an empty list
ATSTDLIB_API ERR32 list_shift(LIST *list);

/// @brief Removes element from the end of the list
/// @param list List where to delete from
/// @return ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_SUCCESS             -- Succesfully popped
///         ERRCODE_FAILURE             -- Popping from an empty list
ATSTDLIB_API ERR32 list_pop(LIST *list);

/// @brief Returns unsigned value at index
/// @param list Pointer to LIST
/// @param index Index
/// @return Value at location. Will not check for overflow
ATSTDLIB_API U64 ulist_at_index(LIST *list, U64 index);

/// @brief Returns signed value at index
/// @param list Pointer to LIST
/// @param index Index
/// @return Value at location. Will not check for overflow
ATSTDLIB_API I64 ilist_at_index(LIST *list, U64 index);

/// @brief Replaces value of element at given index with unsigned value
/// @param list Pointer to LIST
/// @param index Index
/// @param value Value to replace with
/// @return ERRCODE_SUCCESS             -- Succesfully replaced
///         ERRCODE_FAILURE             -- Invalid index
///         ERRCODE_INVALID_VALUE_SIZE  -- Invalid size for element
ATSTDLIB_API ERR32 ureplace_value_at_index(LIST *list, U64 index, U64 value);


/// @brief Replaces value of element at given index with signed value
/// @param list Pointer to LIST
/// @param index Index
/// @param value Value to replace with
/// @return ERRCODE_SUCCESS             -- Succesfully replaced
///         ERRCODE_FAILURE             -- Invalid index
///         ERRCODE_INVALID_VALUE_SIZE  -- Invalid size for element
ATSTDLIB_API ERR32 ireplace_value_at_index(LIST *list, U64 index, I64 value);



/*+++
    BEHAVIOUR FOR TWO FOLLOWING FUNCTIONS:
    ADDING INSIDE CURRENT LIST LIMITS
    0.  32
    1.  64
    2.  128
    upush_value_to_index(&list, 1, 100)
    0.  32
    1.  100
    2.  64
    3.  128
    
    
    ADDING OUTSIDE CURRENT LIST LIMITS
    0.  32
    1.  64
    2.  128
    upush_value_to_index(&list, 5, 100)
    0.  32
    1.  64
    2.  128
    3.  0
    4.  0
    5.  100
---*/



/// @brief Pushes unsigned value to the index given. Values to the right of index will be pushed right
/// @param list Pointer to LIST
/// @param index Index where to insert.
/// @param value Value of new entry
/// @return ERRCODE_SUCCESS             -- Succesfully replaced
///         ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_INVALID_VALUE_SIZE  -- Invalid bit size for pushed item
ATSTDLIB_API ERR32 upush_value_to_index(LIST *list, U64 index, U64 value);

/// @brief Pushes signed value to the index given. Values to the right of index will be pushed right
/// @param list Pointer to LIST
/// @param index Index where to insert. NOTE: IF LARGER THAN LIST SIZE, NULLPTR ENTRIES WILL BE CREATED AS BUFFER
/// @param value Value of new entry
/// @return ERRCODE_SUCCESS             -- Succesfully replaced
///         ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_INVALID_VALUE_SIZE  -- Invalid bit size for pushed item
ATSTDLIB_API ERR32 ipush_value_to_index(LIST *list, U64 index, I64 value);

/// @brief Pop an element from given index.
/// @param list Pointer to LIST
/// @param index Index to pop
/// @return ERRCODE_SUCCESS             -- Succesfully popped
///         ERRCODE_MEMORY_ALLOCATION   -- Error with memory allocation.
///         ERRCODE_FAILURE             -- Invalid index
ATSTDLIB_API ERR32 pop_from_index(LIST *list, U64 index);
#endif //  ATSTDLIB_LIST_H
