# ATSTDLIB for C. 

## Features

 - atstdlib.h
    - Holds all header files
 - atstdlib_linear_allocator.h
    - Linear allocator
 - atstdlib_list.h
    - Dynamic lists. Like vectors, but memory isn't allocated in one big chunk.
 - atstdlib_crypt.h
    - Random number generator
    - 256-bit key generator
 - atstdlib_regex.h
   - Basic regex.
 - atstdlib_string.h
   - String functions and cross-platform safe functions
 - atstdlib_types.h & atstdlib_ext_types.h
    -   | ATSTDLIB_TYPE | C |
        |-|-|
        |NULLPTR|NULL|
        |U0|void|
        |BOOLEAN|bool|
        |TRUE|true|
        |FALSE|false|
        |<U OR I>8|<unsigned OR signed> char|
        |<U OR I>16|<unsigned OR signed> short|
        |<U OR I>32|<unsigned OR signed> int|
        |<U OR I>64|<unsigned OR signed> long long|
        |F32|float|
        |F64|double|
        |F80|long double|
        |-|-|
        |ATSTDLIB_EXT_TYPE|C|
        |<U OR I>128|<unsigned OR signed> long long[2]|
        |<U OR I>192|<unsigned OR signed> long long[3]|
        |<U OR I>256|<unsigned OR signed> long long[4]|
        |<U OR I>512|<unsigned OR signed> long long[8]|

## Usage with CMake
```shell
# Include headers
include_directories("./atstdlib/include")

# Link the test executable with the shared library
target_link_libraries(project_name PRIVATE atstdlib)
```

## Build and run

    NOTE: See .\<win|linux>\<scripts>\globals.<bat|sh>. Enter your paths there, or the executable programs if they are found in the path

    build project:
    .\<win|linux>\build.<bat|sh>

    run project:
    .\<win|linux>\run.<bat|sh> [args...]

    build and run the project:
    .\build_n_run.<bat|sh> [args...]

    clear build:
    .\<win|linux>\<scripts>\del.<bat|sh>
