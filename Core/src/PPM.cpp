#include "../include/PPM.h"

PPM::PPM(const int height, const int width)
{
	set_height(height);
	set_width(width);

	create_image();
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
					output << static_cast<int>(image[i][j].color.X()) << ' ';
					output << static_cast<int>(image[i][j].color.Y()) << ' ';
					output << static_cast<int>(image[i][j].color.Z()) << '\n';
				}
		}

		else
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
					output.write(reinterpret_cast<char*>(&image[i][j]), sizeof(RGB));
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
					image[i][j].color.X() = box;

					input >> box;
					image[i][j].color.Y() = box;

					input >> box;
					image[i][j].color.Z() = box;
				}
		}

		else
		{
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; j++)
					input.read(reinterpret_cast<char*>(&image[i][j]), sizeof(RGB));
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
			image[i][j].color = { 255, 255, 255 };
	}
}
