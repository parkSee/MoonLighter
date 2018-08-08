#pragma once
#include "gameNode.h"

class player;
class inventory;

// csyADD [진열 클래스 추가]
class display : public gameNode
{
private:

	RECT _displaySlot[4];	
	//int _slotNum;
	//tagFloat _displayPos[4];
	RECT _salesTable;

	vector<item*> _vDisplayItem;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	vector<item*> get_vDisplayItem() { return _vDisplayItem; }

	void addDisplayItem(item* _item);
	void dp_SetActiveFalse(int num);
	void dp_SetActiveTrue(int num);
	void dp_setPos(int num);
	void subtractDisplay(int num); //csyADD 아이템 뺴는 함수

	display(){}
	~display(){}
};

