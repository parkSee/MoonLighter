#pragma once
#include "gameNode.h"

//csyADD [다른 클래스에서 받아올 겟터함수 추가]

class item : public gameNode
{	
protected:
	tagFloat _pos;
	image* _img;
	RECT _collisionBox;

public:

	tagFloat get_pos() { return _pos; }
	image* get_img() { return _img; }
	RECT get_collisionBox() { return _collisionBox; }

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	item() {}
	~item() {}
};

