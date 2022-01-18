#include <crt.h>
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
	
	Sphere** objects;
	int n_objects;
	Light** lights;
	int n_lights;
	Vector3D camera = Vector3D(0, 0, -1);
	int width = 100, height = 100;
	
	read_scene(spath, &camera, &objects, &n_objects, &lights, &n_lights, &width, &height);
	std::cout << "Finished reading scene..." << std::endl;
	
	Image result = render(camera, objects, n_objects, lights, n_lights, width, height, 5);
	std::ofstream myfile;

	std::cout << "Printing image to PPM file." << std::endl;
	myfile.open(dpath);
	myfile << result;
	myfile.close();

	std::cout << "Done!" << std::endl;

	return 0;
}