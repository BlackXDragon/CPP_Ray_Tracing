#if !defined(READ_CONFIG_H)
#define READ_CONFIG_H

#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "renderer.h"

void read_scene(std::string spath, Vector3D *camera, std::vector<Sphere> *objects, std::vector<Light*> *lights, int *width, int *height);

#endif // READ_CONFIG_H
