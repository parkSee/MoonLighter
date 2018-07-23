#pragma once
#include "gameNode.h"
#include "gameObject.h"

class mini;

class player : public gameObject
{
private:
	
	
	float _time;
	int _probeY;
	int _probeX;

	image* backGround;
	image* home;
public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void collision();


	player() {}
	~player() {}
};

