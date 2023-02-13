cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

project(tiny_reflect CXX)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_executable(reflect ${srcs} src/main.cpp)

target_compile_options(reflect
    # Diagnose
    PUBLIC -Wall
    # Debug
    PUBLIC -O0
    PUBLIC -ggdb
)

target_include_directories(reflect PUBLIC include)


