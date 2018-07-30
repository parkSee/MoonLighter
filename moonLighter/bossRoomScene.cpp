#include "stdafx.h"
#include "bossRoomScene.h"

HRESULT bossRoomScene::init()
{

	_player = new player;
	_player->init("player", tagFloat(1576, 1900));
	_player->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));

	boss* _boss = new boss;
	_boss->init("boss", tagFloat(1600, 1000));
	OBJECTMANAGER->addObject(objectType::ENEMY, _boss);
	_boss->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));

	_bossHp = new progressBar;
	_bossHp->init("보스체력", "보스체력껍데기", 100, 600,1000,14);
	_currentHp = 200;
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	CAMERAMANAGER->setMapSize(3152, 2131);
	return S_OK;
}

void bossRoomScene::release()
{
	_bossHp->release();
}

void bossRoomScene::update()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);

	CAMERAMANAGER->update();

	OBJECTMANAGER->update();


	_bossHp->update();
	_bossHp->setX( 150 );
	_bossHp->setY( 600 ) ;
	_bossHp->setGauge(_currentHp, 200);
}

void bossRoomScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	IMAGEMANAGER->render("bossRoom", getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);
	OBJECTMANAGER->render(getMemDC());
	_bossHp->render();
}
