#pragma once
#include "gameObject.h"

class display;

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

	int _buyCount;
	bool _isExit ;
	int _moveCount;
	bool _buy;
	vector<tagFloat> _vDot;

	display* _dp;
	bool _pickItem;

	bool _MoveStart;
	bool _soldOut;

	int _AICOUNT, _AIINDEX;

public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void set_startAIKids(bool go) { _MoveStart = go; }
	bool get_startAIKids() { return _MoveStart; }
	
	bool get_SellToAIKids() { return _isExit; }

	void set_SoldOutAIkids(bool so) { _soldOut = so; }
	bool get_SoldOutAIkids() { return _soldOut; }

	void Frame();
	void move();

	AIKids() {}
	~AIKids() {}
};

