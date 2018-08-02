#pragma once
#include "gameNode.h"
#include "furniture.h"
class furnitureContainer : public gameNode
{
private:

	furniture * _furniture[3];
public:

	HRESULT init();
	void release();
	void update();
	void render();


	furnitureContainer(){}
	~furnitureContainer(){}
};

