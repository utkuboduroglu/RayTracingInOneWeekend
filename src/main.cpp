#include <iostream>
#include <fstream>

#include "color.h"

#define IMAGE_OUT "image-out/test.ppm"

int main() {
    const int image_width = 256, image_height = 256;
    std::ofstream ofile(IMAGE_OUT);

    // ppm file magic & header
    ofile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            Color::color pixel_color =
                    {double(i)/(image_width-1), double(j)/(image_height-1), 0.25};
            Color::write_color(ofile, pixel_color);
        }
    }

    std::cerr << "\nWrite done.\n";
    ofile.close();
    return EXIT_SUCCESS;
}
