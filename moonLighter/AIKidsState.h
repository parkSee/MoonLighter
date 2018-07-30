#pragma once
class AIKids;

namespace State
{
	enum Enum
	{
		IDLE, LEFT, RIGHT, UP, DOWN, BUY, END

	};
}

class AIKidsState
{
private:
	State::Enum _state;
	image* _img;
	image* _pixel;
	gameObject* _parent;
	int _currentIndex;
	int _maxIndex;
	int _probeY;

public:


	animation * _ani1;
	vector<tagFloat> _vDot;

	void enter(gameObject* parent, State::Enum state, image* img, image* pixel);
	void update();
	void move();

	AIKidsState(){}
	~AIKidsState(){}
};
