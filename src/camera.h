#ifndef RTIN1WEEKEND_CAMERA_H
#define RTIN1WEEKEND_CAMERA_H

#include "vec3.h"
#include "ray.h"
#include "constutils.h"

class camera {
private:
    const double aspect_ratio = 16.0 / 9.0;
    const double viewport_height = 2.0;
    const double viewport_width = aspect_ratio * viewport_height;
    const double focal_length = 1.0;

    point3 origin = point3(0, 0, 0);
    vec3 horizontal = vec3(viewport_width, 0.0, 0.0);
    vec3 vertical = vec3(0.0, viewport_height, 0.0);
    point3 lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

public:
    ray get_ray(double u, double v) const {
        return ray(
                origin,
                lower_left_corner + u * horizontal + v * vertical - origin
            );
    }
};

#endif //RTIN1WEEKEND_CAMERA_H
