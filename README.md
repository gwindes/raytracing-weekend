# raytracing-weekend

Inspired by: https://raytracing.github.io/

Modified to include OpenMP parallel computing.

## Local Development / Running Locally
* Need CMake 3.16 or great

1. make `build` directory within project root
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
|Roadmap Item|Status|
|:----------:|:----:|
| Add support for OpenMP | Completed |
| Refactor raytracer weekend implementations out of header files | Complete |
| Add support for MPI | In Progress |
| Add Cuda Support | To Do |



## Parallel Benchmarks
Complex Scene 1K+ spheres (100 samples):

|CPU|Cores|Resolution|Time (HH:MM:SS)|Speedup|Parallel Efficency|
|:---:|:---:|:----:|:--------------:|:------:|:----------------:|
|Core i7 3770K ~3.5GHz| 1 | 1080p | 51 hrs 7 min 41 secs | - | - |
|Core i7 3770K ~3.5GHz| 8 | 1080p | 14 hrs 25 min 34 secs | 3.54x | 0.44 |
|Raspberry Pi 3| 1 | 1080p | 51 hrs 2 min 12 secs | - | - |
|Raspberry Pi 3| 4 | 1080p | 24 hrs 1 min 14 secs | 2.12x | 0.53 |

