#pragma once
#include "gameNode.h"

#include "player.h"	//�÷��̾� Ŭ���� ����ϱ� ����
#include "objectContainer.h"



class townScene : public gameNode
{
private:

	player * _player;	//�÷��̾� Ŭ��
	RECT _enterShopRc;
	RECT _enterDgInRc;
	image* _enterText;
	objectContainer* _container;
	float _vol;

	int _count, _index;
public:

	HRESULT init();
	void release();
	void update();
	void render();

	void enterFrame();

	townScene(){}
	~townScene(){}
};

