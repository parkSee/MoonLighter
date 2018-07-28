#pragma once
#include "gameNode.h"
#include "gameObject.h"
#include "progressBar.h"


class player : public gameObject
{
private:

	int _index;
	int _count;
	int _probeY;
	int _probeX;
	int _attCharge;
	int _damage;
	float _time;
	float _speed;
	float _acceleration;
	bool _isIdle;
	bool _isUp;
	bool _isDown;
	bool _isLeft;
	bool _isRight;
	bool _isRolling;
	bool _isInvincible;
	bool _isAttacking;
	bool _isRcSwordOn;
	bool _isHit;
	bool _isDead;

	image* backGround;
	image* will;
	image* willAttack;  //lysADD( 플레이어 공격이미지 야매 초기화 )

	image* _pixelImg;

	RECT _rcBody;	//lysADD( 플레이어 몸뚱아리 크기의 렉트 하나 추가 (에너미와의 충돌, 아이템 먹기 위한 충돌체크) )
	RECT _rcSword;	//lysADD( 플레이어 공격 시 공격범위 렉트 변수 추가)
	RECT _rcProbe;

	progressBar* _hpBar;
public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	void collision();
	void move();
	bool getInvincible() { return _isInvincible; }
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }
	float getSpeed() { return _speed; }		//lysADD  (겟스피드 함수 추가)
	RECT getRcBody() { return _rcBody; }	//lysADD  (겟몸뚱아리 렉트 함수 추가)
	RECT getRcSword() { return _rcSword;}	//lysADD (겟 공격범위 렉트 함수 추가)

	player() {}
	~player() {}
};

