#include "vector3d.h"

Vector3D::Vector3D(long double x, long double y, long double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D() {}

Vector3D Vector3D::operator+(const Vector3D& other) {
	return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D& other) {
	return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3D Vector3D::operator*(const long double scalar) {
	return Vector3D(this->x*scalar, this->y*scalar, this->z*scalar);
}

long double Vector3D::mod() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

long double Vector3D::dot(const Vector3D& other) {
	return this->x*other.x + this->y*other.y + this->z*other.z;
}

Vector3D Vector3D::normalize() {
	long double magnitude = this->mod();
	return Vector3D(this->x/magnitude, this->y/magnitude, this->z/magnitude);
}

std::string Vector3D::__repr__() {
	return "<Vector3D (" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ")>";
}

std::ostream &operator<<(std::ostream &output, const Vector3D& v) {
	return output << "<Vector3D (" << v.x << ", " << v.y << ", " << v.z << ")>";
}