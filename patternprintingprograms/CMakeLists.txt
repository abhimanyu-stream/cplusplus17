cmake_minimum_required(VERSION 3.20)

# Project information
project(TRIANGLE VERSION 0.1.0 LANGUAGES C CXX)

# Include testing support
include(CTest)
enable_testing()


set(SOURCES

    Triangle.cpp
    Main.cpp
)

set(HEADERS
    Triangle.h

)
# Add executable target
add_executable(TRIANGLE Triangle.cpp Main.cpp)

