#include <atstdlib_array.h>
#include <stdlib.h>
#include <atstdlib_memory.h>

ARRAY create_arr(U64 size_of_item_entry){
    ARRAY res;
    res.contents = NULLPTR;
    res.length = 0;
    res.item_entry_size = size_of_item_entry;
}


ERR32 uarr_push_back(ARRAY *arr, U64 value){
    U32 bit_count = 0;
    U64 temp = value;
    while (temp > 0) {
        bit_count++;
        temp >>= 1;
    }
    if((bit_count / 8) > arr->item_entry_size){
        return ERRCODE_INVALID_VALUE_SIZE;
    }
    // Reallocate size for arr->contents and add it as pointer, and malloc an entry for value and add it to the new realloc position
    // atstd_realloc();
    // malloc();
    arr->length++;
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

U64 arr_length(U0 **arr){

}