#include "image.h"

Image::Image(int width, int height, int max_color) : width(width), height(height), max_color(max_color) {
	this->pixels = (Color*) malloc(sizeof(Color) * height * width);
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			this->pixels[i * this->width + j] = Color(0, 0, 0);
		}
	}
}

void Image::setPixel(int x, int y, Color color) {
	// std::cout << "setPixel" << std::endl;
	if (x > width || x < 0 || y > height || y < 0) {
		std::cout << "Pixel indices out of bounds: " << x << " " << y << " " << color << std::endl;
		throw "Pixel indices out of bounds.";
	}
	// std::cout << "in bounds " << this->pixels[x][y] << std::endl;
	this->pixels[x * this->width + y].r = color.r;
	// std::cout << "r set" << std::endl;
	this->pixels[x * this->width + y].g = color.g;
	// std::cout << "g set" << std::endl;
	this->pixels[x * this->width + y].b = color.b;
	// std::cout << x << " " << y << ": " << this-> pixels[x][y] << std::endl;
}

std::ostream &operator<<(std::ostream &output, const Image& im) {
	output << "P3 " << im.width << " " << im.height << std::endl;
	output << im.max_color << std::endl;
	for (int i = 0; i < im.height; i++) {
		for (int j = 0; j < im.width; j++) {
			output << std::round(std::min(std::max(im.pixels[j * im.width + i].r * 255.0, 0.0L), 255.0L)) << " " << std::round(std::min(std::max(im.pixels[j * im.width + i].g * 255.0, 0.0L), 255.0L)) << " " << std::round(std::min(std::max(im.pixels[j * im.width + i].b * 255.0, 0.0L), 255.0L)) << " ";
		}
		output << std::endl;
	}
	return output;
}