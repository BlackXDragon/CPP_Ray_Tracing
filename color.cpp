#include "color.h"
#include <string.h>

Color::Color(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

Color::Color() {}

Color::Color(const char* hex) {
	std::string hexString = hex;
	this->r = strtol(hexString.substr(1,2).c_str(), NULL, 16);
	this->g = strtol(hexString.substr(3,2).c_str(), NULL, 16);
	this->b = strtol(hexString.substr(5,2).c_str(), NULL, 16);
}

Color Color::operator+(const Color& other) {
	return Color(this->r + other.r, this->g + other.g, this->b + other.b);
}

Color& Color::operator+=(const Color& other) {
	this->r += other.r;
	this->g += other.g;
	this->b += other.b;
	return *this;
}

Color Color::operator-(const Color& other) {
	return Color(this->r - other.r, this->g - other.g, this->b - other.b);
}

Color& Color::operator-=(const Color& other) {
	this->r -= other.r;
	this->g -= other.g;
	this->b -= other.b;
	return *this;
}

Color Color::operator*(double scalar) {
	return Color(this->r*scalar, this->g*scalar, this->b*scalar);
}

std::ostream &operator<<(std::ostream &output, const Color& c) {
	return output << "<Color (" << c.r << ", " << c.g << ", " << c.b << ")>";
}