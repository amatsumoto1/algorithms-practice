cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(vendor)

add_executable(
    tests
    tests.cpp
    data_structures/LinkedListTest.cpp
    data_structures/DoublyLinkedListTest.cpp
)

target_include_directories(
    tests
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include/data_structures
    ${gtest_SOURCE_DIR}/include
)

target_link_libraries(
    tests
    gtest_main
)

add_test(NAME test_all COMMAND tests)