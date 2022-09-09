#ifndef RTIN1WEEKEND_HIT_CALC_H
#define RTIN1WEEKEND_HIT_CALC_H

#include "ray.h"

// simple sphere collision check, computed by checking whether t is solvable in
// ||p(t) - c|| < r (through 2nd degree polynomial calc.)
bool hit_sphere(const point& center, double radius, const ray& r) {
  vec oc = r.origin() - center;

  double a = arma::norm(r.direction());
  double b = 2.0 * arma::norm_dot(oc, r.direction());
  double c = arma::norm(oc) - pow(radius, 2.0);

  auto discriminant = pow(b, 2) - 4*a*c;
  return discriminant > 0;
}

#endif // RTIN1WEEKEND_HIT_CALC_H
