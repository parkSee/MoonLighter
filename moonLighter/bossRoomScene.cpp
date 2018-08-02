#include "stdafx.h"
#include "bossRoomScene.h"

HRESULT bossRoomScene::init()
{

	_player = new player;
	_player->init("player", tagFloat(1580, 1900));
	_player->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));

	 _boss = new boss;
	_boss->init("boss", tagFloat(1600, 1000));
	OBJECTMANAGER->addObject(objectType::ENEMY, _boss);
	_boss->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));

	_bossHp = new progressBar;
	_bossHp->init("보스체력", "보스체력껍데기", 100, 600, 1000, 14);
	_currentHp = 300;
	_dmgCount = _blackBgCount=0;
	_blackBgAlpha = 0;
	_damaged = false;
	_dmgCountBool = false;
	for (int i = 0; i < MAXBOSS; i++)
	{
		_clone[i] = false;
	}
	_blackBgBool = false;
	

	_blackBg = IMAGEMANAGER->findImage("검은화면");
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	CAMERAMANAGER->setMapSize(3152, 2131);

/*
	_test = new progressBar;
	_test->init("testF", "testB", WINSIZEX / 2, WINSIZEY / 2, 20, 600);*/
	


	return S_OK;
}

void bossRoomScene::release()
{
}

void bossRoomScene::update()
{
	
	if (((boss*)OBJECTMANAGER->findObject(objectType::ENEMY, "boss"))->getStart() == true)
	{
		CAMERAMANAGER->connectTarget(((boss*)OBJECTMANAGER->findObject(objectType::ENEMY, "boss"))->pos.x, ((boss*)OBJECTMANAGER->findObject(objectType::ENEMY, "boss"))->pos.y);
		
		CAMERAMANAGER->cameraSlideMove(8.0f);
	}
	else
	{
		CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
		CAMERAMANAGER->update();
	}

	OBJECTMANAGER->update();

	// csyADD [보스륨 cpp - c누르면 타운씬 넘어간다]
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
	}

	/*_test->setX(WINSIZEX/2);
	_test->setY(WINSIZEY-200);
	_test->update();
	_test->setHeightGuge(_currentHp, 200);*/

	_bossHp->update();
	
	_bossHp->setX(150);
	_bossHp->setY(600);
	
	//_boss->damagged();
	RECT tempRc;
	if (IntersectRect(&tempRc, &((player*)_player)->getRcSword(), &_boss->getCollisionRC()) && _damaged==false)
	{
		_damaged = true;
		_dmgCountBool = true;
		_currentHp -= 20;
	}

	for(int i=0;i<MAXBOSS;i++)
	{
		if (_clone[i])
		{
			if (IntersectRect(&tempRc, &((player*)_player)->getRcSword(), &_boss2->getCollisionRC()) && _damaged == false)
			{
	
				_damaged = true;
				_dmgCountBool = true;
				_currentHp -= 10;
	
			}
		}
	}
		

	_bossHp->setGauge(_currentHp, 300);

	if (_dmgCountBool)
	{
		_dmgCount++;
	}
	if (_dmgCount>50)
	{
		_dmgCount = 0;
		_damaged = false;
		
	}
	for (int i = 0; i < MAXBOSS ;i++)
	{
		if (_currentHp < 280 - 50 * i  && _clone[i]==false)
		{
			_clone[i] = true;
			this->cloneBoss();
			CAMERAMANAGER->shakeCamera(5.0f, 0.001f);
		}
	}
	
}

void bossRoomScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	IMAGEMANAGER->render("bossRoom", getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);

	OBJECTMANAGER->render(getMemDC());
	_bossHp->render();
	char str[128];
	sprintf(str, "%d", _currentHp);
	TextOut(getMemDC(), 100, WINSIZEY / 2, str, strlen(str));
	_blackBg->alphaRender(getMemDC(), _blackBgAlpha);
	//_test->renderHeight();
}

void bossRoomScene::cloneBoss()
{
	int rndNum = RND->getInt(2);
	if ( rndNum == 0)rndNum = -1;
	_boss2 = new boss;
	_boss2->init("boss", tagFloat(_boss->pos.x+ (rndNum)*(500), _boss->pos.y));
	OBJECTMANAGER->addObject(objectType::ENEMY, _boss2);
	_boss2->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));


	
}

