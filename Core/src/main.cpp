#include "../include/main.h"

lm::vec3 rayCalc(const Ray& r)
{
	lm::vec3 unit_direction = r.getDirection().normalized();
	float t = 0.5f * (unit_direction.Y() + 1.0f);

	return (1.0f - t) * lm::vec3(1.0f, 1.0f, 1.0f) + t * lm::vec3(0.5f, 0.7f, 1.0f);
}

int main()
{
	const int height = 1000;
	const int width = 2000;

	PPM ppm1(height, width);

	lm::vec3 lowLeftCorn(-2.0f, -1.0f, -1.0f);
	lm::vec3 horizontal(4.0f, 0.0f, 0.0f);
	lm::vec3 vertical(0.0f, 2.0f, 0.0f);
	lm::vec3 origin = lm::vec3::zero;

	for (int i = height - 1; i >= 0; i--)
		for (int j = 0; j < width; j++)
		{
			float u = float(i) / float(height);
			float v = float(i) / float(width);

			Ray r(origin, lowLeftCorn + u * horizontal + v * vertical);

			ppm1.image[i][j].color = rayCalc(r) * 255;
		}

	ppm1.set_version("P3");
	ppm1.save("Output.ppm");

	return 0;
}