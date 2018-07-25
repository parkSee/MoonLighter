#pragma once
#include "item.h"

// csyADD [golemCore 클래스의 init,release,update,render 생성]

class golemCore :
	public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	golemCore() {}
	~golemCore() {}
};

