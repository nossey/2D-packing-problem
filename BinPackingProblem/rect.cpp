#include "rect.h"
#include <cmath>


Rect::Rect() :
	l(0),
	r(0),
	t(0),
	b(0)
{
}

Rect::Rect(s32 left, s32 top, s32 right, s32 bottom) :
	l(left),
	t(top),
	r(right),
	b(bottom)
{
}

Rect::~Rect()
{
}

s32 Rect::getWidth() const
{
	return abs(r - l) + 1;
}

s32 Rect::getHeight() const
{
	return abs(b - t) + 1;
}
