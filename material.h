#ifndef RAYTRACER_WEEKEND_MATERIAL_H
#define RAYTRACER_WEEKEND_MATERIAL_H

#include "vec3.h"
#include "ray.h"
#include "hitable.h"

class material {
protected:
    vec3 reflect(const vec3& v, const vec3& n) const {
        return v - 2*dot(v,n)*n;
    }
public:
    virtual bool scatter(const ray& r, const hit_record rec, vec3& attenuation, ray& scattered) const = 0;
};


#endif //RAYTRACER_WEEKEND_MATERIAL_H
