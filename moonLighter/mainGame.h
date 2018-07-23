#pragma once
#include "gameNode.h"
#include "player.h"	//�÷��̾� Ŭ���� ����ϱ� ����
#include "objectContainer.h"
#include "enemyController.h"

class mainGame : public gameNode
{
private:
	player * _player;	//�÷��̾� Ŭ��

	enemyController* _em;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);



	mainGame() {}
	~mainGame() {}
};

