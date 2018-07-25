#pragma once
#include "item.h"

// csyADD [rebar 클래스의 init,release,update,render 생성]

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

