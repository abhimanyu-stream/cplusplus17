cmake_minimum_required(VERSION 3.20)
project(SingleLinkedList VERSION 1.0.0)

# Include testing support
include(CTest)
enable_testing()


set(SOURCES
    SingleLinkedList.cpp
    Main.cpp
)

set(HEADERS
    SingleLinkedList.h
)
# Add executable target
add_executable(SingleLinkedList SingleLinkedList.cpp Main.cpp)

# Set C++ standard

