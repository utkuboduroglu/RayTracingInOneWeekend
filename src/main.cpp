#include <iostream>

#define ARMA_DONT_USE_WRAPPER
#include <armadillo>

using arma::vec;

#include "color.h"
#include "vec_utils.h"
#include "ray.h"

int main()
{
  // Image
  const auto aspect_ratio = 16.0 / 9.0;
  const int image_width = 640;
  const int image_height = static_cast<int>(image_width / aspect_ratio);

  // Camera

  auto viewport_height = 2.0;
  auto viewport_width = aspect_ratio * viewport_height;
  auto focal_length = 1.0;

  auto origin = point{0, 0, 0};
  auto horizontal = vec::fixed<3> {viewport_width, 0, 0};
  auto vertical = vec::fixed<3> {0, viewport_height, 0};
  // if vec::fixed<3> is not used, the auto type becomes eGlue (?), which blows up
  auto lower_left_corner = vec::fixed<3>(origin - horizontal/2 - vertical/2 - vec::fixed<3> {0, 0, focal_length});

  // ppm file header
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  // we allocate ray here and assign uv-vectors later
  ray _ray {origin, origin};

  for (int j = image_height-1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      // canvas space uv coordinates
      auto u = double(i) / (image_width-1);
      auto v = double(j) / (image_height-1);

      _ray.dir = lower_left_corner + u*horizontal + v*vertical - origin;

      color pixel_color = ray_color(_ray);
      write_color(std::cout, pixel_color);
    }
  }

  std::cerr << "\nRender loop complete.\n";

  return 0;
}