#pragma once
#include "item.h"


class rebar : public item
{
public:

	HRESULT init();
	void release();
	void update();
	void render();

	rebar() {}
	~rebar() {}
};

