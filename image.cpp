#include "image.h"
#include <iostream>
#include <vector>

Image::Image(int width, int height, int max_color) : width(width), height(height), max_color(max_color) {
	// this->pixels = new Color*[height];
	for (int i = 0; i < this->height; i++) {
		// this->pixels[i] = new Color[width];
		std::vector<Color> temp;
		for (int j = 0; j < this->width; j++) {
			// this->pixels[i][j] = Color();
			temp.push_back(Color());
		}
		this->pixels.push_back(temp);
	}
}

void Image::setPixel(int x, int y, Color color) {
	// std::cout << "setPixel" << std::endl;
	if (x >= width || x < 0 || y >= height || y < 0) {
		std::cout << "Pixel indices out of bounds: " << x << " " << y << " " << color << std::endl;
		throw "Pixel indices out of bounds.";
	}
	// std::cout << "in bounds " << this->pixels[x][y] << std::endl;
	this->pixels[y][x].r = color.r;
	// std::cout << "r set" << std::endl;
	this->pixels[y][x].g = color.g;
	// std::cout << "g set" << std::endl;
	this->pixels[y][x].b = color.b;
	// std::cout << x << " " << y << ": " << this-> pixels[x][y] << std::endl;
}

std::ostream &operator<<(std::ostream &output, const Image& im) {
	output << "P3 " << im.width << " " << im.height << std::endl;
	output << im.max_color << std::endl;
	for (int i = 0; i < im.height; i++) {
		for (int j = 0; j < im.width; j++) {
			output << im.pixels[i][j].r << " " << im.pixels[i][j].g << " " << im.pixels[i][j].b << " ";
		}
		output << std::endl;
	}
	return output;
}