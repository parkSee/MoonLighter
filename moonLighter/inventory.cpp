#include "stdafx.h"
#include "inventory.h"

// csyADD [인벤토리 cpp - additem함수 내용 추가 (아이템 획득시 인벤토리에 넣어주는 함수)]

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

void inventory::addItem(item * _invenitem)
{
	_vIvenItem.push_back(_invenitem);
}

