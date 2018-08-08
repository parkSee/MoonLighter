#include "stdafx.h"
#include "enemyController.h"

//에너미 컨트롤러에서 해주는건 몇마리 셋팅할것인지와
//오브젝트 매니저에 넣어주는것 

//한마디로 에너미 전체를 움직임을 관리 하는 지휘관같은 존재입니다.

//참고로 오브젝트 매니저는 메인게임에서 이미 업데이트를 돌려주고 있음


HRESULT enemyController::init()
{
	_stage1=false;
	_stage2=false;
	_stage3=false;
	_stage4=false;
	_stage5=false;
	

	return S_OK;
}

void enemyController::release()
{


}

void enemyController::update()
{



}

void enemyController::render()
{


}


void enemyController::golemInit()
{
	

	
	
	
		
}

void enemyController::bigSlimeInit()
{
	

	
	
	
}

void enemyController::smallSlimeInit()
{
	

	
	
	



}

void enemyController::weedInit()
{
	

	

	
	
}

void enemyController::stage1Init()
{
	_stage1 = true;

	bigSlime* _bigSlime = new bigSlime;
	_bigSlime->init("bigSlime", tagFloat(tagFloat(2100, 1800)));
	OBJECTMANAGER->addObject(objectType::ENEMY, _bigSlime);
	_bigSlime->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	
	weed* _weed = new weed;
	_weed->init("weed", tagFloat(1800, 1800));
	OBJECTMANAGER->addObject(objectType::ENEMY, _weed);
	_weed->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));

	golem* _golem = new golem;
	_golem->init("golem", tagFloat(1500, 1800));
	OBJECTMANAGER->addObject(objectType::ENEMY, _golem);
	_golem->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
}

void enemyController::stage2Init()
{
	_stage2 = true;

	for (int i = 0; i < 6; ++i)
	{
		smallSlime* _smallSlime = new smallSlime;
		_smallSlime->init("smallSlime", tagFloat(1400 + 200 * i, 1000));
		OBJECTMANAGER->addObject(objectType::ENEMY, _smallSlime);
		_smallSlime->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	}
	
}

void enemyController::stage3Init()
{

	_stage3 = true;

	for (int i = 0; i < 2; ++i)
	{
		golem* _golem = new golem;
		_golem->init("golem", tagFloat(600 + 300 * i, 1000));
		OBJECTMANAGER->addObject(objectType::ENEMY, _golem);
		_golem->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));

	}
	
	
}

void enemyController::stage4Init()
{

	_stage4 = true;


	for (int i = 0; i < 3; ++i)
	{
		weed* _weed = new weed;
		_weed->init("weed", tagFloat(1400 + 200 * i, 300));
		OBJECTMANAGER->addObject(objectType::ENEMY, _weed);
		_weed->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	}
	for (int i = 0; i < 1; ++i)
	{
		golem* _golem = new golem;
		_golem->init("golem", tagFloat(1700 + 300 * i, 400));
		OBJECTMANAGER->addObject(objectType::ENEMY, _golem);
		_golem->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	}
	for (int i = 0; i < 2; ++i)
	{
		smallSlime* _smallSlime = new smallSlime;
		_smallSlime->init("smallSlime", tagFloat(1800 + 200 * i, 300));
		OBJECTMANAGER->addObject(objectType::ENEMY, _smallSlime);
		_smallSlime->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	}
	

}

void enemyController::stage5Init()
{
	_stage5 = true;

	for (int i = 0; i < 1; ++i)
	{
		bigSlime* _bigSlime = new bigSlime;
		_bigSlime->init("bigSlime", tagFloat(3600 + 500 * i, 200));
		OBJECTMANAGER->addObject(objectType::ENEMY, _bigSlime);
		_bigSlime->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	}
	for (int i = 0; i < 2; ++i)
	{
		weed* _weed = new weed;
		_weed->init("weed", tagFloat(3000 + 400 * i, 300));
		OBJECTMANAGER->addObject(objectType::ENEMY, _weed);
		_weed->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	}
	for (int i = 0; i < 6; ++i)
	{
		smallSlime* _smallSlime = new smallSlime;
		_smallSlime->init("smallSlime", tagFloat(3000 + 200 * i, 300));
		OBJECTMANAGER->addObject(objectType::ENEMY, _smallSlime);
		_smallSlime->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	}

	for (int i = 0; i < 3; ++i)
	{
		golem* _golem = new golem;
		_golem->init("golem", tagFloat(3000 + 300 * i, 400));
		OBJECTMANAGER->addObject(objectType::ENEMY, _golem);
		_golem->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	}


}
