#pragma once
#include "gameObject.h"
#include"progressBar.h"
#define golemMaxImg 4

class golem : public gameObject
{
private:
	//lejADD [골렘 클래스 생성]
	image * _golem[4];
	image* _attackedGolem[8];
	progressBar* _hp;
	int _currentHp;

	int _currentX[4]; // 현재 X 프레임 좌표용 변수
	int _currentY[4];
	int _tempCurrent;
	int _count;
	float tempX;
	float tempY;
	int _attackCount[4];
	bool _attackCountBool[4];
	bool _startAttack;//골렘 공격시작신호
	bool _isAttack;//골렘이 떄리고있는중

	bool _noneAttacked;//공격안받았을때
	bool _isAttacked; // 공격받았다는 신호
	bool _isAttacked2;
	bool _isDead;
	int _attackedCount;


	bool _left;
	bool _right;
	bool _down;
	bool _up;


	
	float speed;
	float angle;
	float distance;



public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	RECT getRect() { return rc; }
	void imgRectMake();
	void hp();
	void golemFrame();
	void golemAttack();
	void move();


	void key();

	golem() {}
	~golem() {}
};
