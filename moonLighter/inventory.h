#pragma once
#include "gameNode.h"

class inventory : public gameNode
{
private:
	vector<item*> _vInvenItem;

	image* _invenImg;
	image* _slotImg;
	bool _openInven; // 인벤이 열렸는지 구분하는 함수
	RECT _invenSlot[20];
	RECT _selectSlot;
	int _slotNum;
	tagFloat _invenPos[20];

public:

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void set_openInven(bool _showInven) { _openInven = _showInven; }
	bool get_openInven() { return _openInven; }
	tagFloat* get_invenPos() { return _invenPos; }
	vector<item*> get_vInvenItem() { return _vInvenItem; }

	void addInven(item* _item);
	void subtractInven(int num); //csyADD 아이템 뺴는 함수

	inventory() {}
	~inventory() {}
};
