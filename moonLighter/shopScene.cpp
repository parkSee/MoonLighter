#include "stdafx.h"
#include "shopScene.h"

HRESULT shopScene::init()
{

	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 
	_player = new player;
	_player->init("player", tagFloat(WINSIZEX/2, WINSIZEY/2));

	_player->setPixelImage(IMAGEMANAGER->findImage("shopPixel"));

	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	//enterRc = RectMakeCenter(1944, 602, 100, 50);
	//_loading->loadImage("shopMap", "./Image/shop_object/red.bmp", 811, 850, true, MAGENTA);
	//IMAGEMANAGER->addImage("shopMap", "./Image/shop_object/shop.bmp", 811, 850);
	//_loading->loadImage("redZone", "./Image/town_object/town_pixel.bmp", 3000, 2460);
	CAMERAMANAGER->setMapSize(WINSIZEX, 1440);

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

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
		SOUNDMANAGER->stop("shopBGM");
	}

}
 
void shopScene::render()
{
	RECT rc = CAMERAMANAGER->getRenderRc();


	IMAGEMANAGER->findImage("shopMap")->render(getMemDC(),0- rc.left,0 - rc.top);//, 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("shopPixel")->render(getMemDC(), 0 - rc.left, 0 - rc.top);//, 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	}

	
	OBJECTMANAGER->render(getMemDC());
	IMAGEMANAGER->findImage("shopLayer")->render(getMemDC(), 0 - rc.left, 555 - rc.top);
	


	//RectangleCam(getMemDC(), enterRc, rc);

}
