cmake_minimum_required(VERSION 3.10)

project(algorithms_practice VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS -std=c++11")

set(LIBNAME libalgopractice)

#########################################
# Unit tests

add_subdirectory(test/vendor)

enable_testing()

if(BUILD_TESTING)
    add_subdirectory(test)
endif()