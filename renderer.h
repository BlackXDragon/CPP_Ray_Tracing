#if !defined(RENDERER_H)
#define RENDERER_H

#include "vector3d.h"
#include "color.h"
#include "image.h"
#include "sphere.h"
#include <vector>

Image render(Vector3D camera, std::vector<Sphere> objects, int width, int height);

Color ray_trace(Ray ray, std::vector<Sphere> objects);

void find_nearest(Ray ray, std::vector<Sphere> objects, double *dist_hit, Sphere *object_hit, bool *success);

Color color_at(Sphere object_hit, Vector3D hit_pos, std::vector<Sphere> objects);

#endif // RENDERER_H
