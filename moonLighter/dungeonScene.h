#pragma once
#include "gameNode.h"
#include "enemyController.h"
#include "player.h"
class dungeonScene : public gameNode
{

private:

	player * _player;
	enemyController * _em;

public:


	HRESULT init();
	void release();
	void update();
	void render();



	dungeonScene(){}
	~dungeonScene(){}
};

