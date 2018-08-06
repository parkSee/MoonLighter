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
public:

	HRESULT init();
	void release();
	void update();
	void render();


	shopScene(){}
	~shopScene(){}
};

