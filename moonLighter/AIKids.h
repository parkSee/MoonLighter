#pragma once
#include "gameObject.h"
#include "AIKidsState.h"

class AIKids : public gameObject
{
private:

	image * _img;
	image* _pixelImg;
	AIKidsState* _state;

public:

	HRESULT init(string _objName, tagFloat _pos, image* imgName);
	void release();
	void update();
	void render();

	void setPixel(image* img) {_pixelImg = img;}

	AIKids(){}
	~AIKids(){}
};

