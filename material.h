#ifndef RAYTRACER_WEEKEND_MATERIAL_H
#define RAYTRACER_WEEKEND_MATERIAL_H

#include "vec3.h"

class material {
public:
    virtual bool scatter(const ray& r, const hit_record rec, vec3& attenuation, ray& scattered) const = 0;
};


#endif //RAYTRACER_WEEKEND_MATERIAL_H
