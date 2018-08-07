#pragma once
#include "gameNode.h"
#include "player.h"
<<<<<<< HEAD
#include "ui.h"
=======

class display;

>>>>>>> 108191f43cdc061f8b9c2433ab952969ea42abe1
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

<<<<<<< HEAD
	ui* _ui;
=======
	display* _display;
>>>>>>> 108191f43cdc061f8b9c2433ab952969ea42abe1

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

