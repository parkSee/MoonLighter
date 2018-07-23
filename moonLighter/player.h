#pragma once
#include "gameNode.h"
#include "gameObject.h"


class player : public gameObject
{
private:
	
public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();


	player() {}
	~player() {}
};

