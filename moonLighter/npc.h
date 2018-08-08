#pragma once
#include "gameNode.h"

class player;

class npc : public gameNode
{

private:

	tagFloat _pos;
	image* _img;
	RECT _rc;

	RECT _talkRc;

	int _timer;
	bool _isFrame;
	int _count, _index;
	int _count2, _index2;

	image* _talkImg;
	bool _isCollision;

public:

	HRESULT init(tagFloat pos, image* img );
	void release();
	void update();
	void render();

	void frame();
	void talkingFrame();
	void talkingRECT(RECT rc);

	npc(){}
	~npc(){}
};

