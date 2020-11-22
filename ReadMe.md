# Basic Ray Tracing in C++

To run the programme use:

```
make run
```

On running the programme, it asks for the path to a scene file (sample file scene.txt is given) and a path to the destination file where the final image will be stored in ppm format.

## Syntax for the scene file:

To set camera location:

```
CAM x y z
```
where x, y and z are the coordinates.

To set output resolution:

```
RES <width> <height>
```

To add a sphere to the scene:

```
SPH x y z r #col
```
where x, y and z are the coordinates of the center of the sphere, r is the radius and #col is the color of the sphere in hex format.

## Bug:
1. *FIXED* - The rendering processes randomly stops around 3/4 of the way without throwing exceptions when the aspect ratio of the final image is not 1.0 (Return code: -1073740940)

**Log of the output where bug occurred is given under the bug_logs directory.**

**The fix for bugs given in [Fixes.md](./Fixes.md).**