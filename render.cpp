// #include "renderer.h"
#include "read_config.h"
#include <iostream>
#include <string>

int main() {
	std::cout << "Enter the path to your scene file: ";
	std::string spath;
	std::cin >> spath;
	std::cout << "Enter the path to your destination file: ";
	std::string dpath;
	std::cin >> dpath;
	std::cout << "Please wait till we render your scene!" << std::endl;
	std::vector<Sphere> objects;
	std::vector<Light*> lights;
	Vector3D camera = Vector3D(0, 0, -1);
	int width = 100, height = 100;
	read_scene(spath, &camera, &objects, &lights, &width, &height);
	/* std::string line;
	while(std::getline(sceneFile, line)) {
		// std::cout << line;
		if(line.substr(0, 3) == "CAM") {
			long double x = 0, y = 0, z = -1;

			int offset = 4;

			int delim = line.substr(offset).find(" ");
			x = stold(line.substr(offset, delim));
			offset += delim + 1;

			delim = line.substr(offset).find(" ");
			y = stold(line.substr(offset, delim));
			offset += delim + 1;

			delim = line.substr(offset).find(" ");
			z = stold(line.substr(offset, delim));
			camera = Vector3D(x, y, z);
		}
		if(line.substr(0, 3) == "RES") {
			int offset = 4;

			int delim = line.substr(offset).find(" ");
			width = stold(line.substr(offset, delim));
			offset += delim + 1;

			delim = line.substr(offset).find(" ");
			height = stold(line.substr(offset, delim));
		}
		if(line.substr(0, 3) == "SPH") {
			long double x = 0, y = 0, z = -1;

			int offset = 4;

			int delim = line.substr(offset).find(" ");
			x = stold(line.substr(offset, delim));
			offset += delim + 1;

			delim = line.substr(offset).find(" ");
			y = stold(line.substr(offset, delim));
			offset += delim + 1;

			delim = line.substr(offset).find(" ");
			z = stold(line.substr(offset, delim));
			Vector3D center = Vector3D(x, y, z);
			offset += delim + 1;

			delim = line.substr(offset).find(" ");
			long double radius = stold(line.substr(offset, delim));
			offset += delim + 1;

			Color color = Color(line.substr(offset).c_str());
			objects.push_back(Sphere(center, radius, Material(color)));
		}
		if(line.substr(0, 3) == "PTL") {
			long double x = 0, y = 0, z = -1;

			int offset = 4;

			int delim = line.substr(offset).find(" ");
			x = stold(line.substr(offset, delim));
			offset += delim + 1;

			delim = line.substr(offset).find(" ");
			y = stold(line.substr(offset, delim));
			offset += delim + 1;

			delim = line.substr(offset).find(" ");
			z = stold(line.substr(offset, delim));
			offset += delim + 1;

			Color color = Color(line.substr(offset).c_str());
			Vector3D position = Vector3D(x, y, z);
			// PointLight PL = PointLight(color, position);
			PointLight *PL = new PointLight(color, position);
			// std::cout << typeid(PL).name() << std::endl;
			// PointLight* PL = (PointLight*) malloc(sizeof(PointLight));
			// *PL = PointLight(color, position);
			// std::cout << ' ' << PL << std::endl;
			lights.push_back(PL);
		// 	std::cout << "PointLight: ";
		// 	PL->print();
		// 	std::cout << ' ' << &PL << std::endl;
		}
	} */
	// std::cout << typeid(*lights[0]).name() << std::endl;
	std::cout << "Finished reading scene..." << std::endl;
	// for (int i = 0; i < lights.size(); i++) {
	// 	std::cout << lights[i] << ' ';
	// 	lights[i]->print();
	// 	std::cout << std::endl;
	// }
	Image result = render(camera, objects, lights, width, height, 5);
	std::ofstream myfile;
	std::cout << "Printing image to PPM file." << std::endl;
	myfile.open(dpath);
	myfile << result;
	myfile.close();
	std::cout << "Done!" << std::endl;
	return 0;
}