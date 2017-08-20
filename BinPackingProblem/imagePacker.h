#pragma once

#include "image.h"
#include "hashAccessor.h"
#include <string>

class Node;
const s32 DummyID = 0;

class ImagePacker
{
public:
	ImagePacker();
	~ImagePacker();

	bool insert(const Image& img, int& id);
	void save(const std::string& path);
	bool unregister(int id);
private:
private:
	Node* mRootNodePtr;
	Image mImage;
	HashAccessor<Node> mAccessor;
	void deleteNode(Node* nodePtr);
};