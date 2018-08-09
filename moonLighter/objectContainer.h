#pragma once
#include "gameNode.h"
#include "house.h"
#include "tree.h"
#include "npc.h"


class objectContainer : public gameNode
{
private:

	house * _house[10];
	tree* _tree[10];

	npc* _witch;
	npc* _forge;
public:

	HRESULT init();
	void release();
	void update();
	void render();


	objectContainer(){}
	~objectContainer(){}
};

