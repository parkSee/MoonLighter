#pragma once
#include "gameNode.h"
#include "golem.h"
#include"weed.h"
#include"smallSlime.h"
#include"bigSlime.h"
#include"boss.h"

// lejADD 잡초 스몰슬라임 빅슬라임 클래스 추가및 할당
class enemyController : public gameNode
{
private:





public:

	HRESULT init();
	void release();
	void update();
	void render();

	void bossInit();
	void golemInit();
	void bigSlimeInit();
	void smallSlimeInit();
	void weedInit();


	enemyController() {}
	~enemyController() {}
};

