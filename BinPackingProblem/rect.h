#pragma once

#include "trivial.hpp"

class Rect
{
public:
	Rect();
	Rect(s32 l, s32 t, s32 r, s32 b);
	~Rect();

	s32 l, r, t, b;

	s32 getWidth() const;
	s32 getHeight() const;
};