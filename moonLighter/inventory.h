#pragma once
#include "gameObject.h"

// csyADD [�κ��丮 Ŭ���� �߰�]

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

