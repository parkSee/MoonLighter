#pragma once
#include "gameNode.h"

class player;
class inventory;

// csyADD [���� Ŭ���� �߰�]
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
	void subtractDisplay(int num); //csyADD ������ ���� �Լ�

	display(){}
	~display(){}
};

