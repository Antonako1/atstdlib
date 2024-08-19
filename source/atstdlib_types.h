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



/*+++
FLOAT DEFINITIONS
---*/
typedef float               F32;
typedef double              F64;
typedef long double         F80;



/*+++
STRING DEFINITIONS
---*/
typedef struct STRING {
    U8 *buf;
    U64 length;
} STRING;

typedef struct WSTRING {
    U16 *buf;
    U64 length;
} WSTRING;



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

#define F32_MAX              1.7976931348623158e+308
#define F64_MAX              3.402823466e+38F
#define F80_MAX              F64_MAX
#endif // ATSTDLIB_TYPES_H