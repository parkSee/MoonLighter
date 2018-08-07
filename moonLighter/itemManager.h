#pragma once
#include "item.h"

class player;
class inventory;
class display;

class itemManager
{
private:

	vector<item*> _vItem;	

public:

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void appear(itemType::Enum type, tagFloat pos);
	void collision();

//	void ItemOnDisplay();
//	void DisplayRender();

	itemManager() {}
	~itemManager() {}
};

