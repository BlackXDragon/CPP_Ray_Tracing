#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>
#include <vector3d.h>
#include <color.h>
#include <material.h>
#include <ray.h>

class Sphere {
	public:
		Vector3D center = Vector3D(0,0,0);
		double radius = 0;
		Material material = Material();
		Sphere(Vector3D center, double radius, Material material);
		Sphere();
		double intersects(Ray ray);
		Vector3D normal(Vector3D point);
		bool in_object(Vector3D point);
};

std::ostream &operator<<(std::ostream &output, const Sphere& s);

#endif