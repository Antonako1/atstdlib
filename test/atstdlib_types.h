/*+++
    ATSTDLIB_TYPES_H HEADER - Antonako1
    
    Licensed under MIT
---*/
#ifndef ATSTDLIB_TYPES_H
#define ATSTDLIB_TYPES_H



typedef void                U0;



/*+++
INTEGER DEFINITIONS
---*/
typedef unsigned char       U8;
typedef unsigned short      U16;
typedef unsigned int        U32;
typedef unsigned long long  U64;

typedef signed char         I8;
typedef signed short        I16;
typedef signed int          I32;
typedef signed long long    I64;

#define U8_BITS             8
#define U16_BITS            16
#define U32_BITS            32
#define U64_BITS            64

#define I8_BITS             8
#define I16_BITS            16
#define I32_BITS            32
#define I64_BITS            64

#define U8_BYTES            1
#define U16_BYTES           2
#define U32_BYTES           4
#define U64_BYTES           8

#define I8_BYTES            1
#define I16_BYTES           2
#define I32_BYTES           4
#define I64_BYTES           8



/*+++
FLOAT DEFINITIONS
---*/
typedef float               F32;
typedef double              F64;
typedef long double         F80;



/*+++
BOOLEAN DEFINITIONS
---*/
#define BOOLEAN _Bool
#define TRUE    1
#define FALSE   0



/*+++
OTHER DEFINITIONS
---*/
#define NULLPTR ((void *)0)



/*+++
MAX AND MIN DEFINITIONS
---*/
#define I8_MIN               (-127i8 - 1)
#define I16_MIN              (-32767i16 - 1)
#define I32_MIN              (-2147483647i32 - 1)
#define I64_MIN              (-9223372036854775807i64 - 1)

#define I8_MAX               127i8
#define I16_MAX              32767i16
#define I32_MAX              2147483647i32
#define I64_MAX              9223372036854775807i64

#define U8_MAX               0xffui8             
#define U16_MAX              0xffffui16
#define U32_MAX              0xffffffffui32
#define U64_MAX              0xffffffffffffffffui64

#define F32_MIN              1.175494351e-38F
#define F64_MIN              2.2250738585072014e-308
#define F80_MIN              F64_MIN

#define F32_MAX              3.402823466e+38F
#define F64_MAX              1.7976931348623158e+308
#define F80_MAX              F64_MAX



#endif // ATSTDLIB_TYPES_H