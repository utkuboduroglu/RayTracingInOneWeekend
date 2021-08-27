#ifndef RTIN1WEEKEND_PPM_WRITE_H
#define RTIN1WEEKEND_PPM_WRITE_H

#include <vector>
#include <cstdio>
#include <fstream>
#include <iostream>
// write data to specified file in ppm format

int ppmWrite(const std::vector<const int> imageShape, std::ostream& out=std::cout) {
    out << "P3\n" << imageShape.at(0) << ' ' << imageShape.at(1) << "\n255\n";

    for (int j = imageShape.at(1)-1; j >= 0; --j) {
        std::cerr << "Lines remaining: " << j << " \n";
        for (int i = 0; i < imageShape.at(0); ++i) {
            auto r = double(i) / (imageShape.at(0)-1);
            auto g = double(j) / (imageShape.at(1)-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            out << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    return imageShape.length();
}

#endif //RTIN1WEEKEND_PPM_WRITE_H
