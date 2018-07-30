#pragma once
#include "gameNode.h"

struct Door
{
	image* img;
	tagInt pos;
};

class startScene : public gameNode
{

private:

	Door _doorLeft;
	Door _doorRight;

	image* main_frame;

	image* _logo;
	image* _aniKeyFont;
	image* _startFont;
	image* _optionFont;
	image* _exitFont;

	image* _selectImg;
	tagInt _selectPos;

	int _count, _index;

	bool _isOpen;
	int _alpha;

	int _alphaTime;
public:

	HRESULT init();
	void release();
	void update();
	void render();

	void Frame();

	startScene(){}
	~startScene(){}
};

