#pragma once
#include "item.h"

// csyADD [twig 클래스의 init,release,update,render 생성]

class twig :
	public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	twig() {}
	~twig() {}
};

