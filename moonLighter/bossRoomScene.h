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
	progressBar* _test;
	boss* _boss;
	boss*_boss2;
	int _currentHp;
	int _dmgCount;
	bool _damaged;
	bool _dmgCountBool;
	bool _clone;
	

public:


	HRESULT init();
	void release();
	void update();
	void render();
	void cloneBoss();
	
	
	bossRoomScene(){}
	~bossRoomScene(){}
};

