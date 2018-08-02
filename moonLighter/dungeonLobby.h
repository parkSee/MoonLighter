#pragma once
#include "gameNode.h"
#include "lobbyContainer.h"
#include "player.h"

class dungeonLobby : public gameNode
{
private:
	int _count;
	int _index;

	player * _player;
	lobbyContainer* _lobbyObj;
	RECT _enterRc;

	RECT _doorSensorRc;
	bool _IsClose_Player;
public:

	HRESULT init();
	void release();
	void update();
	void render();

	dungeonLobby(){}
	~dungeonLobby(){}
};

