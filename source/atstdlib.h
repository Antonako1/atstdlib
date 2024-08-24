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
#define ATSTDLIB_USE_EXTENDED_TYPES     1   // CHAINED TO ATSTDLIB_TYPES
#define ATSTDLIB_USE_LINEAR_ALLOCATORS  1   // CHAINED TO ATSTDLIB_TYPES
#define ATSTDLIB_USE_DYNAMIC_LISTS      1   // CHAINED TO ATSTDLIB_TYPES
#define ATSTDLIB_USE_CRYPTOLOGY         1   // CHAINED TO ATSTDLIB_TYPES
#define ATSTDLIB_USE_REGEX              1   // CHAINED TO ATSTDLIB_TYPES
#define ATSTDLIB_USE_STRING             1   // CHAINED TO ATSTDLIB_TYPES


#include <atstdlib_error.h>
#ifdef ATSTDLIB_USE_TYPES
#   include <atstdlib_types.h>

#   ifdef ATSTDLIB_USE_CRYPTOLOGY
#       include <atstdlib_crypt.h>
#   endif // ATSTDLIB_USE_CRYPTOLOGY

#   ifdef ATSTDLIB_USE_EXTENDED_TYPES
#       include <atstdlib_ext_types.h>
#   endif // ATSTDLIB_USE_EXTENDED_TYPES

#   ifdef ATSTDLIB_USE_LINEAR_ALLOCATORS
#       include <atstdlib_linear_allocator.h>
#   endif // ATSTDLIB_USE_LINEAR_ALLOCATORS

#   ifdef ATSTDLIB_USE_DYNAMIC_LISTS
#       include <atstdlib_list.h>
#   endif // ATSTDLIB_USE_DYNAMIC_LISTS

#   ifdef ATSTDLIB_USE_REGEX
#       include <atstdlib_regex.h>
#   endif // ATSTDLIB_USE_REGEX

#   ifdef ATSTDLIB_USE_STRING
#       include <atstdlib_string.h>
#   endif // ATSTDLIB_USE_STRING

#endif // ATSTDLIB_USE_TYPES
#endif // ATSTDLIB_H