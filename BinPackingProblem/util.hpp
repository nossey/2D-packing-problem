#pragma once

#define SAFE_DELETE(ptr)\
	if (ptr != nullptr)\
		delete(ptr);\
		ptr = nullptr;