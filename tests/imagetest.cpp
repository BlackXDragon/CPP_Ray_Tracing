#include "../image.h"
#include <fstream>
#include <iostream>

int main () {
	int width = 19, height = 6, max_color=255;
	std::cin >> height >> width >> max_color;
	std::cout << "Creating image" << std::endl;
	Image image = Image(width, height, max_color);
	std::cout << "Image object created: " << image.width << "x" << image.height << std::endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			try{
			image.setPixel(j, i, Color(0, i, j));
			}catch (char* e) {
				std::cout << "Some error occured: " << e;
				break;
			}
		}
	}

	std::ofstream myfile;
	std::cout << "Printing image to PPM file." << std::endl;
	myfile.open("testimage.ppm");
	myfile << image;
	myfile.close();
	std::cout << "Done." << std::endl;
	return 0;
}