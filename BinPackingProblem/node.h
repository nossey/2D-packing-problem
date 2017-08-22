#pragma once

#include "image.h"
#include "rect.h"

const int INVALID_NODE_ID = 0;

class Node
{
public:
	Node();
	~Node();

	Node* insert(const Image& img);

	const Rect& getRect() const;
	void setRect(Rect rc);
	int getID() const;
	void setID(int id);
	bool isUsed() const;
	void setUsed(bool flag);

	Node* getParent();
	Node* getLeftChild();
	Node* getRightChild();
	bool isLeaf() const;
	bool isChildrenEmpty();
private:
	Node* mParentNode;
	Node* mChildNode[2];
	Rect mRect;
	int mID;
	bool mUsed;
};