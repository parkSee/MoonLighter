#pragma once
#include "gameNode.h"
#include "player.h"

#include "AIKids.h"
#include "AIGirl.h"
#include"AILink.h"
#include "furnitureContainer.h"
#include "inventory.h"


class shopScene : public gameNode
{
private:

	player * _player;
	RECT _enterRc;


	AIKids* _aiKid;
	AILink* _aiLink;
	AIGirl* _aiGirl;

	inventory* _inven;
	furnitureContainer* _furniture;
	image* _counter;
	image* _display;

	image* _buttonUi;
	image* _buttonAction;

	image* _jButton;

	int _exitCount;
	bool _isExit , _isOpen;

	int _count, _index;
	int _index2;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	void uiFrame();
	void buttonActionFrame();

	shopScene(){}
	~shopScene(){}
};

