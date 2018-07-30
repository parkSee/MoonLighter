#pragma once
#include "item.h"


class redCristal : public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	redCristal() {}
	~redCristal() {}
};

