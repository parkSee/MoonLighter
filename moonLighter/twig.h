#pragma once
#include "item.h"

// csyADD [twig Ŭ������ init,release,update,render ����]

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

