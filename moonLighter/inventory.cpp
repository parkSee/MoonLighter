#include "stdafx.h"
#include "inventory.h"

// csyADD [�κ��丮 cpp - additem�Լ� ���� �߰� (������ ȹ��� �κ��丮�� �־��ִ� �Լ�)]

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

