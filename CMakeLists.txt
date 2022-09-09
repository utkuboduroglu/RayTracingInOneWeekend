cmake_minimum_required(VERSION 3.17)
project(rtin1weekend)

set(CMAKE_CXX_STANDARD 17)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

# I want some compiler flags
set(GCC_COVERAGE_COMPILER_FLAGS "-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Weffc++ -ggdb -O2")
set(GCC_COVERAGE_LINK_FLAGS "-lblas -llapack")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILER_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

set(SOURCE_FILES src/main.cpp src/vec_utils.h src/color.h)

add_executable(rtin1weekend src/main.cpp src/ray.h src/hit_calc.h)
