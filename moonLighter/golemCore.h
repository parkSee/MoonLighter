#pragma once
#include "item.h"

// csyADD [golemCore Ŭ������ init,release,update,render ����]

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

