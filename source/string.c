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

U64 ustrnlen(const U8 *str, U64 max_size){
    U64 cnt = 0;
    while(str[cnt++] != '\0')
        if(cnt >= max_size) {
            cnt++; break;
        }
    ret --cnt;
}
U64 uwstrnlen(const U16 *str, U64 max_size){
    U64 cnt = 0;
    while(str[cnt++] != '\0')
        if(cnt >= max_size) {
            cnt++; break;
        }
    ret --cnt;
}

U64 ustrnlen_s(const U8 *str, U64 max_size){
    if(str == NULLPTR) return 0;
    U64 cnt = 0;
    while(str[cnt++] != '\0')
        if(cnt >= max_size) {
            cnt++; break;
        }
    ret --cnt;
}
U64 uwstrnlen_s(const U16 *str, U64 max_size){
    if(str == NULLPTR) return 0;
    U64 cnt = 0;
    while(str[cnt++] != '\0')
        if(cnt >= max_size) {
            cnt++; break;
        }
    ret --cnt;
}


#include <string.h>
// strcat
