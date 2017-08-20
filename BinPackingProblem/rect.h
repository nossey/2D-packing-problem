#pragma once

class Rect
{
public:
	Rect();
	Rect(int l, int t, int r, int b);
	~Rect();

	int l, r, t, b;

	int getWidth() const;
	int getHeight() const;
};