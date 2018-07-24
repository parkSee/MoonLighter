#pragma once
#include "gameObject.h"

// lejADD 잡초 클래스 생성

class weed : public gameObject
{
private:
	image * _weed;
	int _count;
	int _weedFrameX;
	int _weedFrameY;

public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void weedFrame();
	weed() {}
	~weed() {}
};

