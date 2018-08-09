#pragma once
#include "gameObject.h"

class display;

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
	bool _pickItem;
	int _moveCount;
	vector<tagFloat> _vDot;
	
	display* _dp;

	bool _MoveStart;
	bool _soldOut;

	int _AICOUNT, _AIINDEX;

public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void set_startAIGirl(bool go) { _MoveStart = go; }
	bool get_startAIGirl() { return _MoveStart; }
	
	bool get_SellToAIGirl() { return _isExit; }

	void set_SoldOutAIGirl(bool so) { _soldOut = so; }
	bool get_SoldOutAIGirl() { return _soldOut; }

	void Frame();
	void move();

	AIGirl() {}
	~AIGirl() {}
};
