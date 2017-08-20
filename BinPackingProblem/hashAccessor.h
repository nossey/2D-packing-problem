#pragma once
#include <map>
#include <iostream>

template <typename T>
class HashAccessor
{
private:
	std::map <int, T*> mDataBase;
public:
	HashAccessor()
	{}

	~HashAccessor()
	{
	}

	bool registerData(T* dataPtr, int& id)
	{
		if (dataPtr == nullptr)
			return false;

		auto hasher = hash<int>();
		int key = static_cast<int>(hasher(reinterpret_cast<int>(dataPtr)));
		mDataBase.insert({ key, dataPtr });
		id = key;
		return true;
	}

	bool unregisterData(int id)
	{
		auto* result = mDataBase[id];
		if (result == nullptr)
			return false;

		mDataBase.erase(id);
		return true;
	}

	T* getData(int id)
	{
		return mDataBase[id];
	}

	int getID(T* dataPtr)
	{
		if (dataPtr == nullptr)
		{
			cerr << "null data pointer, returns 0";
			return 0;
		}

		auto hasher = hash<int>();
		return static_cast<int>(hasher(reinterpret_cast<int>(dataPtr)));
	}
};
