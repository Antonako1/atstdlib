/*+++
    ATSTDLIB LIST C SOURCE - Antonako1
    
    Licensed under MIT
---*/
#include <atstdlib_list.h>
#include <stdlib.h>
#include <atstdlib_memory.h>

BOOLEAN bit_test(U64 value, U64 item_entry_size){
    U32 bit_count = 0;
    I64 temp = value;
    while (temp > 0) {
        bit_count++;
        temp >>= 1;
    }
    U32 byte_count = (bit_count + 7) / 8;
    if(byte_count > item_entry_size){
        return TRUE;
    }
    return FALSE;
}

LIST create_list(U64 size_of_item_entry){
    LIST res;
    res.contents = NULLPTR;
    res.length = 0;
    res.item_entry_size = size_of_item_entry;
    return res;
}


ERR32 ilist_push_back(LIST *list, I64 value){
    if(bit_test(value, list->item_entry_size)){
        return ERRCODE_INVALID_VALUE_SIZE;
    }
    U64 **new_contents = (U64**)atstd_realloc(list->contents, (list->length + 1) * sizeof(U64 *));
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    list->contents = new_contents;

    U64 *allocation = (U64*)malloc((size_t)(list->item_entry_size*8));
    if (allocation == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    *allocation = value;
    
    list->contents[list->length++] = allocation;
    return ERRCODE_SUCCESS;
}
ERR32 ulist_push_back(LIST *list, U64 value){
    if(bit_test(value, list->item_entry_size)){
        return ERRCODE_INVALID_VALUE_SIZE;
    }
    U64 **new_contents = (U64**)atstd_realloc(list->contents, (list->length + 1) * sizeof(U64 *));
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    list->contents = new_contents;

    U64 *allocation = (U64*)malloc((size_t)(list->item_entry_size*8));
    if (allocation == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    *allocation = value;
    
    list->contents[list->length++] = allocation;
    return ERRCODE_SUCCESS;
}

U0 list_free(LIST *list) {
    for (U64 i = 0; i < list->length; i++) {
        if (list->contents[i] != NULLPTR) {
            free(list->contents[i]);
            list->contents[i] = NULLPTR;
        }
    }
    free(list->contents);
    list->contents = NULLPTR;
    list->length = 0;
}

U64 list_length(LIST *list){
    return list->length;
}
U64 list_item_size(LIST *list){
    return list->item_entry_size;
}

ERR32 list_pop(LIST *list){
    if(list->length - 1 < 0){
        return ERRCODE_FAILURE;
    }
    free(list->contents[--list->length]);
    U64 **new_contents = (U64**)atstd_realloc(list->contents, (list->length) * sizeof(U64 *));
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    return ERRCODE_SUCCESS;
}
ERR32 list_shift(LIST *list){
    if(list->length - 1 < 0){
        return ERRCODE_FAILURE;
    }
    free(list->contents[0]);
    for (U64 i = 1; i < list->length; i++){
        list->contents[i-1] = list->contents[i];
    }
    U64 **new_contents = (U64**)atstd_realloc(list->contents, (--list->length) * sizeof(U64 *));
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    return ERRCODE_SUCCESS;
}

U64 ulist_at_index(LIST *list, U64 index){
    return *list->contents[index];
}

I64 ilist_at_index(LIST *list, U64 index){
    return *list->contents[index];
}

ERR32 ureplace_value_at_index(LIST *list, U64 index, U64 value){
    if(bit_test(value, list->item_entry_size)){
        return ERRCODE_INVALID_VALUE_SIZE;
    }
    if(index > list->length){
        return ERRCODE_FAILURE;
    }
    *list->contents[index] = value;
    return ERRCODE_SUCCESS;
}
ERR32 ireplace_value_at_index(LIST *list, U64 index, I64 value){
    if(bit_test(value, list->item_entry_size)){
        return ERRCODE_INVALID_VALUE_SIZE;
    }
    if(index > list->length){
        return ERRCODE_FAILURE;
    }
    *list->contents[index] = value;
    return ERRCODE_SUCCESS;
}

ERR32 upush_value_to_index(LIST *list, U64 index, U64 value) {
    if (bit_test(value, list->item_entry_size)) {
        return ERRCODE_INVALID_VALUE_SIZE;
    }
    U64 new_length = (index >= list->length) ? index + 1 : list->length + 1;
    U64 size = new_length * sizeof(U64 *);

    U64 **new_contents = (U64 **)atstd_realloc(list->contents, size);
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    list->contents = new_contents;

    if (index >= list->length) {
        for (U64 i = list->length; i < index; i++) {
            list->contents[i] = (U64 *)calloc(1, sizeof(U64));
            if (list->contents[i] == NULLPTR) {
                for (U64 j = list->length; j < i; j++) {
                    free(list->contents[j]);
                }
                list->length = index; // NOTE: not good?
                list->contents = (U64 **)atstd_realloc(list->contents, list->length * sizeof(U64 *));
                return ERRCODE_MEMORY_ALLOCATION;
            }
        }
        list->length = index + 1;
    } else {
        for (U64 i = list->length; i > index; i--) {
            list->contents[i] = list->contents[i - 1];
        }
        list->length++;
    }

    U64 *allocation = (U64 *)malloc(sizeof(U64));
    if (allocation == NULLPTR) {
        if (index < list->length - 1) {
            for (U64 i = index; i < list->length - 1; i++) {
                list->contents[i] = list->contents[i + 1];
            }
        }
        list->contents = (U64 **)atstd_realloc(list->contents, (--list->length) * sizeof(U64 *));
        return ERRCODE_MEMORY_ALLOCATION;
    }
    *allocation = value;
    list->contents[index] = allocation;

    return ERRCODE_SUCCESS;
}

ERR32 ipush_value_to_index(LIST *list, U64 index, I64 value) {
    if (bit_test(value, list->item_entry_size)) {
        return ERRCODE_INVALID_VALUE_SIZE;
    }
    U64 new_length = (index >= list->length) ? index + 1 : list->length + 1;
    U64 size = new_length * sizeof(U64 *);

    U64 **new_contents = (U64 **)atstd_realloc(list->contents, size);
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    list->contents = new_contents;

    if (index >= list->length) {
        for (U64 i = list->length; i < index; i++) {
            list->contents[i] = (U64 *)calloc(1, sizeof(U64));
            if (list->contents[i] == NULLPTR) {
                for (U64 j = list->length; j < i; j++) {
                    free(list->contents[j]);
                }
                list->length = index; // NOTE: not good?
                list->contents = (U64 **)atstd_realloc(list->contents, list->length * sizeof(U64 *));
                return ERRCODE_MEMORY_ALLOCATION;
            }
        }
        list->length = index + 1;
    } else {
        for (U64 i = list->length; i > index; i--) {
            list->contents[i] = list->contents[i - 1];
        }
        list->length++;
    }

    U64 *allocation = (U64 *)malloc(sizeof(U64));
    if (allocation == NULLPTR) {
        if (index < list->length - 1) {
            for (U64 i = index; i < list->length - 1; i++) {
                list->contents[i] = list->contents[i + 1];
            }
        }
        list->contents = (U64 **)atstd_realloc(list->contents, (--list->length) * sizeof(U64 *));
        return ERRCODE_MEMORY_ALLOCATION;
    }
    *allocation = value;
    list->contents[index] = allocation;
    return ERRCODE_SUCCESS;
}

ERR32 pop_from_index(LIST *list, U64 index){
    if(index > list->length){
        return ERRCODE_FAILURE;
    }
    free(list->contents[index]);
    for(U64 i = index; i < list->length; i++){
        list->contents[i] = list->contents[i+1];
    }
    U64 **new_contents = (U64 **)atstd_realloc(list->contents, (--list->length * sizeof(U64*)));
    if (new_contents == NULLPTR) {
        return ERRCODE_MEMORY_ALLOCATION;
    }
    list->contents = new_contents;
    return ERRCODE_SUCCESS;
}
