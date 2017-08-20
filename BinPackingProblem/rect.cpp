#include "rect.h"
#include <cmath>


Rect::Rect() :
	l(0),
	r(0),
	t(0),
	b(0)
{
}

Rect::Rect(int left, int top, int right, int bottom) :
	l(left),
	t(top),
	r(right),
	b(bottom)
{
}

Rect::~Rect()
{
}

int Rect::getWidth() const
{
	return abs(r - l) + 1;
}

int Rect::getHeight() const
{
	return abs(b - t) + 1;
}
