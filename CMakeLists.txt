cmake_minimum_required(VERSION 3.17)
project(rtin1weekend)

set(CMAKE_CXX_STANDARD 17)

# I want some compiler flags
set(GCC_COVERAGE_COMPILER_FLAGS "-Wall -Wextra -Wpedantic -pedantic-errors -Weffc++ -g -Og")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILER_FLAGS}")

add_executable(rtin1weekend src/main.cpp src/vex.h src/color.h)