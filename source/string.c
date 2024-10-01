/*+++
    ATSTDLIB STRING C SOURCE - Antonako1
    
    Licensed under MIT
---*/
#include <atstdlib_string.h>

#define ret return

U64 ustrlen(const U8 *str){
    U64 cnt = 0;
    while(str[cnt++] != '\0');
    ret --cnt;
}
U64 uwstrlen(const U16 *str){
    U64 cnt = 0;
    while(str[cnt++] != '\0');
    ret --cnt;
}

U64 ustrlen_s(const U8 *str){
    if(str == NULLPTR) return 0;
    U64 cnt = 0;
    while(str[cnt++] != '\0');
    ret --cnt;
}
U64 uwstrlen_s(const U16 *str){
    if(str == NULLPTR) return 0;
    U64 cnt = 0;
    while(str[cnt++] != '\0');
    ret --cnt;
}

U64 ustrnlen(const U8 *str, U64 max_size){
    if(max_size == 0 || max_size > URSIZE_MAX) return ERRCODE_FAILURE;
    U64 cnt = 0;
    while(str[cnt++] != '\0')
        if(cnt >= max_size) {
            cnt++; break;
        }
    ret --cnt;
}
U64 uwstrnlen(const U16 *str, U64 max_size){
    if(max_size == 0 || max_size > URSIZE_MAX) return ERRCODE_FAILURE;
    U64 cnt = 0;
    while(str[cnt++] != '\0')
        if(cnt >= max_size) {
            cnt++; break;
        }
    ret --cnt;
}

U64 ustrnlen_s(const U8 *str, U64 max_size){
    if(max_size == 0 || max_size > URSIZE_MAX) return ERRCODE_FAILURE;
    if(str == NULLPTR) return 0;
    U64 cnt = 0;
    while(str[cnt++] != '\0')
        if(cnt >= max_size) {
            cnt++; break;
        }
    ret --cnt;
}
U64 uwstrnlen_s(const U16 *str, U64 max_size){
    if(max_size == 0 || max_size > URSIZE_MAX) return ERRCODE_FAILURE;
    if(str == NULLPTR) return 0;
    U64 cnt = 0;
    while(str[cnt++] != '\0')
        if(cnt >= max_size) {
            cnt++; break;
        }
    ret --cnt;
}


// U8 *ustrcat(U8 *dest, U8 *src){

// }
// U16 *uwstrcat(U16 *dest, U16 *src){
// }
// ERR32 ustrcat_s(U8 *dest, U64 dstsz, U8 *src){
//     if(dstsz == 0 || dstsz > URSIZE_MAX) return ERRCODE_FAILURE;
//     if(dest == NULLPTR || src == NULLPTR) return ERRCODE_FAILURE;
//     if(ustrnlen_s(dest, dstsz) + ustrnlen_s(src, dstsz) > dstsz) return ERRCODE_FAILURE;
// }
// ERR32 uwstrcat_s(U16 *dest, U64 dstsz, U16 *src){}

