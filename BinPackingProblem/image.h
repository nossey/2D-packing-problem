#pragma once
#include "CImg.h"
#include "rect.h"

typedef  cimg_library::CImg<unsigned char> Image;

bool contain(const Image& value, const Image& packer);
void copy(const Image& src, Image& dst);
void copy(const Image& src, Image& dst, int x_offset, int y_offset);
void fillPixel(Image& img, unsigned char color[3]);
void fillPixel(Image& img, const Rect& rc, unsigned char color[3]);