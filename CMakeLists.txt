cmake_minimum_required(VERSION 3.26)
project(newFastNCD)

set(CMAKE_CXX_STANDARD 17)

# Separate the source files and header files
set(SOURCE_FILES fast_ncd.cpp)
set(HEADER_FILES fast_ncd.h)

# Specify the output directory for the compiled libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(newFastNCD SHARED ${SOURCE_FILES} ${HEADER_FILES})

# Enable testing
enable_testing()

# Add the test files
add_executable(newFastNCD_test fast_ncd_test.cpp)
target_link_libraries(newFastNCD_test newFastNCD)

add_test(NAME newFastNCD_test COMMAND newFastNCD_test)
