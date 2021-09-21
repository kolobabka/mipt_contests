cmake_minimum_required (VERSION 3.16)        # VERSION

project (2Q_Cache VERSION 1.0.0)             # PROJECT TITLE

set (SOURCES main.cpp)                       # SOURCES *.cpp
set (HEADERS cache.hpp)                      # HEADERS *.hpp

set (COMPILER_SETTINGS -Wall -Wextra -O2)    # COMPILER SETTINGS

add_compile_options (${COMPILER_SETTINGS})
add_executable (cache ${SOURCES})  