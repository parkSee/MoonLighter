#pragma once
#include "gameNode.h"

#include "player.h"	//�÷��̾� Ŭ���� ����ϱ� ����
#include "objectContainer.h"


class townScene : public gameNode
{
private:

	player * _player;	//�÷��̾� Ŭ��
	RECT enterRc;
	
	objectContainer* _container;
public:

	HRESULT init();
	void release();
	void update();
	void render();


	townScene(){}
	~townScene(){}
};

