#if !defined(MATERIAL_H)
#define MATERIAL_H

#include "color.h"

class Material {
	public:
		Color color;
		double ambient;
		double diffuse;
		double specular;
		double reflection;
		double refraction;
		double refr_ind;
		Material(Color c, double a, double d, double s, double rl, double rr, double rri);
		Material(Color c);
		Material();
};

std::ostream &operator<<(std::ostream &output, const Material& m);

#endif // MATERIAL_H
