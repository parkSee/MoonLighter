#pragma once
#include "gameObject.h"
class objectContainer : public gameObject
{
private:
	image * _img;


public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();


	objectContainer(){}
	~objectContainer(){}
};

