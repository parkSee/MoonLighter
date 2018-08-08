#pragma once
#include "gameNode.h"
#include "house.h"
#include "tree.h"


class objectContainer : public gameNode
{
private:

	house * _house[10];
	tree* _tree[10];

public:

	HRESULT init();
	void release();
	void update();
	void render();


	objectContainer(){}
	~objectContainer(){}
};

