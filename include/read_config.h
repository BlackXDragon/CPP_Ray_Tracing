#if !defined(READ_CONFIG_H)
#define READ_CONFIG_H

#include <iostream>
#include <fstream>
#include <string>
#include <json.hpp>
#include <vector3d.h>
#include <color.h>
#include <ray.h>
#include <material.h>
#include <image.h>
#include <objects/sphere.h>
#include <lights/light.h>

void read_scene(std::string spath, Vector3D *camera, Sphere* **objects, int* n_objects, Light* **lights, int* n_lights, int *width, int *height);

#endif // READ_CONFIG_H
