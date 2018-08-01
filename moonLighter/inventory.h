#pragma once
#include "gameNode.h"
#include "item.h"
#include "potion.h"
#include "liquidItem.h"
#include "redCristal.h"
#include "twig.h"
#include "rebar.h"
#include "golemCore.h"
#include "player.h"

// csyADD [�κ��丮 ��� - �κ��丮 ���� ���ÿ� �ڽ�&�̹��� ���� ]

class inventory : public gameNode
{
	map<itemType::Enum, vector<item*>> _mItem;		//���� �̿��� ������ ���
	typedef map<itemType::Enum, vector<item*>>::iterator mItemIter;		// ���� �̿��� ������ �ݺ���

	image* _invenImg;
	image* _slotImg;
	bool _openInven; // �κ��� ���ȴ��� �����ϴ� �Լ�
	bool _onceOpen;	// I�� ������ �� �ѹ��� �����ϰ� �ҷ��� �ߴµ� ���� �ʿ���?
	int _slotNum;
	RECT _invenSlot[20];
	RECT _selectSlot;
	
	tagFloat _invenPos[20];

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

