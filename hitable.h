#ifndef RAYTRACER_WEEKEND_HITABLE_H
#define RAYTRACER_WEEKEND_HITABLE_H


struct hit_record {
    float t;
    vec3 p;
    vec3 normal;
};

class hitable {
public:
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};


#endif //RAYTRACER_WEEKEND_HITABLE_H
