#pragma once
#include "gameNode.h"
#include "player.h"
#include"boss.h"
#include"progressBar.h"
#define MAXBOSS 10

class bossRoomScene : public gameNode
{
private:

	player * _player;
	progressBar* _bossHp;
	progressBar* _test;
	boss* _boss;
	boss*_boss2;
	image* _blackBg;
	int _currentHp;
	int _blackBgAlpha;
	int _blackBgBool;
	int _blackBgCount;
	int _dmgCount;
	bool _damaged;
	bool _dmgCountBool;
	bool _clone[MAXBOSS];
	

public:


	HRESULT init();
	void release();
	void update();
	void render();
	void cloneBoss();
	
	
	bossRoomScene(){}
	~bossRoomScene(){}
};

