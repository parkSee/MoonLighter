#pragma once
#include "item.h"

// csyADD [redCristal 클래스의 init,release,update,render 생성]

class redCristal :
	public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	redCristal() {}
	~redCristal() {}
};

