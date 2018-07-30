#pragma once
#include "gameObject.h"
#include "item.h"

// csyADD [인벤토리 클래스 추가 / 아이템을 벡터가 아닌 맵으로 담도록 수정 (함수도 맵의 키를 받도록)]

class inventory : public gameObject
{
	map<itemType::Enum, vector<item*>> _mItem;		//맵을 이용한 아이템 목록
	typedef map<itemType::Enum, vector<item*>>::iterator mItemIter;		// 맵을 이용한 아이템 반복자
	
public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void addItem(itemType::Enum _itemType, item* _item);

	inventory() {}
	~inventory() {}
};

