# (Mini)RT
A (small) raytracer and pathtracer using [MLX](https://github.com/codam-coding-college/MLX42), the graphic library of 42.

GPU utilization is forbidden in this project. To enhance our goal of achieving smooth movement and fast rendering, we implemented multi-threading, pixel shuffling, and an optimized rendering mode during motion. This approach not only improves performance but also ensures a seamless visual experience.
## Index
1. [Exports](#exports)
2. [Setup and run](#setup-and-run)
3. [Controls](#controls)
## Exports
### [demo.rt](assets/scenes/demo.rt)
![assets/scenes/demo.rt_12000s](https://github.com/user-attachments/assets/05329a72-bafa-4b97-b03b-80fc9506a0a8)
12000sec
### [beautiful.rt](assets/scenes/beautiful.rt)
![beautiful_aa_7d_768s](https://github.com/user-attachments/assets/7066fadb-4d93-4878-a702-70058eb75664)
768sec
### [pathtracer.rt](assets/scenes/pathtracer.rt)
![Pathtracer_10000s](https://github.com/user-attachments/assets/d9cc7229-973e-4a37-a676-13dca691caa4)
10000sec

And more...

👇 Try it yourself! 👇
## Setup and run
### Requirements
* Linux or MacOS
* [Clang](https://releases.llvm.org/download.html)
* [Cmake](https://cmake.org/download/)
### Download and execute
```shell
git clone https://github.com/cfareste/MiniRT.git miniRT \
&& cd miniRT \
&& make \
&& ./miniRT assets/scenes/pathtracer.rt;
```
### Execute
Run `miniRT` executable file and pass your favourite `.rt` scene file as an argument (examples given on [assets/scenes](assets/scenes)).
```shell
./miniRT assets/scenes/demo.rt;
```
## Controls
| Key(s) | Action(s) |
| --- | --- |
| 1 | Switch render strategy to PathTracer |
| 2 | Switch render strategy to RayTracer |
| 3 | Switch render strategy to NormalMap |
| 4 | Switch motion cheap render off |
| 5 | Switch progressive render off |
| X | Export .ppm image |
| B | Block controls |
| P | Pause / play progressive render |
| I, O | Regulate fov |
| G, H | Regulate focus radius |
| J, K | Regulate focus distance |
| ctrl / cmd + S | Save changes to .rt file |
| ctrl / cmd + shift + S | Duplicate .rt file |
| esc | Quit program |
### Edit mode
| Key(s) | Action(s) |
| --- | --- |
| left click | Select object |
| enter | De-select object |
| N | New object |
| backspace | Delete object |
| T | Change object type |
| M | Change object material |
| W, A, S, D, shift, space | Move object position |
| arrows, Q, E | Rotate object |
