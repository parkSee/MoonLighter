#pragma once
#include "gameNode.h"
#include "gameObject.h"



class player : public gameObject
{
private:

	int _index;
	int _count;
	int _probeY;
	int _probeX;
	int _attCharge;
	float _time;
	float _speed;
	float _acceleration;
	bool _isIdle;
	bool _isUp;
	bool _isDown;
	bool _isLeft;
	bool _isRight;
	bool _isRolling;
	bool _isInvincible;

	image* backGround;
	image* will;

	RECT _rc;
	RECT _rcProbe;
public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void collision();
	void move();
	bool getInvincible() { return _isInvincible; }


	player() {}
	~player() {}
};

