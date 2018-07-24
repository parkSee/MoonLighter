#pragma once
#include "gameObject.h"

//csyADD [아이템 클래스 추가]

class item : public gameObject
{	

public:

	virtual HRESULT init(string _objName, tagFloat _pos);
	virtual void release();
	virtual void update();
	virtual void render();


	item() {}
	~item() {}
};

