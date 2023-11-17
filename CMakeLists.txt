cmake_minimum_required(VERSION 3.26)
project(newFastNCD)

set(CMAKE_CXX_STANDARD 17)

add_library(newFastNCD SHARED fast_ncd.cpp
        fast_ncd_test.cpp)
