#ifndef RAYTRACER_WEEKEND_DIALECTRIC_H
#define RAYTRACER_WEEKEND_DIALECTRIC_H

#include "material.h"


class dielectric : public material {
private:
    bool refract(const vec3& v, const vec3& n, float ni_over_nt, vec3& refracted) const;
    float schlick(float cosine, float ref_idx) const;

public:
    dielectric(float ri) : ref_idx(ri) {}

    virtual bool scatter(const ray& r_in, const hit_record rec, vec3& attenuation, ray& scattered) const;

    float ref_idx;
};


#endif //RAYTRACER_WEEKEND_DIALECTRIC_H
