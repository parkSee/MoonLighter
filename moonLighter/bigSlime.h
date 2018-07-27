#pragma once
#include "gameObject.h"


// lejADD 큰 슬라임 클래스 생성 
class bigSlime : public gameObject
{
private:
	image * _bigSlime;
	image* _attackedBigSlime[2];
	int _count;
	int _currentX;
	int _currentY;
	int _alpha;
	bool _slimeBool;

	float angle;
	float speed;

	bool _noneAttacked;//공격안받았을때
	bool _isAttacked; // 공격받았다는 신호
	bool _isAttacked2;
	int _attackedCount;


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

