#pragma once
#include "gameObject.h"
class stone : public gameObject
{
private:
	image * _img;

public:

	HRESULT init(string _objName, tagFloat _pos, image* imgName);
	void release();
	void update();
	void render();

	stone(){}
	~stone(){}
};

