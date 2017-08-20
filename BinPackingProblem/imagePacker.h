#pragma once

#include "image.h"
#include "hashAccessor.h"
#include <string>

class Node;
const int DummyID = 0;

class ImagePacker
{
public:
	ImagePacker();
	ImagePacker(unsigned int atlasWidth, unsigned int atlasHeight);
	~ImagePacker();

	bool insert(const Image& img, int& id);
	void save(const std::string& path);
	bool unregister(int id);
	Node* getNode(int id);
private:
private:
	Node* mRootNodePtr;
	Image mImage;
	HashAccessor<Node> mAccessor;
	void deleteNode(Node* nodePtr);
};