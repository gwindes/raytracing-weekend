#include <iostream>

int main() {
    int nx = 500;
    int ny = 250;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    for(int j=0; j < ny; j++) {
        for(int i=0; i < nx; i++) {
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2f;

            int ir = int(255.99*r);
            int ig = int(255.99*g);
            int ib = int(255.99*b);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return 0;
}
