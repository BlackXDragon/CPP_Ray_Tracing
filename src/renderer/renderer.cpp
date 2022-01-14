#include "renderer.h"

Image render(Vector3D camera, std::vector<Sphere> objects, std::vector<Light*> lights, int width, int height, int reflection_depth) {
	double aspect_ratio = double(width) / height;
	Image image = Image(width, height, 255);

	// std::cout << "AR: " << aspect_ratio << std::endl;

#ifdef THREADING
	unsigned int n = std::thread::hardware_concurrency();

	std::cout << "Using " << n << " threads." << std::endl;

	thread_pool* pool = new thread_pool();
#endif

	double x0 = -1.0, x1 = 1.0;
	double xstep = (x1 - x0) / (width - 1.0);
	double y0 = -1.0 / aspect_ratio, y1 = 1.0 / aspect_ratio;
	double ystep = (y1 - y0) / (height - 1.0);

	// std::cout << "Lights: " << std::endl;
	// lights[0]->print();
	// std::cout << std::endl;
	// lights[1]->print();
	// std::cout << std::endl;

#ifndef THREADING
	auto begin = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < height; i++) {
		double y = y0 + i * ystep;
		for (int j = 0; j < width; j++) {
			double x = x0 + j * xstep;
			// std::cout << j << " " << i << std::endl;
			Ray ray = Ray(camera, Vector3D(x, y, 0) - camera);
			// std::cout << "Created ray" << std::endl;
			image.setPixel(j, i, ray_trace(ray, objects, camera, lights, reflection_depth, 1));
			// std::cout << "Ray trace done: " << color << std::endl;
			// image.setPixel(j, i, color);
			// std::cout << "Pixel set" << std::endl;
		}
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::cout << "Time taken without threading: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;

#else

	auto begin = std::chrono::high_resolution_clock::now();

	std::vector<std::future<Color>> futures;

	for (int i = 0; i < height; i++) {
		double y = y0 + i * ystep;
		for (int j = 0; j < width; j++) {
			double x = x0 + j * xstep;
			// std::cout << j << " " << i << std::endl;
			Ray ray = Ray(camera, Vector3D(x, y, 0) - camera);
			// std::cout << "Created ray" << std::endl;
			futures.push_back(pool->submit(ray_trace, ray, objects, camera, lights, reflection_depth, 1));
			// std::cout << "Ray trace done: " << color << std::endl;
			// image.setPixel(j, i, color);
			// std::cout << "Pixel set" << std::endl;
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			image.setPixel(j, i, futures[i * width + j].get());
		}
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::cout << "Time taken with threading: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
#endif

	return image;
}

Color ray_trace(Ray ray, std::vector<Sphere> objects, Vector3D camera, std::vector<Light*> lights, int reflection_depth, int depth) {
	Color color = Color();
	double dist_hit;
	Sphere object_hit;
	bool success = false;
	find_nearest(ray, objects, &dist_hit, &object_hit, &success);
	// std::cout << "Find nearest done." << std::endl;
	if (!success) {
		return color;
	}
	Vector3D hit_pos = ray.origin + ray.direction * dist_hit;
	color = color_at(object_hit, hit_pos, objects, camera, lights);
	if (depth < reflection_depth) {
		Vector3D hit_normal = object_hit.normal(hit_pos);
		double c1 = - ray.direction.dot(hit_normal);
		Vector3D refl_ray_pos = hit_pos + hit_normal * 0.0001;
		Vector3D refl_ray_dir = ray.direction + hit_normal * 2.0 * c1;
		Vector3D refr_ray_pos = hit_pos - hit_normal * 0.0001;
		double n = find_refr_index(objects, refl_ray_pos) / find_refr_index(objects, refr_ray_pos);
		double c2 = sqrt(1 - n*n * (1 - c1*c1));
		Vector3D refr_ray_dir = ray.direction * n - hit_normal * (n * c1 - c2);
		color += ray_trace(Ray(refl_ray_pos, refl_ray_dir), objects, camera, lights, reflection_depth, depth+1)  * object_hit.material.reflection;
		color += ray_trace(Ray(refr_ray_pos, refr_ray_dir), objects, camera, lights, reflection_depth, depth+1)  * object_hit.material.refraction;
	}
	return color;
}

double find_refr_index(std::vector<Sphere> objects, Vector3D position) {
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i].in_object(position))
			return objects[i].material.refr_ind;
	}
	return 1;
}

void find_nearest(Ray ray, std::vector<Sphere> objects, double *dist_hit, Sphere *object_hit, bool *success) {
	double dist_min = 99999;
	Sphere obj_hit;
	// std::cout << "Finding nearest object" << std::endl;
	for (int i = 0; i < objects.size(); i++) {
		double dist = objects[i].intersects(ray);
		// std::cout << "Object: " << objects[i] << " dist: " << dist << std::endl;
		if (dist != -1 && (dist < dist_min || !*success)) {
			dist_min = dist;
			obj_hit = objects[i];
			*success = true;
		}
	}
	// std::cout << "Nearest: " << dist_min << " " << obj_hit << std::endl;
	*dist_hit = dist_min;
	*object_hit = obj_hit;
}

Color color_at(Sphere object_hit, Vector3D hit_pos, std::vector<Sphere> objects, Vector3D camera, std::vector<Light*> lights) {
	// std::cout << object_hit << std::endl;
	// return object_hit.material.color;
	Vector3D hit_normal = object_hit.normal(hit_pos);
	Color color = Color("#000000") * object_hit.material.ambient, obj_color = object_hit.material.color;
	Vector3D to_cam = camera - hit_pos;
	for (int i = 0; i < lights.size(); i++) {
		// std::cout << "Light " << i << std::endl;
		color += lights[i]->calculateDiffuse(hit_pos, object_hit.material, hit_normal);
		color += lights[i]->calculateSpecular(hit_pos, object_hit.material, hit_normal, to_cam, 50);
	}
	// std::cout << color << std::endl;
	return color;
}