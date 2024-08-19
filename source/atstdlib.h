#ifndef ATSTDLIB_H
#define ATSTDLIB_H

#if defined(_WIN64) || defined(_WIN32)
    #ifdef ATSTDLIB_EXPORTS
    #  define ATSTDLIB_API __declspec(dllexport)
    #else
    #  define ATSTDLIB_API __declspec(dllimport)
    #endif
#else
    #define ATSTDLIB_API
#endif

/*+++
    Macro definitions.
    Use 1/0 to enable/disable
---*/
#define ATSTDLIB_TYPES              1
#define ATSTDLIB_EXTENDED_TYPES     1 // CHAINED TO ATSTDLIB_TYPES
#define ATSTDLIB_LINEAR_ALLOCATORS  1 // CHAINED TO ATSTDLIB_TYPES

/*+++
ATSTDLIB DEFINED TYPES
---*/
#ifdef ATSTDLIB_TYPES
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
#   define I8_MIN               (-127i8 - 1)
#   define I16_MIN              (-32767i16 - 1)
#   define I32_MIN              (-2147483647i32 - 1)
#   define I64_MIN              (-9223372036854775807i64 - 1)

#   define I8_MAX               127i8
#   define I16_MAX              32767i16
#   define I32_MAX              2147483647i32
#   define I64_MAX              9223372036854775807i64

#   define U8_MAX               0xffui8             
#   define U16_MAX              0xffffui16
#   define U32_MAX              0xffffffffui32
#   define U64_MAX              0xffffffffffffffffui64

#   define F32_MAX              1.7976931348623158e+308
#   define F64_MAX              3.402823466e+38F
#   define F80_MAX              F64_MAX



    /*+++
    EXTENDED TYPES
    {U|I}{128|192|256|512}
    ---*/
#   ifdef ATSTDLIB_EXTENDED_TYPES
        typedef struct U128 {
            U64 part[2];
        } U128;
        typedef struct I128 {
            I64 part[2];
        } I128;

        typedef struct U192 {
            U64 part[3];
        } U192;
        typedef struct I192 {
            I64 part[3];
        } I192;

        typedef struct U256 {
            U64 part[4];
        } U256;
        typedef struct I256 {
            I64 part[4];
        } I256;

        typedef struct U512 {
            U64 part[4];
        } U512;
        typedef struct I512 {
            I64 part[4];
        } I512;
#   endif // ATSTDLIB_EXTENDED_TYPES
#endif // ATSTDLIB_TYPES


/*+++
ATSTDLIB LINEAR ALLOCATOR
---*/
#if defined(ATSTDLIB_LINEAR_ALLOCATORS) && defined(ATSTDLIB_TYPES)
    typedef struct LINEAR_ALLOCATOR {
        U0 *home_pointer;       // Pointer to start of linear allocator
        U0 *current_endpoint;        // Pointer to the end of the memory stack
        U64 memory_size;        // Memory size
    } LINEAR_ALLOCATOR;

    /// @brief Creates a new linear allocator
    /// @param home_pointer Start of the linear allocator stack. End pointer will use the same
    /// @param memory_size  Size of the memory allocation
    /// @return Linear allocator with initialized with given values
    ATSTDLIB_API LINEAR_ALLOCATOR create_linear_allocator(U0 *home_pointer, U64 memory_size);

    /// @brief                      Allocate memory to linear allocator
    /// @param size                 Memory amount to allocate
    /// @param linear_allocator     Pointer to Linear Allocator
    /// @return                     Pointer to mallocated type. NULLPTR on failure
    ATSTDLIB_API U0 *linear_allocation(U64 size, LINEAR_ALLOCATOR *linear_allocator);

    /// @brief Moves Linear allocator's endpoint pointer to home. Zeroes memory
    /// @param linear_allocator Pointer to linear allocator
    ATSTDLIB_API U0 reset_linear_memory(LINEAR_ALLOCATOR *linear_allocator);

    /// @brief Use if linear memory is heap allocated and needs to be freed. Freeing home pointer will also work
    /// @param linear_allocator pointer to linear allocator 
    ATSTDLIB_API U0 free_linear_memory(LINEAR_ALLOCATOR *linear_allocator);
#endif // ATSTDLIB_LINEAR_ALLOCATORS


#endif // ATSTDLIB_H