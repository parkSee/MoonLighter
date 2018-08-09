#pragma once
#include "gameNode.h"
#include "gameObject.h"
#include "progressBar.h"
#include "effect.h"
#include "enemyController.h"

enum direction 
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct tagArrow
{
	tagFloat pos;
	int speed;
	bool isActive;
	RECT rcArrow;
	direction dir;
} Arrow;

#define WILL_DAMAGED_MAX 3

class inventory;	//csyADD

class player : public gameObject
{
private:

	int _index;
	int _count;
	int _cntFoot;
	int _cntHp[9];
	int _cntMoney[4];
	int _beforeHp;
	int _cntPendant;
	int _cntShakeHeart;
	int _money[2];
	int _cntIsHit;
	int _cntIsInvincible;
	int _probeY;
	int _probeX;
	int _attCharge;
	int _damage;
	playerDirection _dir;
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
	bool _isShakingHeart;
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
	image* willAttackShadow;
	image* willDamaged[WILL_DAMAGED_MAX];
	image* willAttackDamaged[WILL_DAMAGED_MAX-1];
	image* willPendant;
	image* willGoHome;
	image* willMoneyBag;
	image* willArrow[4];
	image* willBowAttack[4];
	image* willBowAttackShadow[4];
	image* willBowAttackDamaged[WILL_DAMAGED_MAX - 1][4];

	image* shakeHeart;
	image* number;
	image* weaponUi;

	int _UiCount;
	int _UiCurrentX;
	int _UiCurrentY;
	int _UiBool;

	bool _knife;
	bool _bow;
	Arrow _arrow[10];

	image* _pixelImg;

	RECT _rcBody;	
	RECT _rcSword;
	RECT _rcProbe;
	RECT _cam;

	progressBar* _hpBar;

	inventory* _inven; //csyADD
	
public:
	HRESULT init(string _objName, tagFloat _pos);
	void release();
	void update();
	void render();

	inventory* getInven() { return _inven; } //csyADD [인벤 클래스 쓰기위해 get함수 선언]

	void collision();
	void dungeonMove();
	void willAction();
	void willDoSomething();
	void othersFrameUpdate(int frameX, int frameY);
	void swordFrameUpdate();
	void bowFrameUpdate();
	void arrowUpdate();
	void attackRender();
	void noUsePendant();
	void goHome();
	void numberUpdate();
	void numberRender();
	bool getInvincible() { return _isInvincible; }
	void setPixelImage(image* pixelImg) { _pixelImg = pixelImg; }
	void setIsAutomatic(bool isAutomatic) { _isAutomatic = isAutomatic; }
	bool getIsAutomatic() { return _isAutomatic; }
	void setIsIdleUp(bool isUp);
	void setIsIdleLeft(bool isLeft);
	void setRevive();
	void setIsDead(bool isDead) { _isDead = isDead; }
	bool getIsDead() { return _isDead; }
	int getAttack();
	float getSpeed() { return _speed; }		
	RECT getRcBody() { return _rcBody; }	
	RECT getRcProbe() { return _rcProbe; }	
	RECT getRcSword() { return _rcSword;}	
	RECT getRcArrow();
	bool getIsRcSwordOn() { return _isRcSwordOn; } 
	void enemyCheckCollision();
	void setPlayerMove(bool playermove) { _playerMove = playermove; }
	void renderUI();	//csyADD [이제부터 체력바,인벤토리 등 UI의 랜더를 이 함수를 통해 씬에 출력하자]

	player() {}
	~player() {}
};

