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
	

	vector<item*> _vDisplayItem;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	vector<item*> get_vDisplayItem() { return _vDisplayItem; }

	void addDisplayItem(item* _item);
	void subtractDisplay(int num); //csyADD ������ ���� �Լ�

	display(){}
	~display(){}
};

