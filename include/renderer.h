#if !defined(RENDERER_H)
#define RENDERER_H

#include <vector3d.h>
#include <color.h>
#include <image.h>
#include <objects/sphere.h>
#include <lights/light.h>
#include <vector>
#include <cmath>
#include <chrono>
#include <iostream>

#if SPEEDUP==1
	#include <thread_pool.hpp>
#endif

Image render(Vector3D camera, Sphere** objects, int n_objects, Light** lights, int n_lights, int width, int height, int reflection_depth);

Color ray_trace(Ray ray, Sphere** objects, int n_objects, Vector3D camera, Light** lights, int n_lights, int reflection_depth, int depth);

double find_refr_index(Sphere** objects, int n_objects, Vector3D position);

void find_nearest(Ray ray, Sphere** objects, int n_objects, double *dist_hit, Sphere *object_hit, bool *success);

Color color_at(Sphere object_hit, Vector3D hit_pos, Sphere** objects, int n_objects, Vector3D camera, Light** lights, int n_lights);

#endif // RENDERER_H
