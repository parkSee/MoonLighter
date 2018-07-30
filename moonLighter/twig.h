#pragma once
#include "item.h"

class twig : public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	twig() {}
	~twig() {}
};

