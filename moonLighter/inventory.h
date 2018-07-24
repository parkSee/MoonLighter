#pragma once
#include "gameObject.h"
#include "item.h"

// csyADD [인벤토리 클래스 추가]

class inventory : public gameObject
{
	vector<item*> _vIvenItem;


public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void addItem();

	inventory() {}
	~inventory() {}
};

