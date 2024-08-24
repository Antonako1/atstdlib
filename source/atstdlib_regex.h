/*+++
    ATSTDLIB REGEX HEADER - Antonako1
    
    Licensed under MIT
---*/
#ifndef ATSTDLIB_REGEX_H
#define ATSTDLIB_REGEX_H
#include <atstdlib_types.h>
#include <atstdlib_error.h>
/*+++
    Basic regex library.
    
    Same algorithm as in grep.
    Syntax should be similar to grep.
---*/

/// @brief Checks if given input string is valid for regex
/// @param regex_str Regex to check against string
/// @param input_str String to check against regex
/// @return TRUE if string is valid for regex, FALSE otherwise
BOOLEAN check_str_against_regex(U8 *regex_str, U8 *input_str);


#endif // ATSTDLIB_REGEX_H