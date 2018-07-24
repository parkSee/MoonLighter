#pragma once
#include "gameNode.h"
#include "enemyController.h"
<<<<<<< HEAD
#include "player.h"
=======
#include "itemManager.h"

>>>>>>> 아이템 이미지 초기화 / 아이템 상속 관련 테스트 / 각 아이템 하위클래스 생성 [주석 안달았어요 죄송]
class dungeonScene : public gameNode
{

private:

<<<<<<< HEAD
	player * _player;
=======
	itemManager * _im;
>>>>>>> 아이템 이미지 초기화 / 아이템 상속 관련 테스트 / 각 아이템 하위클래스 생성 [주석 안달았어요 죄송]
	enemyController * _em;

public:


	HRESULT init();
	void release();
	void update();
	void render();



	dungeonScene(){}
	~dungeonScene(){}
};

