#pragma once
#include "gameNode.h"
class npc : public gameNode
{

private:

	tagFloat _pos;
	image* _img;
	RECT _rc;

	RECT _talkRc;


	int _count, _index;

public:

	HRESULT init(tagFloat pos, image* img );
	void release();
	void update();
	void render();

	void frame();


	npc(){}
	~npc(){}
};

