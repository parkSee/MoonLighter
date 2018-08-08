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
	
	RECT _enterRc[9];
	float _cameraDistance;
	bool _cameraMove;
	int _cameraMoveCount;

	float _vol;
public:


	HRESULT init();
	void release();
	void update();
	void render();

	void moveDungeon();

	dungeonScene(){}
	~dungeonScene(){}
};

