#pragma once
#include "item.h"

// csyADD [rebar Ŭ������ init,release,update,render ����]

class rebar :
	public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	rebar() {}
	~rebar() {}
};

