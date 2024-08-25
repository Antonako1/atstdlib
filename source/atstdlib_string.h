/*+++
    ATSTDLIB STRING HEADER - Antonako1
    
    Licensed under MIT
---*/

#ifndef ATSTDLIB_STRING_H
#define ATSTDLIB_STRING_H
#include <atstdlib_types.h>
#include <atstdlib_error.h>

/// @brief Returns length of null terminated string
/// @param str Input string
/// @return Length of string, not including null character
U64 ustrlen(const U8 *str);

/// @brief Returns length of wide, null terminated string
/// @param str Input string
/// @return Length of wide string, not including null character
U64 uwstrlen(const U16 *str);

/// @brief Returns length of null terminated string
/// @param str Input string
/// @param max_size If string input's length is past max_size, max_size is returned
/// @return Length of string, not including null character
U64 ustrnlen(const U8 *str, U64 max_size);

/// @brief Returns length of wide, null terminated string
/// @param str Input string
/// @param max_size If string input's length is past max_size, max_size is returned
/// @return Length of wide string, not including null character
U64 uwstrnlen(const U16 *str, U64 max_size);

/// @brief Returns length of null terminated string
/// @param str Input string
/// @param max_size If string input's length is past max_size, max_size is returned
/// @return Length of string, not including null character. 0 if str is null
U64 ustrnlen_s(const U8 *str, U64 max_size);

/// @brief Returns length of wide, null terminated string
/// @param str Input string
/// @param max_size If string input's length is past max_size, max_size is returned
/// @return Length of wide string, not including null character. 0 if str is null
U64 uwstrnlen_s(const U16 *str, U64 max_size);

/*
ustrcmp
uwstrcmp
ustrcmp_s
uwstrcmp_s

ustrcat
uwstrcat
ustrcat_s
uwstrcat_s

ustrncat
uwstrncat
ustrncat_s
uwstrncat_s

ustrcopy
uwstrcopy
ustrcopy_s
uwstrcopy_s

usubstr
uwsubstr
*/

#endif // ATSTDLIB_STRING_H