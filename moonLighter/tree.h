#pragma once
#include "gameObject.h"
class tree : public gameObject
{
private:
	image* _img;

	int _count, _index;


public:

	HRESULT init(string _objName, tagFloat _pos, image* imgName);
	void release();
	void update();
	void render();

	tree(){}
	~tree(){}
};

