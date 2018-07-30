#pragma once
#include "gameNode.h"
#include "stone.h"

class lobbyContainer : public gameNode
{
private:
	stone * _lobbyObj[9];
public:
	HRESULT init();
	void release();
	void update();
	void render();

	lobbyContainer(){}
	~lobbyContainer(){}
};

