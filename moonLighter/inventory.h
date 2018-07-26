#pragma once
#include "gameObject.h"
#include "item.h"

// csyADD [인벤토리 클래스 추가 / additem함수 추가 (아이템 획득시 인벤토리에 넣어주는 함수)]

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

