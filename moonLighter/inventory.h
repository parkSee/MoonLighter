#pragma once
#include "gameNode.h"
#include "item.h"
#include "player.h"

// csyADD [�κ��丮 Ŭ���� �߰� / �������� ���Ͱ� �ƴ� ������ �㵵�� ���� (�Լ��� ���� Ű�� �޵���)]

class inventory : public gameNode
{
	map<itemType::Enum, vector<item*>> _mItem;		//���� �̿��� ������ ���
	typedef map<itemType::Enum, vector<item*>>::iterator mItemIter;		// ���� �̿��� ������ �ݺ���

	image* _invenImg;
	bool _openInven;
	bool _onceOpen;
	RECT _invenSlot[20];

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void set_openInven(bool _showInven) { _openInven = _showInven; }	// �κ� ��� �׽�Ʈ�� 
	bool get_openInven() { return _openInven; }							// �κ� ��� �׽�Ʈ��
	void set_onceOpen(bool _keyOnceDown) { _onceOpen = _keyOnceDown; }	// �κ� ��� �׽�Ʈ��
	bool get_onceOpen() { return _onceOpen; }							// �κ� ��� �׽�Ʈ��

	void addItem(itemType::Enum _itemType, item* _item);

	inventory() {}
	~inventory() {}
};

