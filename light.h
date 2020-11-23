#if !defined(LIGHT_H)
#define LIGHT_H

#include "color.h"
#include "vector3d.h"
#include "material.h"
#include "ray.h"
#include <algorithm>

class Light {
	public:
		Color color;
		Light();
		Color calculateDiffuse(Vector3D hit_pos, Material material, Vector3D hit_normal);
		Color calculateSpecular(Vector3D hit_pos, Material material, Vector3D hit_normal, Vector3D to_cam, double specular_k);
};

class PointLight : public Light {
	public:
		Vector3D position;
		PointLight();
		PointLight(Color color, Vector3D position);
		Color calculateDiffuse(Vector3D hit_pos, Material material, Vector3D hit_normal);
		Color calculateSpecular(Vector3D hit_pos, Material material, Vector3D hit_normal, Vector3D to_cam, double specular_k);
};

#endif // LIGHT_H
