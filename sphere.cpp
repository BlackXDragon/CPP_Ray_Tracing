#include "sphere.h"
#include <cmath>

Sphere::Sphere(Vector3D center, int radius, Material material) : center(center), radius(radius), material(material) {}

Sphere::Sphere() {}

double Sphere::intersects(Ray ray) {
	Vector3D sphere_to_ray = ray.origin - this->center;
	double b = 2 * ray.direction.dot(sphere_to_ray);
	double c = sphere_to_ray.dot(sphere_to_ray) - this->radius * this->radius;
	double discriminant = b * b - 4 * c;
	if (discriminant >= 0) {
		double dist = (-b -sqrt(discriminant))/2;
		if (dist > 0) {
			return dist;
		}
	}
	return -1;
}

Vector3D Sphere::normal(Vector3D point) {
	return (point - this->center).normalize();
}

std::ostream &operator<<(std::ostream &output, const Sphere& s) {
	return output << "<Sphere (" << s.center.x << ", " << s.center.y << ", " << s.center.z << ") " << s.radius << " " << s.material << ">";
}