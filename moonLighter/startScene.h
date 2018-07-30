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
	int _count, _index;

	bool _isOpen;
public:

	HRESULT init();
	void release();
	void update();
	void render();

	void Frame();

	startScene(){}
	~startScene(){}
};

