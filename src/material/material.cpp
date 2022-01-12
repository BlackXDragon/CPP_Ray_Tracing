#include "material.h"

Material::Material() {
	color = Color();
	ambient = 0.05;
	diffuse = 1.0;
	specular = 1.0;
	reflection = 0.5;
	refraction = 0.5;
	refr_ind = 1;
}

Material::Material(Color c) {
	color = c;
	ambient = 0.05;
	diffuse = 1.0;
	specular = 1.0;
	reflection = 0.5;
	refraction = 0.5;
	refr_ind = 1;
}

Material::Material(Color c = Color(), double a = 0.05, double d = 1.0, double s = 1.0, double rl = 0.5, double rr = 0.5, double rri = 1.0) {
	color = c;
	ambient = a;
	diffuse = d;
	specular = s;
	reflection = rl;
	refraction = rr;
	refr_ind = rri;
}

std::ostream &operator<<(std::ostream &output, const Material& m) {
	return output << "<Material (" << m.color << ", " << m.ambient << ", " << m.diffuse << ", " << m.specular << ")>";
}