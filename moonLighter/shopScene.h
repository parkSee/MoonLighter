#pragma once
#include "gameNode.h"
#include "player.h"

#include "AIKids.h"

#include "inventory.h"


class shopScene : public gameNode
{
private:

	player * _player;
	RECT _enterRc;


	AIKids* _aiKid;

	inventory* _inven;


public:

	HRESULT init();
	void release();
	void update();
	void render();


	shopScene(){}
	~shopScene(){}
};

