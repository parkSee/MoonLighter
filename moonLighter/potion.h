#pragma once
#include "item.h"


class potion :	public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	potion(){}
	~potion(){}
};

