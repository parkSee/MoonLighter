#pragma once
#include "gameNode.h"
#include "golem.h"
#include"weed.h"
#include"smallSlime.h"
#include"bigSlime.h"
#include"boss.h"

// lejADD 잡초 스몰슬라임 빅슬라임 클래스 추가및 할당
class enemyController : public gameNode
{
private:

	bool _stage1;
	bool _stage2;
	bool _stage3;
	bool _stage4;
	bool _stage5;



public:

	HRESULT init();
	void release();
	void update();
	void render();

	void golemInit();
	void bigSlimeInit();
	void smallSlimeInit();
	void weedInit();

	bool getstage1() { return _stage1; }
	bool getstage2() { return _stage2; }
	bool getstage3() { return _stage3; }
	bool getstage4() { return _stage4; }
	bool getstage5() { return _stage5; }

	void setStage1(bool stage) { _stage1 = stage; }
	void setStage2(bool stage) { _stage2 = stage; }
	void setStage3(bool stage) { _stage3 = stage; }
	void setStage4(bool stage) { _stage4 = stage; }
	void setStage5(bool stage) { _stage5 = stage; }


	void stage1Init();
	void stage2Init();
	void stage3Init();
	void stage4Init();
	void stage5Init();


	enemyController() {}
	~enemyController() {}
};

