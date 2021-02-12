#ifndef RTIN1WEEKEND_COLOR_H
#define RTIN1WEEKEND_COLOR_H

#include "vex.h"
#include <fstream>

namespace Color {
    using color = Vec<3>;

    std::ofstream& write_color(std::ofstream& out,
                               color pixel_color) {
        out << static_cast<int>(255.99 * pixel_color.at(0)) << ' '
            << static_cast<int>(255.99 * pixel_color.at(1)) << ' '
            << static_cast<int>(255.99 * pixel_color.at(2)) << '\n';
        return out;
    }
}

#endif //RTIN1WEEKEND_COLOR_H
