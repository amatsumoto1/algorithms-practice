cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(
    algorithm_practice
    STATIC
        Stub.cpp
)

target_include_directories(
    algorithm_practice
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include/data_structures
)