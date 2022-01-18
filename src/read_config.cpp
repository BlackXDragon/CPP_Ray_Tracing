#include "read_config.h"

void read_scene(std::string spath, Vector3D *camera, Sphere* **objects, int* n_objects, Light* **lights, int* n_lights, int *width, int *height) {
	std::ifstream sceneFile(spath);
	nlohmann::json j;
	sceneFile >> j;

	if (j["camera"].is_null() || (j["camera"].size() != 3)) {
		std::cout << "No or invalid camera config found (" << j["camera"] << "). Using default (0, 0, -1)." << std::endl;
		*camera = Vector3D(0, 0, -1);
	} else {
		nlohmann::json camjson = j["camera"];
		*camera = Vector3D(camjson[0], camjson[1], camjson[2]);
	}
	if (j["resolution"].is_null() || (j["resolution"].size() != 2)) {
		std::cout << "No or invalid resolution config found (" << j["resolution"] << "). Using default (1280x720)." << std::endl;
		*width = 1280;
		*height = 720;
	} else {
		nlohmann::json resjson = j["resolution"];
		*width = resjson[0];
		*height = resjson[1];
	}
	if (j["objects"].is_null() || (j["objects"].size() < 1)) {
		std::cout << "No objects found in the config file!" << std::endl;
	} else {
		nlohmann::json objson = j["objects"];
		*objects = (Sphere**)malloc(sizeof(Sphere*) * objson.size());
		*n_objects = 0;
		
		for (int i = 0; i < objson.size(); i++) {
			Vector3D center;
			if (!objson[i]["center"].is_null() && (objson[i]["center"].size() == 3))
				center = Vector3D(objson[i]["center"][0], objson[i]["center"][1], objson[i]["center"][2]);
			double radius = 0;
			if (objson[i]["radius"].is_number())
				radius = objson[i]["radius"];
			Material m;
			if (!objson[i]["material"].is_null()) {
				nlohmann::json matjson = objson[i]["material"];
				if (matjson["color"].is_string()) {
					assert(matjson["color"].get<std::string>().substr(0, 1) == "#");
					m.color = Color(matjson["color"].get<std::string>().c_str());
				} else if (matjson["color"].is_array() && (matjson["color"].size() == 3)) {
					m.color = Color(matjson["color"][0], matjson["color"][1], matjson["color"][2]);
				} else {
					m.color = Color();
				}
				if (matjson["ambient"].is_number()) {
					m.ambient = matjson["ambient"];
				} else {
					m.ambient = 0;
				}
				if (matjson["diffuse"].is_number()) {
					m.diffuse = matjson["diffuse"];
				} else {
					m.diffuse = 0;
				}
				if (matjson["specular"].is_number()) {
					m.specular = matjson["specular"];
				} else {
					m.specular = 0;
				}
				if (matjson["reflection"].is_number()) {
					m.reflection = matjson["reflection"];
				} else {
					m.reflection = 0;
				}
				if (matjson["refraction"].is_number()) {
					m.refraction = matjson["refraction"];
				} else {
					m.refraction = 0;
				}
				if (matjson["refr_ind"].is_number()) {
					m.refr_ind = matjson["refr_ind"];
				} else {
					m.refr_ind = 0;
				}
			}
			(*objects)[*n_objects] = new Sphere(center, radius, m);
			(*n_objects)++;
		}
	}
	if (j["lights"].is_null() || (j["lights"].size() < 1)) {
		std::cout << "No lights found in the config file!" << std::endl;
	} else {
		nlohmann::json ltjson = j["lights"];
		*lights = (Light**)malloc(sizeof(Light*)*ltjson.size());
		*n_lights = 0;
		
		for (int i = 0; i < ltjson.size(); i++) {
			if (ltjson[i]["type"] == "point") {
				Vector3D position;
				if (!ltjson[i]["position"].is_null() && (ltjson[i]["position"].size() == 3))
					position = Vector3D(ltjson[i]["position"][0], ltjson[i]["position"][1], ltjson[i]["position"][2]);
				Color color;
				if (ltjson[i]["color"].is_string()) {
					assert(ltjson[i]["color"].get<std::string>().substr(0, 1) == "#");
					color = Color(ltjson[i]["color"].get<std::string>().c_str());
				} else if (ltjson[i]["color"].is_array() && (ltjson[i]["color"].size() == 3)) {
					color = Color(ltjson[i]["color"][0], ltjson[i]["color"][1], ltjson[i]["color"][2]);
				} else {
					color = Color();
				}
				(*lights)[*n_lights] = new PointLight(color, position);
				(*n_lights)++;
			}
			else if (ltjson[i]["type"] == "directional") {
				Vector3D direction;
				if (!ltjson[i]["direction"].is_null() && (ltjson[i]["direction"].size() == 3))
					direction = Vector3D(ltjson[i]["direction"][0], ltjson[i]["direction"][1], ltjson[i]["direction"][2]);
				Color color;
				if (ltjson[i]["color"].is_string()) {
					assert(ltjson[i]["color"].get<std::string>().substr(0, 1) == "#");
					color = Color(ltjson[i]["color"].get<std::string>().c_str());
				} else if (ltjson[i]["color"].is_array() && (ltjson[i]["color"].size() == 3)) {
					color = Color(ltjson[i]["color"][0], ltjson[i]["color"][1], ltjson[i]["color"][2]);
				} else {
					color = Color();
				}
				(*lights)[*n_lights] = new PointLight(color, direction);
				(*n_lights)++;
			}
		}
	}
}