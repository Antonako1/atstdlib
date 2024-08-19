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

/*+++
    ATSTDLIB DEFINED TYPES
---*/
#ifdef ATSTDLIB_USE_TYPES
#   include <atstdlib_types.h>
#   include <atstdlib_strings.h>
#   ifdef ATSTDLIB_USE_EXTENDED_TYPES
#       include <atstdlib_ext_types.h>
#   endif // ATSTDLIB_USE_EXTENDED_TYPES

#   ifdef ATSTDLIB_USE_LINEAR_ALLOCATORS
#       include <atstdlib_linear_allocator.h>
#   endif // ATSTDLIB_USE_LINEAR_ALLOCATORS
#endif // ATSTDLIB_USE_TYPES



#if defined(ATSTDLIB_LINEAR_ALLOCATORS) && defined(ATSTDLIB_TYPES)
    
#endif // ATSTDLIB_LINEAR_ALLOCATORS


#endif // ATSTDLIB_H