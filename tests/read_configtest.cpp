#include "../read_config.h"

int main() {
	Vector3D cam;
	std::vector<Sphere> objects;
	std::vector<Light*> lights;
	int width, height;
	read_scene("scene.json", &cam, &objects, &lights, &width, &height);
	std::cout << cam << std::endl;
	std::cout << width << "x" << height << std::endl;
	std::cout << "objects:" << std::endl;
	for (auto i: objects)
		std::cout << i << std::endl;
	std::cout << "lights:" << std::endl;
	for (auto i: lights)
		std::cout << *i << std::endl;
	return 0;
}