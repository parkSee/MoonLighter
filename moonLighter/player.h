#pragma once
#include "gameNode.h"
#include "gameObject.h"



class player : public gameObject
{
private:

	int _index;
	int _count;
	int _probeY;
	int _probeX;
	int _attCharge;
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

	image* backGround;
	image* will;
	image* willAttack;  //lysADD( �÷��̾� �����̹��� �߸� �ʱ�ȭ )

	image* _pixelImg;

	RECT _rcBody;	//lysADD( �÷��̾� ���׾Ƹ� ũ���� ��Ʈ �ϳ� �߰� (���ʹ̿��� �浹, ������ �Ա� ���� �浹üũ) )
	RECT _rcSword;	//lysADD( �÷��̾� ���� �� ���ݹ��� ��Ʈ ���� �߰�)
	RECT _rcProbe;
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


	player() {}
	~player() {}
};

