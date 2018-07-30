#pragma once
#include "gameNode.h"
#include "player.h"
<<<<<<< HEAD
#include "AIKids.h"
=======
#include "inventory.h"
>>>>>>> 인벤토리 테스트용 코드, 이미지 추가

class shopScene : public gameNode
{
private:

	player * _player;
	RECT _enterRc;


	AIKids* _aiKid;

	inventory* _inven;


public:

	HRESULT init();
	void release();
	void update();
	void render();


	shopScene(){}
	~shopScene(){}
};

