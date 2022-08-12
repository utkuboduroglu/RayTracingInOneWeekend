#ifndef RTIN1WEEKEND_RAY_H
#define RTIN1WEEKEND_RAY_H

#include "vec_utils.h"
#include "color.h"

using arma::vec;

class ray {
public:
  point orig;
  vec   dir;

public:
  ray() {}
  ray(const point& origin, const vec& direction)
    : orig(origin), dir(direction) {}

  point origin() const {
    return orig;
  }

  vec direction() const {
    return dir;
  }

};

color ray_color(const ray& r) {
    vec unit_direction = arma::normalise(r.direction());
    auto t = 0.5*(unit_direction[1] + 1.0);
    return (1.0-t)*color {1.0, 1.0, 1.0} + t*color {0.5, 0.7, 1.0};
}

#endif // RTIN1WEEKEND_RAY_H
