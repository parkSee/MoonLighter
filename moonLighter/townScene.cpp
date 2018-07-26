#include "stdafx.h"
#include "townScene.h"

HRESULT townScene::init()
{

	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 
	_player = new player;
	_player->init("player", tagFloat(WINSIZEX / 2, WINSIZEY / 2));
	_player->setPixelImage(IMAGEMANAGER->findImage("redZone"));
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	_container = new objectContainer;
	_container->init();

	_enterShopRc = RectMakeCenter(1944, 602, 100, 50);
	_enterDgInRc = RectMakeCenter(2950, 788, 50, 100);
	//IMAGEMANAGER->addImage("redZone", "./Image/town_object/town_pixel.bmp", 3000, 2460);
	//_loading->loadImage("redZone", "./Image/town_object/town_pixel.bmp", 3000, 2460);
	CAMERAMANAGER->setMapSize(3000, 2460);

	//SOUNDMANAGER->play("townBGM");

	return S_OK;
}

void townScene::release()
{
	
}

void townScene::update()
{
	CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
	
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonScene");
		//SOUNDMANAGER->stop("townBGM");
	}
	
	RECT temp;
	if (IntersectRect(&temp, &_player->rc, &_enterShopRc))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("shopScene");
		//SOUNDMANAGER->stop("townBGM");
	}

	if (IntersectRect(&temp, &_player->rc, &_enterDgInRc))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonLobby");
	}


	OBJECTMANAGER->update();

	CAMERAMANAGER->update();

	_enterShopRc = RectMakeCenter(1944, 602, 100, 50);
	_enterDgInRc = RectMakeCenter(2950, 788, 50, 100);
}

void townScene::render()
{
	RECT rc = CAMERAMANAGER->getRenderRc();


	IMAGEMANAGER->findImage("map")->render(getMemDC(), 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);

	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("redZone")->render(getMemDC(), 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	}

	//_background->render(getMemDC(), 0, 0, renderRC.left, renderRC.top, WINSIZEX, WINSIZEY);

	/*HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);

	SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));

	Rectangle(getMemDC(), CAMERAMANAGER->getRenderRc());


	SelectObject(getMemDC(), oldPen);
	DeleteObject(pen); 
	*/

	OBJECTMANAGER->render(getMemDC());
	RectangleCam(getMemDC(), _enterShopRc, rc);
	RectangleCam(getMemDC(), _enterDgInRc, rc);



}
