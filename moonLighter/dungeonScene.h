#pragma once
#include "gameNode.h"
#include "player.h"
#include "enemyController.h"

class dungeonScene : public gameNode
{

private:


	enemyController * _em;

public:


	HRESULT init();
	void release();
	void update();
	void render();



	dungeonScene(){}
	~dungeonScene(){}
};

