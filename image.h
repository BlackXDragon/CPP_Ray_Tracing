#ifndef IMAGE_H
#define IMAGE_H

#include "Color.h"
#include <vector>

class Image {
	public:
		const int width, height, max_color;
		std::vector<std::vector<Color>> pixels;
		Image(int width, int height, int max_color);
		void setPixel(int x, int y, Color color);
};

std::ostream &operator<<(std::ostream &output, const Image& im);

#endif