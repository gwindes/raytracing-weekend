# raytracing-weekend

Inspired by: https://raytracing.github.io/

Modified to include OpenMP parallel computing.

## Local Development / Running Locally
* Need CMake 3.16 or great

1. create build directory within project root `mkdir build`
2. cd to `build` directory
3. run `cmake ..` to build cmake dependencies
4. run `make` in `raytracing-weekend/build`
5. To run program `./build/raytracer_weekend >> output.ppm`

Note: Modify the resolution and number of samples in `main.cpp` within `main()`:
```
    int nx = 1920; // image width
    int ny = 1080; // image height
    int ns = 4; //number of samples per pixel
```


## Roadmap
|                          Roadmap Item                          |   Status    |
|:--------------------------------------------------------------:|:-----------:|
|                     Add support for OpenMP                     |  Completed  |
| Refactor raytracer weekend implementations out of header files |  Complete   |
|                      Add support for MPI                       | In Progress |
|                        Add Cuda Support                        |    To Do    |



## Parallel Benchmarks
Complex Scene 1K+ spheres (100 samples):

| CPU                     | Cores / Threads | Resolution |  Avg Time (3 runs)   | Speedup | Parallel Efficiency |
|:------------------------|:---------------:|:----------:|:--------------------:|:-------:|:-------------------:|
| AMD Ryzen 7950x 4.5GHz  |        1        |   1080p    | 4 hrs 24 min 47 secs |    -    |          -          |
| AMD Ryzen 7950x 4.5GHz  |     16 / 32     |   1080p    |    14 min 13 secs    | 18.62x  |        0.58         |
| Core i7 3770K 3.5GHz    |        1        |   1080p    | 5 hrs 22 min 43 secs |    -    |          -          |
| Core i7 3770K 3.5GHz    |      4 / 8      |   1080p    | 1 hrs 22 min 54 secs |  3.89x  |        0.49         |
| Raspberry Pi 3 1.4GHz   |        1        |   1080p    | 51 hrs 2 min 12 secs |    -    |          -          |
| Raspberry Pi 3 1.4GHz   |        4        |   1080p    | 24 hrs 1 min 14 secs |  2.12x  |        0.53         |

