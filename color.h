#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color {
	public:
		int r = 0, g = 0, b = 0;
		Color(int r, int g, int b);
		Color();
		Color(const char* hex);
		Color operator+(const Color& other);
		Color operator-(const Color& other);
		Color operator*(double scalar);
};

std::ostream &operator<<(std::ostream &output, const Color& v);

#endif
