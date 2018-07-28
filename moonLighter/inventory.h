#pragma once
#include "gameObject.h"
#include "item.h"

// csyADD [�κ��丮 Ŭ���� �߰� / �������� ���Ͱ� �ƴ� ������ �㵵�� ���� (�Լ��� ���� Ű�� �޵���)]

class inventory : public gameObject
{
	map<itemType::Enum, vector<item*>> _mItem;		//���� �̿��� ������ ���
	typedef map<itemType::Enum, vector<item*>>::iterator mItemIter;		// ���� �̿��� ������ �ݺ���
	
public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void addItem(itemType::Enum _itemType, item* _item);

	inventory() {}
	~inventory() {}
};

