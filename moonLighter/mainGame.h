#pragma once
#include "gameNode.h"
#include "startScene.h"
#include "loadingScene.h"
#include "townScene.h"
#include "shopScene.h"
#include "dungeonScene.h"


class mainGame : public gameNode
{
private:


public:
	HRESULT init();
	void release();
	void update();
	void render();



	mainGame() {}
	~mainGame() {}
};

