#pragma once
#include "gameNode.h"


class enemyController : public gameNode
{
private:


public:

	HRESULT init();
	void release();
	void update();
	void render();


	enemyController(){}
	~enemyController(){}
};

