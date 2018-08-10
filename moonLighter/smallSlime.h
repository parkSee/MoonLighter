#pragma once
#include "gameObject.h"
#include"progressBar.h"

// lejADD 스몰 슬라임 클래스 생성
class smallSlime : public gameObject
{
private:
	image * _smallSlime;
	image* _smallSlimeShadow;
	image* _attackedSmallSlime[2];
	image* _attackedSmallSlimeShadow[2];
	progressBar* _hp;
	RECT _collisionRc;
	image* _dmgFontTen;
	image* _dmgFontOne;
	RECT _dmgFontRc[2];
	float _dmgImgY;
	int _dmgImgCount;
	bool _dmgImgCountBool;

	int _currentHp;
	int _count;
	int _currentX;
	int _currentY;
	int _alpha;

	float angle;
	float speed;

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
	int _dmgCount;
	
	bool _noneAttacked;//공격안받았을때
	bool _isAttacked; // 공격받았다는 신호
	bool _isAttacked2;
	int _attackedCount;
	image* _pixelImg;
	RECT _rc[4];

	bool _deadEffectBool;
	bool _deadBool;
	bool _dmg;
	bool _isAttacked3;
	RECT _rc2;


public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void imgRectMake();
	void hp();
	void damagged();
	void smallSlimeFrame();
	void pixelCollision();
	RECT getRect() { return rc; }
	RECT getCollisionRect() { return _collisionRc; }
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }
	void move();
	void dead();

	smallSlime() {}
	~smallSlime() {}
};

