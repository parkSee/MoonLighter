#pragma once
#include "gameObject.h"


	// lejADD 스몰 슬라임 클래스 생성
class smallSlime : public gameObject
{
private:
	image * _smallSlime;
	int _count;
	int _currentX;
	int _currentY;


public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void smallSlimeFrame();

	smallSlime() {}
	~smallSlime() {}
};

