#pragma once
#include "CImg.h"
#include "trivial.hpp"

typedef  cimg_library::CImg<unsigned char> Image;

bool contain(const Image& value, const Image& packer);
void copy(const Image& src, Image& dst);
void copy(const Image& src, Image& dst, s32 x_offset, s32 y_offset);
void fillPixel(Image& img, unsigned char color[3]);