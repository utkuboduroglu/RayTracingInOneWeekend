# Ray Tracing in One Weekend
This is my repository for hosting my work on [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html).

## Notes
* The plan is to replicate the code as is at first; then add optimizations and refactors to make it more C++20 compliant.
  - Additionally, we plan to introduce other libraries like Boost as a practice.
* We will add OpenGL to the project so that we can create a supported raytracer directly rendering our images.
* If relevant, we will also port code to OpenCL to utilize our GPU etc.
* Finally, if we finish with C++, we will also port the basic code into Rust.

## Issues
* Windows has issues building Boost; use the tutorial `vec3.h` until possible to build.
