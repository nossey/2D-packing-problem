#pragma once

#include "trivial.hpp"
#include "image.h"
#include "rect.h"

const s32 INVALID_NODE_ID = 0;

class Node
{
public:
	Node();
	~Node();

	Node* insert(const Image& img);

	const Rect& getRect() const;
	void setRect(Rect rc);
	s32 getID() const;
	void setID(s32 id);
	bool isUsed() const;

	Node* getParent();
	Node* getLeftChild();
	Node* getRightChild();
	bool isLeaf() const;
private:
	Node* mParentNode;
	Node* mChildNode[2];
	Rect mRect;
	s32 mID;
	bool mUsed;

	void setUsed(bool flag);
};