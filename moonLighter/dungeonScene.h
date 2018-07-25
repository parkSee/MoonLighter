#pragma once
#include "gameNode.h"
#include "enemyController.h"
#include "player.h"
#include "itemManager.h"

class dungeonScene : public gameNode
{

private:


	player * _player;
	itemManager * _im;
	enemyController * _em;

public:


	HRESULT init();
	void release();
	void update();
	void render();



	dungeonScene(){}
	~dungeonScene(){}
};

