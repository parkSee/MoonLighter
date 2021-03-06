#pragma once
#include "gameNode.h"

#include "player.h"	//플레이어 클래스 사용하기 위해
#include "objectContainer.h"



class townScene : public gameNode
{
private:

	player * _player;	//플레이어 클래
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

