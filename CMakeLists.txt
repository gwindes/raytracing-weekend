cmake_minimum_required(VERSION 3.16)
project(raytracer_weekend)

set(CMAKE_CXX_STANDARD 14)

add_executable(raytracer_weekend main.cpp camera.cpp dielectric.cpp sphere.cpp metal.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(raytracer_weekend PUBLIC OpenMP::OpenMP_CXX)
endif()