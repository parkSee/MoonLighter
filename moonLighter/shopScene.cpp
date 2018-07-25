#include "stdafx.h"
#include "shopScene.h"

HRESULT shopScene::init()
{

	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 
	_player = new player;
	_player->init("player", tagFloat(WINSIZEX/2, WINSIZEY/2));
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	//enterRc = RectMakeCenter(1944, 602, 100, 50);
	//_loading->loadImage("shopMap", "./Image/shop_object/red.bmp", 811, 850, true, MAGENTA);
	//IMAGEMANAGER->addImage("shopMap", "./Image/shop_object/shop.bmp", 811, 850);
	//_loading->loadImage("redZone", "./Image/town_object/town_pixel.bmp", 3000, 2460);
	CAMERAMANAGER->setMapSize(811, 850);

	SOUNDMANAGER->play("shopBGM");

	return S_OK;
}

void shopScene::release()
{
}

void shopScene::update()
{
	OBJECTMANAGER->update();

	CAMERAMANAGER->update();

}

void shopScene::render()
{
	RECT rc = CAMERAMANAGER->getRenderRc();


	IMAGEMANAGER->findImage("shopMap")->render(getMemDC());
	OBJECTMANAGER->render(getMemDC());
	
	//RectangleCam(getMemDC(), enterRc, rc);

}
