#pragma once
#include "item.h"

// csyADD [redCristal Ŭ������ init,release,update,render ����]

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

