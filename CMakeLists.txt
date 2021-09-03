cmake_minimum_required(VERSION 3.17)
project(rtin1weekend)

set(CMAKE_CXX_STANDARD 17)

# I want some compiler flags
set(GCC_COVERAGE_COMPILER_FLAGS "-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Weffc++ -g -Og")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILER_FLAGS}")

set(SOURCE_FILES src/main.cpp)

add_executable(rtin1weekend src/main.cpp src/ppm_write.h src/vec3.h src/color.h src/ray.h src/hittable.h src/sphere.h src/hittable_list.h src/constutils.h)