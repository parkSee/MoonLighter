#pragma once
#include "gameNode.h"
#include "gameObject.h"
#include "progressBar.h"
#include "effect.h"
#include "enemyController.h"
class player : public gameObject
{
private:

	int _index;
	int _count;
	int _cntIsInvincible;
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

	bool a;


	effect* _efcShortSword1;   //lysADD( �÷��̾� ��������Ʈ�̹��� �߸� �ʱ�ȭ )
	image* backGround;
	image* will;
	image* willAttack;  

	image* _pixelImg;

	RECT _rcBody;	
	RECT _rcSword;	
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
	float getSpeed() { return _speed; }		//lysADD  (�ٽ��ǵ� �Լ� �߰�)
	RECT getRcBody() { return _rcBody; }	//lysADD  (�ٸ��׾Ƹ� ��Ʈ �Լ� �߰�)
	RECT getRcSword() { return _rcSword;}	//lysADD (�� ���ݹ��� ��Ʈ �Լ� �߰�)
	bool getIsRcSwordOn() { return _isRcSwordOn; } //lysADD (���������� �ƴ��� bool�� ��ȯ)
	void enemyCheckCollision();

	player() {}
	~player() {}
};

