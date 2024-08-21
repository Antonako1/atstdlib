#include <atstdlib_memory.h>
#include <stdlib.h>

U0 *atstd_realloc(U0 *block, U64 size){
    U64 *temp = realloc(block, (size_t)size);
    if (temp == NULLPTR) {
        return NULLPTR;
    }
    return temp;
}