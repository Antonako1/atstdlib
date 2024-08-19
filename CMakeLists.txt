cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

if(USEDEBUG STREQUAL "1")
  set(DEBUG 1)
  SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()
message(STATUS "Debug status: ${DEBUG}")

set(project_name "atstdlib")

# Define the project
project(${project_name} LANGUAGES C)

# Add the shared library
add_library(${project_name} SHARED 
            "./source/atstdlib_api.h"
            "./source/atstdlib_ext_types.h"
            "./source/atstdlib_linear_allocator.h"
            "./source/atstdlib_strings.h"
            "./source/atstdlib_types.h"
            "./source/atstdlib.h"
            "./source/linear_allocation.c"
            "./source/strings.c"
)

# Ensure ATSTDLIB_EXPORTS is defined when building the DLL
target_compile_definitions(${project_name} PRIVATE ATSTDLIB_EXPORTS)

# Set output directory for the shared library
set_target_properties(${project_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")



# On errors, abort build
# Compiler-specific options
if (DEBUGGING__)
  if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${project_name} PRIVATE /WX /Zi)
  elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${project_name} PRIVATE -Werror -g)
  endif()
else()
  if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${project_name} PRIVATE /WX)
  elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${project_name} PRIVATE -Werror)
  endif()
endif()

# Set output directory based on OS
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  set_target_properties(${project_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/win")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set_target_properties(${project_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/linux")
endif()

# Enable debugging symbols for Release and Debug builds if DEBUGGING__ is TRUE
if (DEBUGGING__)
  if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  endif()
  add_compile_definitions(DEBUG)
endif()


# Add test executable
add_executable(test_exec "./test/test.c")

# Link the test executable with the shared library
target_link_libraries(test_exec PRIVATE ${project_name})

# Set output directory for the test executable
set_target_properties(test_exec PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test")
message("STATUS" "CXX: ${CMAKE_CXX_FLAGS}")