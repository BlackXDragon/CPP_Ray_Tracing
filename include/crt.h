#include <vector3d.h>
#include <color.h>
#include <ray.h>
#include <material.h>
#include <image.h>
#include <objects/sphere.h>
#include <lights/light.h>
#include <read_config.h>

#if SPEEDUP==2
	#include <renderer_cuda.h>
#else
	#include <renderer.h>
#endif