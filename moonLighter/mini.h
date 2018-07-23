#pragma once
#include "gameObject.h"

class mini : public gameObject
{
private:
	int count;
	int isRight;

public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void move();

	mini(){}
	~mini(){}
};

