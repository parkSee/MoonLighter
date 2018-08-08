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
	tagFloat _taklUiPos;
	bool _isCollision;
	image* _talkBox;
	tagFloat _talkBoxUiPos;
	bool _istalk;

	char text[256];

	int _txtCount, _txtIndex;

public:

	HRESULT init(tagFloat pos, image* img );
	void release();
	void update();
	void render();

	void frame();
	void talkingFrame();
	void talkingRECT(RECT rc, tagFloat talkUi, tagFloat talkBoxUi);
	void talkingRender(const char* a );

	bool getIstalk() { return _istalk; }
	void setIsTalk(bool istalk) { _istalk = istalk; }

	npc(){}
	~npc(){}
};

