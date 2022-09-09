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

  point at(double t) const {
    return static_cast<point>(
        static_cast<vec>(orig) + t*dir
        );
  }

};

// todo: this exists in hit_calc.h, remove when tutorial progresses
// simple sphere collision check, computed by checking whether t is solvable in
// ||p(t) - c|| < r (through 2nd degree polynomial calc.)
// NOTE that instead of the actual discriminant calculation, we reparametrize to b = 2h
double hit_sphere(const point& center, double radius, const ray& r) {
  vec oc = r.origin() - center;

  double a = pow(arma::norm(r.direction()), 2.0);
  double half_b = arma::norm_dot(oc, r.direction());
  double c = pow(arma::norm(oc), 2.0) - pow(radius, 2.0);

  auto discriminant = pow(half_b, 2) - a*c;
  if (discriminant < 0) {
    return -1.0;
  } else {
    return (-half_b - sqrt(discriminant))/a;
  }
}

// the color arguments do not cost much, no need to make them const color&
color ray_color(const ray& r,
                color color1={1.0, 1.0, 1.0},
                color color2={0.5, 0.3, 1.0}) {
    auto t = hit_sphere({0,0,-1}, 0.5, r);
    if (t > 0.0) {
      vec N = arma::normalise(r.at(t) - vec{0, 0, -1});
      return 0.5*color{N[0]+1, N[1]+1, N[2]+1};
    }

    vec unit_direction = arma::normalise(r.direction());
    t = 0.5*(unit_direction[1] + 1.0);
    return (1.0-t)*color1 + t*color2;
}

#endif // RTIN1WEEKEND_RAY_H
