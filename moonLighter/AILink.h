#pragma once
#include "gameObject.h"

class display;

#define MAXSTATE 5


class AILink : public gameObject
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
	vector<tagFloat> _vDot;

	display* _dp;
	bool _pickItem;
	bool _MoveStart;
public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void set_startAILink(bool go) { _MoveStart = go; }
	bool get_startAILink() { return _MoveStart; }
	bool get_SellToAILink() { return _isExit; }

	void Frame();
	void move();

	AILink() {}
	~AILink() {}
};
