#pragma once
#include "gameObject.h"
#define golemMaxImg 4

class golem : public gameObject
{
private:
	//lejADD [골렘 클래스 생성]
	image * _golem[4];
	
	
	

	int _currentX[4]; // 현재 X 프레임 좌표용 변수
	int _currentY;
	
	int _count;

	int _attackCount[4];
	bool _attackCountBool[4];
	

	bool _left;
	bool _right;
	bool _down;
	bool _up;

	int _alpha; //빅슬라임 캐릭터 덮쳤을때 알파값




public:
	HRESULT init(string _objName, tagFloat _pos );
	void release();
	void update();
	void render();

	void golemFrame();
	void bigSlimeFrame();

	void key();

	golem() {}
	~golem() {}
};

