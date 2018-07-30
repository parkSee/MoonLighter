#pragma once
#include "gameNode.h"
#include "golem.h"
#include"weed.h"
#include"smallSlime.h"
#include"bigSlime.h"
#include"boss.h"

// lejADD ���� ���������� �򽽶��� Ŭ���� �߰��� �Ҵ�
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

