#pragma once
#include "gameNode.h"
#include "player.h"
#include"boss.h"
#include"progressBar.h"

class bossRoomScene : public gameNode
{
private:

	player * _player;
	progressBar* _bossHp;
	int _currentHp;

public:


	HRESULT init();
	void release();
	void update();
	void render();

	bossRoomScene(){}
	~bossRoomScene(){}
};

