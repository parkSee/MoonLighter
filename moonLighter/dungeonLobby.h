#pragma once
#include "gameNode.h"
#include "lobbyContainer.h"
#include "player.h"

class dungeonLobby : public gameNode
{
private:

	player * _player;
	lobbyContainer* _lobbyObj;
	RECT _enterRc;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	dungeonLobby(){}
	~dungeonLobby(){}
};

