#include "renderer.h"

Image render(Vector3D camera, std::vector<Sphere> objects, int width, int height) {
	double aspect_ratio = double(width) / height;
	Image image = Image(width, height, 255);

	// std::cout << "AR: " << aspect_ratio << std::endl;

	double x0 = -1.0, x1 = 1.0;
	double xstep = (x1 - x0) / (width - 1.0);
	double y0 = -1.0 / aspect_ratio, y1 = 1.0 / aspect_ratio;
	double ystep = (y1 - y0) / (height - 1.0);

	for (int i = 0; i < height; i++) {
		double y = y0 + i * ystep;
		for (int j = 0; j < width; j++) {
			double x = x0 + j * xstep;
			// std::cout << j << " " << i << std::endl;
			Ray ray = Ray(camera, Vector3D(x, y, 0) - camera);
			// std::cout << "Created ray" << std::endl;
			Color color = ray_trace(ray, objects);
			// std::cout << "Ray trace done: " << color << std::endl;
			image.setPixel(j, i, color);
			// std::cout << "Pixel set" << std::endl;
		}
	}
	return image;
}

Color ray_trace(Ray ray, std::vector<Sphere> objects) {
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
	return color_at(object_hit, hit_pos, objects);
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

Color color_at(Sphere object_hit, Vector3D hit_pos, std::vector<Sphere> objects) {
	return object_hit.color;
}