cmake_minimum_required(VERSION 3.29)
project(SortingAlgorithms)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)


set(FETCHCONTENT_QUIET OFF)
set(BUILD_EXAMPLES OFF) # wyłącz przykłady raylib
FetchContent_MakeAvailable(raylib)

add_executable(SortingAlgorithms
        main.cpp
        cpp_files/sorting_algorithms.cpp
        headers/sorting_algorithms.h
        cpp_files/file_operations.cpp
        headers/file_operations.h
        cpp_files/visuals.cpp
        headers/visuals.h
        cpp_files/tools.cpp
        headers/tools.h
        cpp_files/tools.cpp
)
target_link_libraries(SortingAlgorithms raylib)