#ifndef SPHERE_H
#define SPHERE_H

#include "vector3d.h"
#include "color.h"
#include "ray.h"

class Sphere {
	public:
		Vector3D center = Vector3D(0,0,0);
		double radius = 0;
		Color color = Color();
		Sphere(Vector3D center, int radius, Color color);
		Sphere();
		double intersects(Ray ray);
};

std::ostream &operator<<(std::ostream &output, const Sphere& s);

#endif