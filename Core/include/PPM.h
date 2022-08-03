#pragma once
#include <fstream>
#include <iostream>
#include "Vec3/Vec3.h"

class PPM
{
public:

	PPM(const int& height, const int& width);
	~PPM();

	struct RGB
	{
		lm::vec3 color;
	};

	void set_width(const int& width);
	void set_height(const int& height);
	void set_version(const std::string& version);

	void save(const std::string& name) const;
	void read(const std::string& name);

	void delete_image() const;

	RGB** image = nullptr;

private:

	int width = 0;
	int height = 0;
	std::string version = "P3";

	void create_image();
};