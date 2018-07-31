#include "stdafx.h"
#include "bossRoomScene.h"

HRESULT bossRoomScene::init()
{

	_player = new player;
	_player->init("player", tagFloat(1576, 1900));
	_player->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));

	 _boss = new boss;
	_boss->init("boss", tagFloat(2000, 1000));
	OBJECTMANAGER->addObject(objectType::ENEMY, _boss);
	_boss->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));

	_bossHp = new progressBar;
	_bossHp->init("보스체력", "보스체력껍데기", 100, 600, 1000, 14);
	_currentHp = 200;
	_dmgCount = 0;
	_damaged = false;
	_dmgCountBool = false;
	_clone = false;

	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	CAMERAMANAGER->setMapSize(3152, 2131);
	return S_OK;
}

void bossRoomScene::release()
{
}

void bossRoomScene::update()
{
	CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);

	CAMERAMANAGER->update();

	OBJECTMANAGER->update();

	// csyADD [보스륨 cpp - c누르면 타운씬 넘어간다]
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
	}


	


	_bossHp->update();
	
	_bossHp->setX(150);
	_bossHp->setY(600);
	
	//_boss->damagged();
	RECT tempRc;
	if (IntersectRect(&tempRc, &((player*)_player)->getRcSword(), &_boss->rc) && _damaged==false)
	{
		_damaged = true;
		_dmgCountBool = true;
		_currentHp -= 20;
	}

	if (_clone)
	{
		if (IntersectRect(&tempRc, &((player*)_player)->getRcSword(), &_boss2->rc) && _damaged == false)
		{
			_damaged = true;
			_dmgCountBool = true;
			_currentHp -= 10;
		}
	}

	_bossHp->setGauge(_currentHp, 200);

	if (_dmgCountBool)
	{
		_dmgCount++;
	}
	if (_dmgCount>50)
	{
		_dmgCount = 0;
		_damaged = false;
		
	}
	if (_currentHp < 100 && _clone==false)
	{
		_clone = true;
		this->cloneBoss();
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
}

void bossRoomScene::cloneBoss()
{
	_boss2 = new boss;
	_boss2->init("boss", tagFloat(_boss->pos.x-200, _boss->pos.y));
	OBJECTMANAGER->addObject(objectType::ENEMY, _boss2);
	_boss2->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));

}

