#pragma once
#include "gameNode.h"
#include "lobbyContainer.h"
#include "player.h"

class dungeonLobby : public gameNode
{
private:
	int _count;
	int _index;
	int _index2;

	player * _player;
	lobbyContainer* _lobbyObj;
	RECT temp;
	RECT _enterRc;
	RECT _doorSensorRc;
	bool _isClose_Player;
	bool _isDungeonIn;
public:

	HRESULT init();
	void release();
	void update();
	void render();
	void willEnterFrame();


	dungeonLobby(){}
	~dungeonLobby(){}
};

