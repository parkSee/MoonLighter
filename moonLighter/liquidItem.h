#pragma once
#include "item.h"

// csyADD [liquidItem Ŭ������ init,release,update,render ����]

class liquidItem :
	public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	liquidItem() {}
	~liquidItem() {}
};

