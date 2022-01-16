#ifndef IMAGE_H
#define IMAGE_H

#include <color.h>
#include <cmath>
#include <algorithm>

class Image {
	public:
		const int width, height, max_color;
		Color* pixels;
		Image(int width, int height, int max_color);
		void setPixel(int x, int y, Color color);
};

std::ostream &operator<<(std::ostream &output, const Image& im);

#endif