#include "renderer.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::cout << "Enter the path to your scene file: ";
	std::string spath;
	std::cin >> spath;
	std::cout << "Enter the path to your destination file: ";
	std::string dpath;
	std::cin >> dpath;
	std::cout << "Please wait till we render your scene!" << std::endl;
	std::ifstream sceneFile(spath);
	std::vector<Sphere> objects;
	Vector3D camera = Vector3D(0, 0, -1);
	int width = 100, height = 100;
	std::string line;
	while(std::getline(sceneFile, line)) {
		// std::cout << line;
		if(line.substr(0, 3) == "CAM") {
			long double x = 0, y = 0, z = -1;

			int offset = 4;

			int delim1 = line.substr(offset).find(" ");
			x = stold(line.substr(offset, delim1));
			offset += delim1 + 1;

			int delim2 = line.substr(offset).find(" ");
			y = stold(line.substr(offset, delim2));
			offset += delim2 + 1;

			int delim3 = line.substr(offset).find(" ");
			z = stold(line.substr(offset, delim3));
			camera = Vector3D(x, y, z);
		}
		if(line.substr(0, 3) == "RES") {
			int offset = 4;

			int delim1 = line.substr(offset).find(" ");
			width = stold(line.substr(offset, delim1));
			offset += delim1 + 1;

			int delim2 = line.substr(offset).find(" ");
			height = stold(line.substr(offset, delim2));
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
			objects.push_back(Sphere(center, radius, color));
		}
	}
	std::cout << "Finished reading scene..." << std::endl;
	Image result = render(camera, objects, width, height);
	std::ofstream myfile;
	std::cout << "Printing image to PPM file." << std::endl;
	myfile.open(dpath);
	myfile << result;
	myfile.close();
	std::cout << "Done!" << std::endl;
	return 0;
}