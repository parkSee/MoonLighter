#include "stdafx.h"
#include "inventory.h"

// csyADD [인벤토리 cpp - additem함수 내용 수정 (벡터x 맵 사용o)]

HRESULT inventory::init(string _objName, tagFloat _pos)
{
	//_item = new item;

	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
}

void inventory::render()
{
}

void inventory::addItem(itemType::Enum _itemType, item* _item)
{

	vector<item*> temp;
	if (_itemType == itemType::GOLEMCORE)
	{
		temp.push_back(_item);
	}
	_mItem.insert(make_pair(_itemType, temp));

}