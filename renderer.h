#if !defined(RENDERER_H)
#define RENDERER_H

#include "vector3d.h"
#include "color.h"
#include "image.h"
#include "sphere.h"
#include "light.h"
#include <vector>
#include <cmath>

Image render(Vector3D camera, std::vector<Sphere> objects, std::vector<Light*> lights, int width, int height);

Color ray_trace(Ray ray, std::vector<Sphere> objects, Vector3D camera, std::vector<Light*> lights);

void find_nearest(Ray ray, std::vector<Sphere> objects, double *dist_hit, Sphere *object_hit, bool *success);

Color color_at(Sphere object_hit, Vector3D hit_pos, std::vector<Sphere> objects, Vector3D camera, std::vector<Light*> lights);

#endif // RENDERER_H
