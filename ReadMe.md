# Basic Ray Tracing in C++

To run the program use:

```
make run
```

On running the program, it asks for the path to a scene file (sample file scene.txt is given) and a path to the destination file where the final image will be stored in ppm format.

## Syntax for the scene file:

### To set camera location:

```
CAM x y z
```
where x, y and z are the coordinates.

### To set output resolution:

```
RES <width> <height>
```

### To add a sphere to the scene:

```
SPH x y z r #col
```
where x, y and z are the coordinates of the center of the sphere, r is the radius and #col is the color of the sphere in hex format.

### To add a point light source to the scene:

```
PLT x y z #col
```
where x, y and z are the coordinates of the location and #col is the color of the point light source in hex format.

## Sample output image

In the following sample output, the 4 spheres are intersecting with each other and there are 2 point light sources in the scene. While the actual output of the code is a .ppm file, the image has been converted to JPEG format using GIMP to be embedded in this ReadMe file.

![Sample output image](./test.jpg)

## Bug:
1. *FIXED* - The rendering processes randomly stops around 3/4 of the way without throwing exceptions when the aspect ratio of the final image is not 1.0 (Return code: -1073740940)

**Log of the output where bug occurred is given under the bug_logs directory.**

**The fix for bugs given in [Fixes.md](./Fixes.md).**