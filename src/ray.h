#ifndef RTIN1WEEKEND_RAY_H
#define RTIN1WEEKEND_RAY_H

#include "vec3.h"
#include <cmath>

class ray {
public:
    ray() : orig(vec3{0,0,0}), dir(vec3{0,0,0}) {}
    ray(const point3& origin, const vec3& direction)
            : orig(origin), dir(direction)
    {}

    point3 origin() const  { return orig; }
    vec3 direction() const { return dir; }

    point3 at(double t) const {
        return orig + t*dir;
    }

private:
    point3 orig;
    vec3 dir;
};

double hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = b*b - a*c;

    if (discriminant < 0.0)
        return -1.0;
    else
        return (-b - std::sqrt(discriminant))/a;
}

#endif //RTIN1WEEKEND_RAY_H