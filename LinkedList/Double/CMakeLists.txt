cmake_minimum_required(VERSION 3.20)
project(DoubleLinkedList VERSION 1.0.0)

# Include testing support
include(CTest)
enable_testing()


set(SOURCES
    DoubleLinkedList.cpp
    Main.cpp
)

set(HEADERS
    DoubleLinkedList.h
)
# Add executable target
add_executable(DoubleLinkedList DoubleLinkedList.cpp Main.cpp)

# Set C++ standard

