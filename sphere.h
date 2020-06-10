#ifndef RAYTRACER_WEEKEND_SPHERE_H
#define RAYTRACER_WEEKEND_SPHERE_H

#include "hitable.h"

class sphere: public hitable {
public:
    sphere() {}
    sphere(vec3 cen, float r) : center(cen), radius(r) {};
    sphere(vec3 cen, float r, material * mat) : center(cen), radius(r), obj_material(mat) {};
    virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
    vec3 center;
    float radius;
    material* obj_material;
};

#endif //RAYTRACER_WEEKEND_SPHERE_H
