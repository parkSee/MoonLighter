#pragma once
#include "gameNode.h"

//csyADD [�ٸ� Ŭ�������� ��ǥ ������ �����Լ� �߰�]

class item : public gameNode
{	
protected:
	tagFloat _pos;
	image* _img;
	RECT _collisionBox;

public:

	tagFloat get_pos() { return _pos; }
	void set_pos(tagFloat pos) { _pos = pos; }

	image* get_img() { return _img; }
	RECT get_collisionBox() { return _collisionBox; }

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	item() {}
	~item() {}
};

