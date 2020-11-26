#include "renderer.h"

Image render(Vector3D camera, std::vector<Sphere> objects, std::vector<Light*> lights, int width, int height) {
	double aspect_ratio = double(width) / height;
	Image image = Image(width, height, 255);

	// std::cout << "AR: " << aspect_ratio << std::endl;

	double x0 = -1.0, x1 = 1.0;
	double xstep = (x1 - x0) / (width - 1.0);
	double y0 = -1.0 / aspect_ratio, y1 = 1.0 / aspect_ratio;
	double ystep = (y1 - y0) / (height - 1.0);

	// std::cout << "Lights: " << std::endl;
	// lights[0]->print();
	// std::cout << std::endl;
	// lights[1]->print();
	// std::cout << std::endl;

	for (int i = 0; i < height; i++) {
		double y = y0 + i * ystep;
		for (int j = 0; j < width; j++) {
			double x = x0 + j * xstep;
			// std::cout << j << " " << i << std::endl;
			Ray ray = Ray(camera, Vector3D(x, y, 0) - camera);
			// std::cout << "Created ray" << std::endl;
			Color color = ray_trace(ray, objects, camera, lights);
			// std::cout << "Ray trace done: " << color << std::endl;
			image.setPixel(j, i, color);
			// std::cout << "Pixel set" << std::endl;
		}
	}
	return image;
}

Color ray_trace(Ray ray, std::vector<Sphere> objects, Vector3D camera, std::vector<Light*> lights) {
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
	return color_at(object_hit, hit_pos, objects, camera, lights);
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