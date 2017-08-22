#include "image.h"

bool contain(const Image& value, const Image& pack)
{
	return value.width() <= pack.width() && value.height() <= pack.height();
}

void copy(const Image& src, Image& dst)
{
	if (src.width() != dst.width() || src.height() != dst.height())
		return;

	const auto imgHeight = src.height();
	const auto imgWidth = src.width();
	for (auto height = 0; height < imgHeight; ++height)
	{
		for (auto width = 0; width < imgWidth; ++width)
		{
			unsigned char color[3];
			color[0] = src(width, height, 0);
			color[1] = src(width, height, 1);
			color[2] = src(width, height, 2);
			dst.draw_point(width, height, color);
		}
	}
}

void copy(const Image& src, Image& dst, int x_offset, int y_offset)
{
	if (!contain(src, dst))
		return;

	const auto endX = src.width() + x_offset;
	const auto endY = src.height() + y_offset;

	if (endX > dst.width() || endY > dst.height())
		return;

	const auto imgHeight = src.height();
	const auto imgWidth = src.width();
	for (auto height = 0; height < imgHeight; ++height)
	{
		for (auto width = 0; width < imgWidth; ++width)
		{
			unsigned char color[3];
			color[0] = src(width, height, 0);
			color[1] = src(width, height, 1);
			color[2] = src(width, height, 2);
			dst.draw_point(width + x_offset, height + y_offset, color);
		}
	}
}

void fillPixel(Image& img, unsigned char color[3])
{
	const auto imgHeight = img.height();
	const auto imgWidth = img.width();
	for (auto height = 0; height < imgHeight; ++height)
	{
		for (auto width = 0; width < imgWidth; ++width)
		{
			img.draw_point(width, height, color);
		}
	}
}

void fillPixel(Image& img, const Rect& rc, unsigned char color[3])
{
	for (auto height = rc.t; height <= rc.b; ++height)
	{
		for (auto width = rc.l; width <= rc.r; ++width)
		{
			img.draw_point(width, height, color);
		}
	}
}