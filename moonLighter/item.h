#pragma once
#include "gameNode.h"
//csyADD [������ Ŭ���� �߰�]

class item : public gameNode
{	
protected:
	tagFloat _pos;
	image* _img;
	


public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	item() {}
	~item() {}
};

