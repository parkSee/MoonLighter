#pragma once
#include "gameObject.h"

#define MAXSTATE 5


class AIGirl : public gameObject
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

	int _buyCount;
	bool _isExit;
	bool _buy;
	int _moveCount;
	vector<tagFloat> _vDot;

public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();


	void Frame();
	void move();

	AIGirl() {}
	~AIGirl() {}
};
