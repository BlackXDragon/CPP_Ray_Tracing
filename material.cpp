#include "material.h"

Material::Material(Color c = Color(), double a = 0.05, double d = 1.0, double s = 1.0) {
	color = c;
	ambient = a;
	diffuse = d;
	specular = s;
}

Material::Material(Color c = Color()) {
	color = c;
	ambient = 0.05;
	diffuse = 1.0;
	specular = 1.0;
}

Material::Material() {
	color = Color();
	ambient = 0.05;
	diffuse = 1.0;
	specular = 1.0;
}

std::ostream &operator<<(std::ostream &output, const Material& m) {
	return output << "<Material (" << m.color << ", " << m.ambient << ", " << m.diffuse << ", " << m.specular << ")>";
}