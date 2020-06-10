# raytracing-weekend

Inspired by: https://raytracing.github.io/

Modified to include OpenMP parallel computing.

## Roadmap
|Roadmap Item|Status|
|:----------:|:----:|
| Add support for OpenMP | Completed |
| Refactor raytracer weekend implementations out of header files | In Progress |
| Add support for MPI | To Do |
| Add Cuda Support | To Do |



## Parallel Benchmarks

Complex Scene 1K+ spheres:

|CPU|Cores|Resolution|Time (HH:MM:SS)|Performance Gain|
|:---:|:---:|:----:|:--------------:|:---:|
|Core i7| 1 | 1080p | TBD | - |
|Core i7| 8 | 1080p | 87 min 34 secs | - |
|Raspberry Pi 3| 1 | 1080p | 51 hrs 2 min 12 secs | - |
|Raspberry Pi 3| 4 | 1080p | TBD | - |

