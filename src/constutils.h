#ifndef RTIN1WEEKEND_CONSTUTILS_H
#define RTIN1WEEKEND_CONSTUTILS_H

#include <cmath>
#include <limits>
#include <memory>

#include <cstdlib>

using std::shared_ptr, std::make_shared, std::sqrt;

const double infinity   = std::numeric_limits<double>::infinity();
const double pi         = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

#endif //RTIN1WEEKEND_CONSTUTILS_H
