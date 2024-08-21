/*+++
    ATSTDLIB EXTENDED TYPES HEADER- Antonako1
    
    Licensed under MIT



    {U|I}{128|192|256|512}
---*/
#ifndef ATSTDLIB_EXT_TYPES_H
#define ATSTDLIB_EXT_TYPES_H
#include <atstdlib_types.h>
    #define _128_PARTS 2
    typedef struct U128 {
        U64 parts[_128_PARTS];
    } U128;
    typedef struct I128 {
        I64 parts[_128_PARTS];
    } I128;

    #define _192_PARTS 3
    typedef struct U192 {
        U64 parts[_192_PARTS];
    } U192;
    typedef struct I192 {
        I64 parts[_192_PARTS];
    } I192;

    #define _256_PARTS 4
    typedef struct U256 {
        U64 parts[_256_PARTS];
    } U256;
    typedef struct I256 {
        I64 parts[_256_PARTS];
    } I256;

    #define _512_PARTS 8
    typedef struct U512 {
        U64 parts[_512_PARTS];
    } U512;
    typedef struct I512 {
        I64 parts[_512_PARTS];
    } I512;
#endif //  ATSTDLIB_EXT_TYPES_H