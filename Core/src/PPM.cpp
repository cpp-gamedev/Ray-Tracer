#include "../include/PPM.h"

PPM::PPM(int height, int width)
{
	set_height(height);
	set_width(width);

	create_image();
}

PPM::~PPM()
{
	delete_image();
}

void PPM::set_width(const int& width)
{
	this->width = width;
}

void PPM::set_height(const int& height)
{
	this->height = height;
}

void PPM::set_version(const std::string& version)
{
	this->version = version;
}

void PPM::save(const std::string& name) const
{
	std::ofstream output(name, std::ios::binary);

	if (output.is_open())
	{
		output << version << std::endl;
		output << width << std::endl;
		output << height << std::endl;
		output << 255 << std::endl;

		if (version == "P3")
		{
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
				{
					output << (int)image[i][j].r << ' ';
					output << (int)image[i][j].g << ' ';
					output << (int)image[i][j].b << '\n';
				}
		}

		else
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
					output.write((char*)&image[i][j], sizeof(RGB));

		output.close();
	}
}

void PPM::read(const std::string& name)
{
	std::ifstream input(name, std::ios::binary);

	if (input.is_open())
	{
		int color;
		char ver[3];

		input.read(ver, 2);
		version = ver;
		input >> width;
		input >> height;
		input >> color;
		input.read(ver, 1);

		create_image();

		int box;

		if (version == "P3")
		{
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
				{
					input >> box;
					image[i][j].r = box;

					input >> box;
					image[i][j].g = box;

					input >> box;
					image[i][j].b = box;
				}
		}

		else
		{
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
					input.read((char*)&image[i][j], sizeof(RGB));
		}

		input.close();
	}
}

void PPM::delete_image() const
{
	if (image != nullptr)
	{
		for (int i = 0; i < height; i++)
			delete image[i];

		delete image;
	}
}

void PPM::create_image()
{
	if (image != nullptr)
		delete_image();

	image = new RGB * [height];

	for (int i = 0; i < height; i++)
	{
		image[i] = new RGB[width];

		for (int j = 0; j < width; j++)
		{
			image[i][j].r = 255;
			image[i][j].g = 255;
			image[i][j].b = 255;
		}
	}
}
