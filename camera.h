#ifndef RAYTRACER_WEEKEND_CAMERA_H
#define RAYTRACER_WEEKEND_CAMERA_H

#include "vec3.h"
class ray;

class camera {
public:
    camera(
        vec3 lookfrom,
        vec3 lookat,
        vec3 vup,
        float vfov,
        float aspect,
        float aperture,
        float focus_dist
    );

    ray get_ray(float s, float t);

    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
    vec3 origin;
    vec3 u, v, w;
    float lens_radius;
};

#endif //RAYTRACER_WEEKEND_CAMERA_H
