#ifndef RAYTRACER_WEEKEND_HITABLELIST_H
#define RAYTRACER_WEEKEND_HITABLELIST_H

#include "hitable.h"

class hitablelist: public hitable {
public:
    hitablelist() {}
    hitablelist(hitable **l, int n) {list = l; list_size = n;}
    virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
    hitable **list;
    int list_size;
};

bool hitablelist::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;
    for (int i = 0; i < list_size; i++) {
        if (list[i]->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}


#endif //RAYTRACER_WEEKEND_HITABLELIST_H
