# MiniRT
A small raytracer using MLX, the graphic library of 42.

GPU utilization is forbidden in this project. To enhance our goal of achieving smooth movement and fast rendering, we implemented multi-threading, pixel shuffling, and an optimized rendering mode during motion. This approach not only improves performance but also ensures a seamless visual experience.
## Index
1. [Exports](#exports)
2. [Requirements](#requirements)
3. [Setup and run](#setup-and-run)
## Exports
### [assets/scenes/demo.rt](assets/scenes/demo.rt)
![assets/scenes/demo.rt_12000s](https://github.com/user-attachments/assets/05329a72-bafa-4b97-b03b-80fc9506a0a8)
12000sec
### [assets/scenes/beautiful.rt](assets/scenes/beautiful.rt)
![beautiful_aa_7d_768s](https://github.com/user-attachments/assets/7066fadb-4d93-4878-a702-70058eb75664)
768sec
### [assets/scenes/pathtracer.rt](assets/scenes/pathtracer.rt)
![Pathtracer_10000s](https://github.com/user-attachments/assets/d9cc7229-973e-4a37-a676-13dca691caa4)
10000sec

And more...

👇 Try it yourself! 👇
## Requirements
* Linux or MacOS
* [Clang](https://releases.llvm.org/download.html)
* [Cmake](https://cmake.org/download/)
## Setup and run
```shell
git clone https://github.com/cfareste/MiniRT.git miniRT \
&& cd miniRT \
&& make \
&& ./miniRT assets/scenes/pathtracer.rt;
```
