cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(vendor)

add_executable(
    tests
    tests.cpp
    data_structures/LinkedListTest.cpp
)

target_include_directories(
    tests
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

add_test(NAME test_all COMMAND tests)