#if !defined(LIGHT_H)
#define LIGHT_H

#include <color.h>
#include <vector3d.h>
#include <material.h>
#include <ray.h>
#include <algorithm>
#include <math.h>
#include <string>

class Light {
	public:
		Color color;
		Light();
		virtual Color calculateDiffuse(Vector3D hit_pos, Material material, Vector3D hit_normal);
		virtual Color calculateSpecular(Vector3D hit_pos, Material material, Vector3D hit_normal, Vector3D to_cam, double specular_k);
		virtual void print();
		virtual std::string __repr__();
};

class PointLight : public Light {
	public:
		Vector3D position;
		PointLight();
		PointLight(Color color, Vector3D position);
		Color calculateDiffuse(Vector3D hit_pos, Material material, Vector3D hit_normal);
		Color calculateSpecular(Vector3D hit_pos, Material material, Vector3D hit_normal, Vector3D to_cam, double specular_k);
		void print();
		std::string __repr__();
};

class DirectionalLight : public Light {
	public:
		Vector3D direction;
		DirectionalLight();
		DirectionalLight(Color color, Vector3D direction);
		Color calculateDiffuse(Vector3D hit_pos, Material material, Vector3D hit_normal);
		Color calculateSpecular(Vector3D hit_pos, Material material, Vector3D hit_normal, Vector3D to_cam, double specular_k);
		void print();
		std::string __repr__();
};

std::ostream &operator<<(std::ostream &output, PointLight& pl);

#endif // LIGHT_H
