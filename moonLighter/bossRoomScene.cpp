#include "stdafx.h"
#include "bossRoomScene.h"

HRESULT bossRoomScene::init()
{

	_player = new player;
	_player->init("player", tagFloat(1576, 1900));
	_player->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));

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

}

void bossRoomScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	IMAGEMANAGER->render("bossRoom", getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);

	OBJECTMANAGER->render(getMemDC());
}
