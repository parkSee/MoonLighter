#pragma once
#include "gameObject.h"
#include"progressBar.h"

class boss :public gameObject
{
private:
	image * _boss[5];
	image* _attackedBoss[9];
	progressBar* _hp;
	int _currentHp;

	int _currentX[5]; // 현재 X 프레임 좌표용 변수
	int _currentY[5];
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
	int _dmgCount;
	int _dmgHp;

	bool _leftUp;
	bool _rightUp;
	bool _leftDown;
	bool _rightDown;

	bool _damaaged;
	bool _start;
	bool _playing;

	bool _xMove;
	bool _yMove;

	int _rc0X;
	int _rc0Y;
	int _rc1X;
	int _rc1Y;
	int _rc2X;
	int _rc2Y;
	int _rc3X;
	int _rc3Y;

	int tempX2;
	int tempY2;

	float speed;
	float angle;
	float distance;
	image* _pixelImg;
	RECT _rc[4];
	RECT _detectRect;

public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	RECT getRect() { return rc; }
	void imgRectMake();
	int damagged();
	void hp();
	void bossFrame();
	void bossAttack();
	void move();
	void pixelCollision();
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }

	

	boss() {}
	~boss() {}
};

