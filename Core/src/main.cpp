#include "../include/main.h"

int main()
{
	PPM ppm1(500, 1000);

	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 1000; j++)
		{
			ppm1.image[i][j].r = 10;
			ppm1.image[i][j].g = 50;
			ppm1.image[i][j].b = 120;
		}

	ppm1.set_version("P3");
	ppm1.save("Output.ppm");

	return 0;
}