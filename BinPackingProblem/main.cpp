#include <iostream>
#include <string>
#include <random>
using namespace std;

#include "trivial.hpp"
#include "image.h"
#include "imagePacker.h"
#include "node.h"

namespace
{
	const string AtlasFileName = "result.bmp";
	const u32 GenerateBinCount = 1000;
	const u32 InitialSeed = 10;

	mt19937 GlobalMt(InitialSeed);
	uniform_int_distribution<int> ColorRange(0, 255);
	void RandomColor(unsigned char* color)
	{
		color[0] = ColorRange(GlobalMt);
		color[1] = ColorRange(GlobalMt);
		color[2] = ColorRange(GlobalMt);
	}
}

void main()
{
	vector<Image> imageList;
	imageList.reserve(GenerateBinCount);
	mt19937 mt(InitialSeed);
	uniform_int_distribution<int> range(10, 50);

	// Generate bins to be packed
	for (u32 i = 0; i < GenerateBinCount; ++i)
	{
		Image img(range(mt), range(mt), 1, 3);
		unsigned char color[3];
		RandomColor(color);
		fillPixel(img, color);
		imageList.push_back(img);
	}

	ImagePacker packer;
	int id = 0;
	for (auto& img : imageList)
	{
		auto result = packer.insert(img, id);
		if (!result)
			break;
	}

	packer.save("result.bmp");
	exit(0);
}