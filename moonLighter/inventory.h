#pragma once
#include "gameObject.h"
#include "item.h"

// csyADD [�κ��丮 Ŭ���� �߰� / additem�Լ� �߰� (������ ȹ��� �κ��丮�� �־��ִ� �Լ�)]

class inventory : public gameObject
{
	//item* _item;
	vector<item*> _vIvenItem;
	
public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void addItem(item* _invenitem);

	inventory() {}
	~inventory() {}
};

