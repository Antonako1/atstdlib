/*+++
    ATSTDLIB HEADER - Antonako1
    
    Licensed under MIT
---*/
#ifndef ATSTDLIB_H
#define ATSTDLIB_H
/*+++
    Macro definitions.
    Use 1/0 to enable/disable
---*/
#define ATSTDLIB_USE_TYPES              1
#define ATSTDLIB_USE_EXTENDED_TYPES     1 // CHAINED TO ATSTDLIB_TYPES
#define ATSTDLIB_USE_LINEAR_ALLOCATORS  1 // CHAINED TO ATSTDLIB_TYPES
#define ATSTDLIB_DYNAMIC_ARRAYS         1 // CHAINED TO ATSTDLIB_TYPES

#include <atstdlib_error.h>

/*+++
    ATSTDLIB DEFINED TYPES
---*/
#ifdef ATSTDLIB_USE_TYPES
#   include <atstdlib_types.h>
#   ifdef ATSTDLIB_USE_EXTENDED_TYPES
#       include <atstdlib_ext_types.h>
#   endif // ATSTDLIB_USE_EXTENDED_TYPES

#   ifdef ATSTDLIB_USE_LINEAR_ALLOCATORS
#       include <atstdlib_linear_allocator.h>
#   endif // ATSTDLIB_USE_LINEAR_ALLOCATORS

#   ifdef ATSTDLIB_DYNAMIC_ARRAYS
#       include <atstdlib_array.h>
#   endif
#endif // ATSTDLIB_USE_TYPES




#endif // ATSTDLIB_H