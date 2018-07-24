#pragma once
#include "gameObject.h"

// csyADD [인벤토리 클래스 추가]

class inventory : public gameObject
{
public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	inventory() {}
	~inventory() {}
};

