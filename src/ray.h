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

color ray_color(const ray& r) {
    auto t = hit_sphere(point3(0,0,-1), 0.5, r);
    if (t > 0.0) {
        vec3 N = unit_vector(r.at(t) - vec3(0,0,-1));
        return 0.5*color(N.x()+1, N.y()+1, N.z()+1);
    }

    vec3 unit_direction = unit_vector(r.direction());
    t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}


#endif //RTIN1WEEKEND_RAY_H