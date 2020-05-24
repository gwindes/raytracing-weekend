#include <iostream>
#include "vec3.h"
#include "ray.h"
#include "float.h"
#include "sphere.h"
#include "hitablelist.h"
#include "camera.h"
#include "material.h"
#include "lambertian.h"
#include "metal.h"

// TODO: find the real MAXFLOAT var
#define MAXFLOAT 9999999.9

vec3 color(const ray& r, hitable* world, int depth) {
    hit_record rec;
    if (world->hit(r, 0.001, MAXFLOAT, rec)) {
        ray scattered;
        vec3 attenuation;

        if (depth < 50 && rec.material_ptr->scatter(r, rec, attenuation, scattered)) {
            return attenuation * color(scattered, world, depth+1);
        } else {
            return vec3(0,0,0);
        }
    } else {
        vec3 unit_direction = unit_vector(r.direction());
        float t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
    }
}

int main() {
    int nx = 500;
    int ny = 250;
    int ns = 100;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    int num_spheres = 4;

    hitable* list[num_spheres];
    list[0] = new sphere(vec3(0,0,-1), 0.5, new lambertian(vec3(0.8, 0.3, 0.3)));
    list[1] = new sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.1, 0.1, 0.1)));
    list[2] = new sphere(vec3(1,0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2), 1.0));
    list[3] = new sphere(vec3(-1,0, -1), 0.5, new metal(vec3(0.8, 0.8, 0.8), 0.3));

    hitable * world = new hitablelist(list, num_spheres);
    camera cam;

    // for(int j = 0; j < ny; j++) {
    for(int j = ny-1; j >= 0; j--) {
        for(int i=0; i < nx; i++) {
            vec3 col(0.0, 0.0, 0.0);
            for (int s=0; s < ns; s++) {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);

                ray r = cam.get_ray(u, v);
                vec3 p = r.point_at_parameter(2.0);
                col += color(r, world, 0);
            }

            // average the pixel value for ns rays casted
            col /= float(ns);
            // gamma correction
            col = vec3( sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return 0;
}
