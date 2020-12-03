#include "light.h"

Light::Light() {
	color = Color("#FFFFFF");
}

Color Light::calculateDiffuse(Vector3D hit_pos, Material material, Vector3D hit_normal) {
	throw "Error: Light::calculateDiffuse method not implemented.";
}

Color Light::calculateSpecular(Vector3D hit_pos, Material material, Vector3D hit_normal, Vector3D to_cam, double specular_k) {
	throw "Error: Light::calculateSpecular method not implemented.";
}

void Light::print() {
	std::cout << "<Light (" << this->color << ")>";
}

std::string Light::__repr__() {
	return "<Light (" + this->color.__repr__() + ")>";
}

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
	// std::cout << "PointLight.calculateDiffuse" << this->position << std::endl;
	Ray to_light = Ray(hit_pos, this->position-hit_pos);
	Color change = material.color * material.diffuse * std::max(hit_normal.dot(to_light.direction), 0.0L);
	// std::cout << "Change: " << change << std::endl;
	return change;
}

Color PointLight::calculateSpecular(Vector3D hit_pos, Material material, Vector3D hit_normal, Vector3D to_cam, double specular_k) {
	// Blinn-Phong model
	// std::cout << "PointLight.calculateSpecular" << this->position << std::endl;
	Ray to_light = Ray(hit_pos, this->position-hit_pos);
	Vector3D half_vector = (to_light.direction + to_cam).normalize();
	Color change = this->color * material.specular * pow(std::max(hit_normal.dot(half_vector), 0.0L), specular_k);
	// std::cout << "Change: " << change << std::endl;
	return change;
}

void PointLight::print() {
	std::cout << "<PointLight (" << this->color << ", " << this->position << ")>";
}

std::string PointLight::__repr__() {
	return "<PointLight (" + this->color.__repr__() + this->position.__repr__() + ")>";
}

std::ostream &operator<<(std::ostream &output, const PointLight& pl) {
	return output << "<PointLight (" << pl.color << ", " << pl.position << ")>";
}