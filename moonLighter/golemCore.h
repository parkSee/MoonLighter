#pragma once
#include "item.h"

class golemCore : public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	golemCore() {}
	~golemCore() {}
};

