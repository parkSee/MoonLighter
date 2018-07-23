#pragma once
#include "gameNode.h"
#include "player.h"	//플레이어 클래스 사용하기 위해
#include "objectContainer.h"
#include "enemyController.h"

class mainGame : public gameNode
{
private:
	player * _player;	//플레이어 클래

	enemyController* _em;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);



	mainGame() {}
	~mainGame() {}
};

