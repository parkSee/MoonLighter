#pragma once
#include "gameObject.h"
#include "item.h"

// csyADD [�κ��丮 Ŭ���� �߰�]

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

