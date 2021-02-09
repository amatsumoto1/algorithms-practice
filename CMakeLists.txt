cmake_minimum_required(VERSION 3.10)

project(algorithms_practice VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(src)

#########################################
# Unit tests
enable_testing()
add_subdirectory(test)