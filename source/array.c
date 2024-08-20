#include <atstdlib_array.h>
#include <stdlib.h>
#include <atstdlib_memory.h>

ARRAY create_arr(U64 size_of_item_entry){
    ARRAY res;
    res.contents = NULLPTR;
    res.length = 0;
    res.item_entry_size = size_of_item_entry;
    return res;
}


ERR32 iarr_push_back(ARRAY *arr, I64 value){
    U32 bit_count = 0;
    I64 temp = value;
    while (temp > 0) {
        bit_count++;
        temp >>= 1;
    }
    U32 byte_count = (bit_count + 7) / 8;
    if(byte_count > arr->item_entry_size){
        return ERRCODE_INVALID_VALUE_SIZE;
    }
    U64 **new_contents = (U64**)atstd_realloc(arr->contents, (arr->length + 1) * sizeof(U64 *));
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    arr->contents = new_contents;

    U64 *allocation = (U64*)malloc((size_t)(arr->item_entry_size*8));
    if (allocation == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    *allocation = value;
    
    arr->contents[arr->length++] = allocation;
    return ERRCODE_SUCCESS;
}
ERR32 uarr_push_back(ARRAY *arr, U64 value){
    U32 bit_count = 0;
    U64 temp = value;
    while (temp > 0) {
        bit_count++;
        temp >>= 1;
    }
    U32 byte_count = (bit_count + 7) / 8;
    if(byte_count > arr->item_entry_size){
        return ERRCODE_INVALID_VALUE_SIZE;
    }
    U64 **new_contents = (U64**)atstd_realloc(arr->contents, (arr->length + 1) * sizeof(U64 *));
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    arr->contents = new_contents;

    U64 *allocation = (U64*)malloc((size_t)(arr->item_entry_size*8));
    if (allocation == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    *allocation = value;
    
    arr->contents[arr->length++] = allocation;
    return ERRCODE_SUCCESS;
}

U0 arr_free(ARRAY *arr) {
    for (U64 i = 0; i < arr->length; i++) {
        if (arr->contents[i] != NULLPTR) {
            free(arr->contents[i]);
        }
    }
    free(arr->contents);
    arr->contents = NULLPTR;
    arr->length = 0;
}

U64 arr_length(ARRAY *arr){
    return arr->length;
}
U64 arr_item_size(ARRAY *arr){
    return arr->item_entry_size;
}

ERR32 arr_pop(ARRAY *arr){
    if(arr->length - 1 < 0){
        return ERRCODE_FAILURE;
    }
    free(arr->contents[--arr->length]);
    U64 **new_contents = (U64**)atstd_realloc(arr->contents, (arr->length) * sizeof(U64 *));
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    return ERRCODE_SUCCESS;
}
ERR32 arr_shift(ARRAY *arr){
    if(arr->length - 1 < 0){
        return ERRCODE_FAILURE;
    }
    free(arr->contents[0]);
    for (U64 i = 1; i < arr->length; i++){
        arr->contents[i-1] = arr->contents[i];
    }
    U64 **new_contents = (U64**)atstd_realloc(arr->contents, (--arr->length) * sizeof(U64 *));
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    return ERRCODE_SUCCESS;
}

U64 uarr_at_index(ARRAY *arr, U64 index){
    return *arr->contents[index];
}

I64 iarr_at_index(ARRAY *arr, U64 index){
    return *arr->contents[index];
}

ERR32 ureplace_value_at_index(ARRAY *arr, U64 index, U64 value){
    if(index > arr->length){
        return ERRCODE_FAILURE;
    }
    *arr->contents[index] = value;
    return ERRCODE_SUCCESS;
}
ERR32 ireplace_value_at_index(ARRAY *arr, U64 index, I64 value){
    if(index > arr->length){
        return ERRCODE_FAILURE;
    }
    *arr->contents[index] = value;
    return ERRCODE_SUCCESS;
}

ERR32 upush_value_to_index(ARRAY *arr, U64 index, I64 value){
    
    
    return ERRCODE_SUCCESS;
}