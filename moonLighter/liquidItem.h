#pragma once
#include "item.h"

// csyADD [liquidItem 클래스의 init,release,update,render 생성]

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

