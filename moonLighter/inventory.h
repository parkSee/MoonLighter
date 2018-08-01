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

// csyADD [인벤토리 헤더 - 인벤토리 슬롯 선택용 박스&이미지 선언 ]

class inventory : public gameNode
{
	map<itemType::Enum, vector<item*>> _mItem;		//맵을 이용한 아이템 목록
	typedef map<itemType::Enum, vector<item*>>::iterator mItemIter;		// 맵을 이용한 아이템 반복자

	image* _invenImg;
	image* _slotImg;
	bool _openInven; // 인벤이 열렸는지 구분하는 함수
	bool _onceOpen;	// I가 눌렸을 때 한번만 오픈하게 할려고 했는데 굳이 필요해?
	int _slotNum;
	RECT _invenSlot[20];
	RECT _selectSlot;
	
	tagFloat _invenPos[20];

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void set_openInven(bool _showInven) { _openInven = _showInven; }	// 인벤 출력 테스트용 
	bool get_openInven() { return _openInven; }							// 인벤 출력 테스트용
	void set_onceOpen(bool _keyOnceDown) { _onceOpen = _keyOnceDown; }	// 인벤 출력 테스트용
	bool get_onceOpen() { return _onceOpen; }							// 인벤 출력 테스트용

	void addItem(itemType::Enum _itemType, item* _item);

	inventory() {}
	~inventory() {}
};

