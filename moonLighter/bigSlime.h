#pragma once
#include "gameObject.h"
#include"progressBar.h"

// lejADD 큰 슬라임 클래스 생성 
class bigSlime : public gameObject
{
private:
	image * _bigSlime;
	image* _attackedBigSlime[2];
	progressBar* _hp;
	int _currentHp;
	int _count;
	int _currentX;
	int _currentY;
	int _alpha;
	bool _slimeBool;

	float angle;
	float speed;
	image* _pixelImg;
	RECT _rc[4];
	bool _xCollision;
	bool _yCollision;
	int _rc0X;
	int _rc0Y;
	int _rc1X;
	int _rc1Y;
	int _rc2X;
	int _rc2Y;
	int _rc3X;
	int _rc3Y;

	bool _damaaged;
	bool _noneAttacked;//공격안받았을때
	bool _isAttacked; // 공격받았다는 신호
	bool _isAttacked2;
	int _attackedCount;
	int _dmgCount;
	bool _deadEffectBool ;
	bool _deadBool ;
	bool _dmg ;
	bool _isAttacked3;
	RECT _rc2;

public:

	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void imgRectMake();
	void hp();
	void bigSlimeFrame();
	void move();
	void damaged();
	void pixelCollision();
	RECT getRect() { return rc; }
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }
	void dead();

	bigSlime() {}
	~bigSlime() {}
};

