#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color {
	public:
		long double r = 0, g = 0, b = 0;
		Color(long double r, long double g, long double b);
		Color();
		Color(const char* hex);
		Color operator+(const Color& other);
		Color operator-(const Color& other);
		Color operator*(double scalar);
		Color& operator+=(const Color& other);
		Color& operator-=(const Color& other);
};

std::ostream &operator<<(std::ostream &output, const Color& v);

#endif
