#pragma once
#include "gameObject.h"

// lejADD 스몰 슬라임 클래스 생성
class smallSlime : public gameObject
{
private:
	image * _smallSlime;
	image* _attackedSmallSlime[2];
	int _count;
	int _currentX;
	int _currentY;

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

	void smallSlimeFrame();
	void move();

	smallSlime() {}
	~smallSlime() {}
};

