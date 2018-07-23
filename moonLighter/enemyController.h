#pragma once
#include "gameNode.h"
#include "mini.h"

class enemyController : public gameNode
{
private:

	vector<mini*> _vMini;
	

public:

	HRESULT init();
	void release();
	void update();
	void render();


	enemyController(){}
	~enemyController(){}
};

