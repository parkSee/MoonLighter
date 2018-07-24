#pragma once
#include "gameNode.h"
#include "golem.h"
#include"weed.h"
#include"smallSlime.h"
#include"bigSlime.h"
// lejADD ���� ���������� �򽽶��� Ŭ���� �߰��� �Ҵ�
class enemyController : public gameNode
{
private:
	golem * _golem;
	weed* _weed;
	smallSlime* _smallSlime;
	bigSlime* _bigSlime;

	//vector<golem*> _vgolem;
public:

	HRESULT init();
	void release();
	void update();
	void render();


	enemyController(){}
	~enemyController(){}
};

