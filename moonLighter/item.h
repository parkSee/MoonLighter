#pragma once
#include "gameNode.h"

//csyADD [충돌박스 용 렉트 추가]

class item : public gameNode
{	
protected:
	tagFloat _pos;
	image* _img;
	RECT _collisionBox;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	item() {}
	~item() {}
};

