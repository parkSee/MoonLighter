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
	image* _door[9];
	int _doorCurrentX[9];
	int _doorCurrentY[9];
	int _doorCount[9];
	bool _doorBool[9];
	int _deadCount;
	bool _doorSound[5];
	bool _tempDoorSound[5];

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

