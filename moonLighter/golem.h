#pragma once
#include "gameObject.h"
#include"progressBar.h"
#define golemMaxImg 4

class golem : public gameObject
{
private:
	//lejADD [�� Ŭ���� ����]
	image * _golem[4];
	image * _golemShadow[4];
	image* _attackedGolem[8];
	image* _attackedGolemShadow[8];
	progressBar* _hp;
	int _currentHp;
	RECT _attackRc;
	image* _dmgFontTen;
	image* _dmgFontOne;
	RECT _dmgFontRc[2];
	float _dmgImgY;
	int _dmgImgCount;
	bool _dmgImgCountBool;

	int _currentX[4]; // ���� X ������ ��ǥ�� ����
	int _currentY[4];
	int _tempCurrent;
	int _count;
	float tempX;
	float tempY;
	int _attackCount[4];
	bool _attackCountBool[4];
	bool _startAttack;//�� ���ݽ��۽�ȣ
	bool _isAttack;//���� �������ִ���

	bool _noneAttacked;//���ݾȹ޾�����
	bool _isAttacked; // ���ݹ޾Ҵٴ� ��ȣ
	bool _isAttacked2;
	bool _isDead;
	int _attackedCount;


	bool _left;
	bool _right;
	bool _down;
	bool _up;
	bool _attackBool;

	int _rc0X;
	int _rc0Y;
	int _rc1X;
	int _rc1Y;
	int _rc2X;
	int _rc2Y;
	int _rc3X;
	int _rc3Y;
	

	int _dmgCount;
	float speed;
	float angle;
	float distance;
	image* _pixelImg;
	RECT _rc[4];


	bool _damaaged;
	RECT _rc2; //ü�±��̴� ��Ʈ
	RECT _collisionRc;
	bool _deadEffectBool ;
	bool _deadBool ;
	bool _dmg ;
	bool _isAttacked3;

public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	RECT getRect() { return rc; }
	void imgRectMake();
	void hp();
	void damaged();
	void golemFrame();
	void golemAttack();
	void move();
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }
	void pixelCollision();
	RECT getCollisionRC() { return _collisionRc; }
	RECT getAttackRc() { return _attackRc; }
	void dead();

	golem() {}
	~golem() {}
};
