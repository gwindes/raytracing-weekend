#include <iostream>
#include <string>
#include "vec3.h"
#include "ray.h"
#include "float.h"
#include "sphere.h"
#include "hitablelist.h"
#include "camera.h"

#include "material.h"
#include "lambertian.h"
#include "metal.h"
#include "dielectric.h"

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

hitable * random_scene() {
    int max = 15;
    int n = (max*2)*(max*2) + 1;
    hitable **list = new hitable*[n+1];

    list[0] = new sphere(vec3(0, -1000, -1), 1000, new lambertian(vec3(0.1, 0.1, 0.1)));

    int i = 1;

    for (int x = -max; x < max; x++) {
        for (int z = -max; z < max; z++) {
            float choose_mat = drand48();
            vec3 center(x+0.9*drand48(), 0.2, z+0.9*drand48());
            if ((center - vec3(4, 0.2, 0)).length() > 0.9) {
                material * obj_material;
                if (choose_mat < 0.8) {
                    obj_material = new lambertian(vec3(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()));
                } else if (choose_mat < 0.95) {
                    obj_material = new metal(vec3(0.5*(1+drand48()), 0.5*(1+drand48()), 0.5*(1+drand48())), 0.5*drand48());
                } else {
                    obj_material = new dielectric(1.5);
                }
                list[i++] = new sphere(center, 0.2, obj_material);
            }
        }
    }

    list[i++] = new sphere(vec3(3,1, 0), 1.0, new metal(vec3(0.7, 0.6, 0.5), 0.01));
    list[i++] = new sphere(vec3(0,1,0), 1.0, new dielectric(1.5));
    list[i++] = new sphere(vec3(-3,1, 0), 1.0, new lambertian(vec3(0.1, 0.3, 1.0)));

    return new hitablelist(list, i);
}

int main() {
    int nx = 500;
    int ny = 250;
    int ns = 100;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    /*
    int num_spheres = 5;
    hitable* list[num_spheres];
    list[0] = new sphere(vec3(0,0,-1), 0.5, new lambertian(vec3(0.1, 0.3, 0.99)));
    list[1] = new sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.1, 0.1, 0.1)));
    list[2] = new sphere(vec3(1,0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2), 0.1));
    list[3] = new sphere(vec3(-1,0, -1), 0.5, new dielectric(1.5));
    list[4] = new sphere(vec3(-1,0, -1), -0.45, new dielectric(1.5));
    hitable * world = new hitablelist(list, num_spheres);
     */

    hitable * world = random_scene();

    vec3 lookfrom(4,1.25,2);
    vec3 lookat(0,0,-1);
    float aperture = 0.0;
    float dist_to_focus = (lookfrom-lookat).length();
    camera cam(
            lookfrom,
            lookat,
            vec3(0,1,0),
            80,
            float(nx)/float(ny),
            aperture,
            dist_to_focus
    );

    long num_pixels = nx * ny;
    std::string * pixel_values = new std::string[num_pixels+1];
    int max_y = ny-1;

    #pragma omp parallel for
    for(int j = max_y; j >= 0; j--) {
        long idx = 0;
        for(int i=0; i < nx; i++) {
            vec3 col(0.0, 0.0, 0.0);
            for (int s=0; s < ns; s++) {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);

                ray r = cam.get_ray(u, v);
                //vec3 p = r.point_at_parameter(2.0);
                col += color(r, world, 0);
            }

            // average the pixel value for ns rays casted
            col /= float(ns);
            // gamma correction
            col = vec3( sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);

            idx = abs(j - (max_y)) * nx + i;
            std::string tmp = std::to_string(ir) + " " + std::to_string(ig) + " " + std::to_string(ib);
            pixel_values[idx] = tmp;
        }
    }

    for (long i=0; i < num_pixels; i++) {
        std::cout << pixel_values[i] << "\n";
    }

    return 0;
}
