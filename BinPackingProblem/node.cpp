#include "node.h"
#include "util.hpp"

namespace
{
	bool contain(const Image& img, const Rect& rect)
	{
		return img.width() <= rect.getWidth() && img.height() <= rect.getHeight();
	}

	bool fitPerfect(const Image& img, const Rect& rect)
	{
		return img.width() == rect.getWidth() && img.height() == rect.getHeight();
	}

}

Node::Node() :
	mRect(0, 0, 0, 0),
	mID(INVALID_NODE_ID),
	mUsed(false)
{
	mChildNode[0] = mChildNode[1] = nullptr;
}

Node::~Node()
{
	SAFE_DELETE(mChildNode[0]);
	SAFE_DELETE(mChildNode[1]);
}

bool Node::isLeaf() const
{
	return mChildNode[0] == nullptr && mChildNode[1] == nullptr;
}

Node* Node::insert(const Image& img)
{
	if (!isLeaf())
	{
		Node* newNodePtr;
		if (mChildNode[0] != nullptr)
			newNodePtr = mChildNode[0]->insert(img);

		if (newNodePtr != nullptr)
			return newNodePtr;

		return mChildNode[1]->insert(img);
	}
	else
	{
		if (isUsed())
			return nullptr;

		if (!contain(img, mRect))
			return nullptr;

		if (fitPerfect(img, mRect))
		{
			setUsed(true);
			return this;
		}

		mChildNode[0] = new Node();
		mChildNode[1] = new Node();

		mChildNode[0]->mParentNode = this;
		mChildNode[1]->mParentNode = this;

		const auto dw = mRect.getWidth() - img.width();
		const auto dh = mRect.getHeight() - img.height();

		if (dw > dh)
		{
			mChildNode[0]->mRect = Rect(mRect.l, mRect.t, mRect.l + img.width() - 1, mRect.b);
			mChildNode[1]->mRect = Rect(mRect.l + img.width(), mRect.t, mRect.r, mRect.b);
		}
		else
		{
			mChildNode[0]->mRect = Rect(mRect.l, mRect.t, mRect.r, mRect.t + img.height() - 1);
			mChildNode[1]->mRect = Rect(mRect.l, mRect.t + img.height(), mRect.r, mRect.b);
		}

		return mChildNode[0]->insert(img);
	}

	return nullptr;
}

const Rect& Node::getRect() const
{
	return mRect;
}

void Node::setRect(Rect rc)
{
	mRect = rc;
}

int Node::getID() const
{
	return mID;
}

void Node::setID(int id)
{
	mID = id;
}

bool Node::isUsed() const
{
	return mUsed;
}

void Node::setUsed(bool flag)
{
	mUsed = flag;
}

Node* Node::getParent()
{
	return mParentNode;
}

Node* Node::getLeftChild()
{
	return mChildNode[0];
}

Node* Node::getRightChild()
{
	return mChildNode[1];
}