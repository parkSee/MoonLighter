#pragma once
#include "gameNode.h"
#include "house.h"
#include "tree.h"
#include "npc.h"


class objectContainer : public gameNode
{
private:

	house * _house[11];
	tree* _tree[11];

	npc* _witch;
	npc* _forge;
	npc* _merchant;
	npc* _bird;
public:

	HRESULT init();
	void release();
	void update();
	void render();


	objectContainer(){}
	~objectContainer(){}
};

