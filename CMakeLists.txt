cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(RustVsCpp LANGUAGES CXX)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

if(MSVC)
  add_compile_options(PRIVATE /W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

add_subdirectory(iterator-invalidation-cpp)
add_subdirectory(uninitialized-cpp)
