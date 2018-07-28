#pragma once
#include "item.h"

class liquidItem : public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	liquidItem() {}
	~liquidItem() {}
};

