#pragma once
#include "gameNode.h"
#include "golem.h"

class enemyController : public gameNode
{
private:
	golem * _golem;
	//vector<golem*> _vgolem;
public:

	HRESULT init();
	void release();
	void update();
	void render();


	enemyController(){}
	~enemyController(){}
};

