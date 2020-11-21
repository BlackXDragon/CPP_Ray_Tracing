#include "../vector3d.h"
#include <iostream>

int main() {
	Vector3D v1 = Vector3D(1,2,3);
	Vector3D v2 = Vector3D(2,2,2);
	std::cout << "Sum: " << v1+v2 << std::endl;
	std::cout << "Difference: " << v1-v2 << std::endl;
	std::cout << "Scalar multiplication: " << v1*2 << std::endl;
	std::cout << "Magnitude: " << v1.mod() << std::endl;
	std::cout << "Dot product: " << v1.dot(v2) << std::endl;
	return 0;
}