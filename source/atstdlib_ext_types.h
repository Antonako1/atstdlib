/*+++
    ATSTDLIB EXTENDED TYPES HEADER- Antonako1
    
    Licensed under MIT



    {U|I}{128|192|256|512}
---*/
#ifndef ATSTDLIB_EXT_TYPES_H
#define ATSTDLIB_EXT_TYPES_H
#include <atstdlib_types.h>
    typedef struct U128 {
        U64 parts[2];
    } U128;
    typedef struct I128 {
        I64 parts[2];
    } I128;

    typedef struct U192 {
        U64 parts[3];
    } U192;
    typedef struct I192 {
        I64 parts[3];
    } I192;

    typedef struct U256 {
        U64 parts[4];
    } U256;
    typedef struct I256 {
        I64 parts[4];
    } I256;

    typedef struct U512 {
        U64 parts[8];
    } U512;
    typedef struct I512 {
        I64 parts[8];
    } I512;
#endif //  ATSTDLIB_EXT_TYPES_H