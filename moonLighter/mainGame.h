#pragma once
#include "gameNode.h"
#include "startScene.h"
#include "loadingScene.h"
#include "townScene.h"
#include "shopScene.h"
#include "dungeonScene.h"
#include "dungeonLobby.h"
#include "bossRoomScene.h"
#include "player.h"


class mainGame : public gameNode
{
private:

	player * _player;
public:
	HRESULT init();
	void release();
	void update();
	void render();



	mainGame() {}
	~mainGame() {}
};

