#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D {
	public:
		long double x = 0, y = 0, z = 0;
		Vector3D(long double x, long double y, long double z);
		Vector3D();
		Vector3D operator+(const Vector3D& other);
		Vector3D operator-(const Vector3D& other);
		Vector3D operator*(const long double scalar);
		long double dot(const Vector3D& other);
		long double mod();
		Vector3D normalize();
		std::string __repr__();
};

std::ostream &operator<<(std::ostream &output, const Vector3D& v);

#endif