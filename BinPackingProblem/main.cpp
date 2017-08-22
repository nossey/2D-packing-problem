#include <iostream>
#include <string>
#include <random>
using namespace std;
#include "image.h"
#include "imagePacker.h"
#include "node.h"

namespace
{
	const string AtlasFileName = "result.bmp";
	const unsigned int GenerateBinCount = 1000;
	const unsigned int RandomlyDeleteNodeCount = 500;
	const unsigned int RandomSeed = 0;

	mt19937 GlobalMt(RandomSeed);
	uniform_int_distribution<int> ColorRange(0, 255);
	void RandomColor(unsigned char* color)
	{
		color[0] = ColorRange(GlobalMt);
		color[1] = ColorRange(GlobalMt);
		color[2] = ColorRange(GlobalMt);
	}


	template<typename Iter, typename RandomGenerator>
	Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
		std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
		std::advance(start, dis(g));
		return start;
	}

	template<typename Iter>
	Iter select_randomly(Iter start, Iter end) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		return select_randomly(start, end, gen);
	}
}

struct ImageHandle
{
	Image image;
	int id = 0;
};

void main()
{
	// Randomly create images whose width/height is 10-50.
	vector<ImageHandle> imageList;
	imageList.reserve(GenerateBinCount);
	mt19937 mt(RandomSeed);
	uniform_int_distribution<int> range(10, 50);

	for (int i = 0; i < GenerateBinCount; ++i)
	{
		Image img(range(mt), range(mt), 1, 3);
		unsigned char color[3];
		RandomColor(color);
		fillPixel(img, color);

		ImageHandle handle;
		handle.image = img;
		handle.id = 0;
		imageList.push_back(handle);
	}

	// Packing images
	// Image packer whose atlas image is 1024px width/height.
	ImagePacker packer(1024, 1024);
	for (auto& handle : imageList)
	{
		auto result = packer.insert(handle.image, handle.id);
		if (!result)
			break;
	}

	// Randomly unregister test
	//for (auto i = 0; i < RandomlyDeleteNodeCount; ++i)
	//{
	//	auto itr = select_randomly(imageList.begin(), imageList.end());
	//	packer.unregister(itr->id);
	//	imageList.erase(itr);
	//}

	packer.save(AtlasFileName);
	exit(0);
}