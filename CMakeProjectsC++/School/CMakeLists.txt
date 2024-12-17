cmake_minimum_required(VERSION 3.31.2)

# Project information
project(MyCMakeProject VERSION 0.1.0 LANGUAGES C CXX)

# Include testing support
include(CTest)
enable_testing()


set(SOURCES
    Student.cpp
    Main.cpp
)

set(HEADERS
    Student.h
)
# Add executable target
add_executable(MyCMakeProject Student.cpp Main.cpp)

# Set C++ standard
set_property(TARGET MyCMakeProject PROPERTY CXX_STANDARD 17)

# Notes:
# - To use CMake presets, refer to your CMakePresets.json file.
# - Presets allow grouping of settings and can be OS-specific.
# - They make it easier to share configurations and integrate with CI systems.


# reload vscode [ ctrl + p, then > reload window]
# now you can see CMAKE icon on activity left side bar
# now ctrl + p [>target   CMake:Set Build Target]
