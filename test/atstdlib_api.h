/*+++
    ATSTDLIB API HEADER - Antonako1
    
    Licensed under MIT
---*/
#ifndef ATSTDLIB_API_H
#define ATSTDLIB_API_H
#   if defined(_WIN64) || defined(_WIN32)
#       ifdef ATSTDLIB_EXPORTS
#           define ATSTDLIB_API __declspec(dllexport)
#       else
#           define ATSTDLIB_API __declspec(dllimport)
#       endif
#   else
#       define ATSTDLIB_API
#   endif
#endif // ATSTDLIB_API_H