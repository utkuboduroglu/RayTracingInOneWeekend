#include <iostream>
#include <fstream>

#include "color.h"
#include "ray.h"
#include "vec3.h"

#define IMAGE_OUT "image-out/test.ppm"

using std::cout, std::cerr, std::cin;

int main() {
    // Image settings
    const auto aspect_ratio = 16.0 / 9.0;
    const int   image_width = 400,
                image_height = static_cast<int>(image_width / aspect_ratio);

    std::ofstream outfile(IMAGE_OUT);
    outfile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Camera settings
    auto    viewport_height = 2.0,
            viewport_width = aspect_ratio * viewport_height,
            focal_length = 1.0;

    auto    origin = point3(0,0,0);
    auto    horizontal = vec3(viewport_width, 0, 0),
            vertical = vec3(0, viewport_height, 0);
    auto    lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    // render loop
    for (int j = image_height-1; j >= 0; --j) {
        cerr << "Lines remaining: " << j << " \n";
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i)/(image_width - 1);
            auto v = double(j)/(image_height - 1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            auto pixel_color = ray_color(r);
            outfile << pixel_color << '\n';
        }
    }

    outfile.close();
    return EXIT_SUCCESS;
}
