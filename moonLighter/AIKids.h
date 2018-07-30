#pragma once
#include "gameObject.h"
#include "AIKidsState.h"

class AIKids : public gameObject
{
private:

	image * _img;
	AIKidsState* _state;

public:

	HRESULT init(string _objName, tagFloat _pos, image* imgName);
	void release();
	void update();
	void render();

	AIKids(){}
	~AIKids(){}
};

