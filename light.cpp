#include "light.h"

Light::Light() {
	color = Color("#FFFFFF");
}

Color Light::calculateDiffuse(Vector3D hit_pos, Material material, Vector3D hit_normal) {
	throw "Error: Light::calculateDiffuse method not implemented.";
}

Color Light::calculateSpecular(Vector3D hit_pos, Material material, Vector3D hit_normal, Vector3D to_cam, double specular_k) {}

PointLight::PointLight() {
	this->color = Color("#FFFFFF");
	this->position = Vector3D();
}

PointLight::PointLight(Color color, Vector3D position) {
	this->color = color;
	this->position = position;
}

Color PointLight::calculateDiffuse(Vector3D hit_pos, Material material, Vector3D hit_normal) {
	// Lambert model
	Ray to_light = Ray(hit_pos, this->position-hit_pos);
	return material.color * material.diffuse * std::max(hit_normal.dot(to_light.direction), 0.0L);
}

Color PointLight::calculateSpecular(Vector3D hit_pos, Material material, Vector3D hit_normal, Vector3D to_cam, double specular_k) {
	// Blinn-Phong model
	Ray to_light = Ray(hit_pos, this->position-hit_pos);
	Vector3D half_vector = (to_light.direction + to_cam).normalize();
	return this->color * material.specular * std::pow(std::max(hit_normal.dot(half_vector), 0.0L), specular_k);
}