#pragma once
#include "gameNode.h"
#include "item.h"
#include "player.h"

// csyADD [인벤토리 클래스 추가 / 아이템을 벡터가 아닌 맵으로 담도록 수정 (함수도 맵의 키를 받도록)]

class inventory : public gameNode
{
	map<itemType::Enum, vector<item*>> _mItem;		//맵을 이용한 아이템 목록
	typedef map<itemType::Enum, vector<item*>>::iterator mItemIter;		// 맵을 이용한 아이템 반복자

	image* _invenImg;
	bool _openInven;
	bool _onceOpen;
	RECT _invenSlot[20];

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

