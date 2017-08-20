#pragma once

#define SAFE_DELETE(ptr)\
	delete(ptr);\
	ptr = nullptr;