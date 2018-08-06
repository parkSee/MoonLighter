#pragma once
#include "gameObject.h"

#define MAXSTATE 5

namespace State
{
	enum Enum
	{
		FRONT, BACK, LEFT, RIGHT, BUY, END
		//LEFT, RIGHT, UP, DOWN, BUY, END
	};
}

class AIKids : public gameObject
{
private:

	image * _state[MAXSTATE];
	image * _img;
	image* _pixelImg;
	//AIKidsState* _state;
	int _curState;

	int _count, _index;
	int _currentIndex;
	int _maxIndex;
	int _probeY;

	int buyCount = 0;
	bool _isExit = false;
	vector<tagFloat> _vDot;

public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void setPixel(image* img) { _pixelImg = img; }
	void Frame();
	void move();

	void test();

	AIKids() {}
	~AIKids() {}
};

