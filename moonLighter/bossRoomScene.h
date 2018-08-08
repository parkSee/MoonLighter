#pragma once
#include "gameNode.h"
#include "player.h"
#include"boss.h"
#include"progressBar.h"
#define MAXBOSS 5

class bossRoomScene : public gameNode
{
private:

	player * _player;
	RECT _bossRect;
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
	int _deadCount;

	bool _deadEffectBool;
	bool _deadBool[MAXBOSS];
	bool _bgStart;

	float _vol;
	

public:


	HRESULT init();
	void release();
	void update();
	void render();
	void cloneBoss();
	void removeClone(int index);
	
	
	bossRoomScene(){}
	~bossRoomScene(){}
};

