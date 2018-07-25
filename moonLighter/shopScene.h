#pragma once
#include "gameNode.h"
#include "player.h"

class shopScene : public gameNode
{
private:

	player * _player;

public:

	HRESULT init();
	void release();
	void update();
	void render();


	shopScene(){}
	~shopScene(){}
};

