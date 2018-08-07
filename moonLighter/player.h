#pragma once
#include "gameNode.h"
#include "gameObject.h"
#include "progressBar.h"
#include "effect.h"
#include "enemyController.h"

#define WILL_DAMAGED_MAX 3

class player : public gameObject
{
private:

	int _index;
	int _count;
	int _cntFoot;
	int _cntPendant;
	int _cntIsHit;
	int _cntIsInvincible;
	int _probeY;
	int _probeX;
	int _attCharge;
	int _damage;
	tagFloat footPos;
	float _time;
	float _speed;
	float _acceleration;
	bool _isAutomatic;
	bool _isIdle;
	bool _isUp;
	bool _isDown;
	bool _isLeft;
	bool _isRight;
	bool _isWalking;
	bool _isRolling;
	bool _isInvincible;
	bool _isAttacking;
	bool _isUsingPendant;
	bool _isGoingHome;
	bool _isRcSwordOn;
	bool _isEnemyHit;
	bool _isHit;
	bool _isDead;

	bool a;
	bool _playerMove;

	effect* _efcShortSword1;   
	image* backGround;
	image* will;
	image* willDungeon;
	image* willDungeonShadow;
	image* willFoot;
	image* willAttack;
	image* willDamaged[WILL_DAMAGED_MAX];
	image* willPendant;
	image* willGoHome;

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
	void dungeonMove();
	void willAction();
	void willDoSomething();
	void othersFrameUpdate(int frameX, int frameY);
	void noUsePendant();
	void goHome();
	bool getInvincible() { return _isInvincible; }
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }
	void setIsAutomatic(bool isAutomatic) { _isAutomatic = isAutomatic; }
	bool getIsAutomatic() { return _isAutomatic; }
	void setIsIdleUp(bool isUp);
	void setIsIdleLeft(bool isLeft);
	void setRevive();
	void setIsDead(bool isDead) { _isDead = isDead; }
	bool getIsDead() { return _isDead; }
	float getSpeed() { return _speed; }		
	RECT getRcBody() { return _rcBody; }	
	RECT getRcProbe() { return _rcProbe; }	
	RECT getRcSword() { return _rcSword;}	
	bool getIsRcSwordOn() { return _isRcSwordOn; } 
	void enemyCheckCollision();
	void setPlayerMove(bool playermove) { _playerMove = playermove; }

	player() {}
	~player() {}
};

