#ifndef RAYTRACER_WEEKEND_LAMBERTIAN_H
#define RAYTRACER_WEEKEND_LAMBERTIAN_H

#include "material.h"
#include "hitable.h"

class lambertian: public material {
public:
    lambertian(const vec3& a) : albedo(a) {}

    virtual bool scatter(const ray& r_in, const hit_record rec, vec3& attenuation, ray& scattered) const;

    vec3 albedo;
};


#endif //RAYTRACER_WEEKEND_LAMBERTIAN_H
