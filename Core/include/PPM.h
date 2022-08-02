#pragma once
#include <fstream>
#include <iostream>
#include <cmath>

class PPM
{
public:

	PPM();
	PPM(int height, int width);
	~PPM();

	struct RGB
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
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