#include <atstdlib_memory.h>
#include <stdlib.h>

ERR32 atstd_realloc(U0 *block, U64 size){
    U64 *temp = block;
    realloc(temp, size);
    if(temp == NULLPTR){
        return ERRCODE_FAILURE;
    }
    block = temp;
    return ERRCODE_SUCCESS;
}