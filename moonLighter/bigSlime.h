#pragma once
#include "gameObject.h"


class player;
	// lejADD ū ������ Ŭ���� ���� 
class bigSlime : public gameObject
{
private:
	image * _bigSlime;
	int _count;
	int _currentX;
	int _currentY;
	int _alpha;
	bool _slimeBool;


public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void bigSlimeFrame();
	void move();

	bigSlime() {}
	~bigSlime() {}
};

