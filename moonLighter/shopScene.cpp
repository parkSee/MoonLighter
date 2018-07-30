#include "stdafx.h"
#include "shopScene.h"

//csyADD [인벤 출력 테스트 용 추가]

HRESULT shopScene::init()
{

	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 
	_player = new player;
	_player->init("player", tagFloat(WINSIZEX/2, 1000));

	_player->setPixelImage(IMAGEMANAGER->findImage("shopPixel"));

	OBJECTMANAGER->addObject(objectType::PLAYER, _player);


	_aiKid = new AIKids;
	_aiKid->init("aiKid", tagFloat(655, 1303),IMAGEMANAGER->findImage("AiKids"));
	OBJECTMANAGER->addObject(objectType::AI, _aiKid);

	_inven = new inventory;
	_inven->init();


	//enterRc = RectMakeCenter(1944, 602, 100, 50);
	//_loading->loadImage("shopMap", "./Image/shop_object/red.bmp", 811, 850, true, MAGENTA);
	//IMAGEMANAGER->addImage("shopMap", "./Image/shop_object/shop.bmp", 811, 850);
	//_loading->loadImage("redZone", "./Image/town_object/town_pixel.bmp", 3000, 2460);
	
	CAMERAMANAGER->setMapSize(WINSIZEX, 1440);

	SOUNDMANAGER->play("shopBGM");

	_enterRc = RectMakeCenter(650, 1290, 50, 50);

	return S_OK;
}

void shopScene::release()
{
}

void shopScene::update()
{
	OBJECTMANAGER->update();
	CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
	CAMERAMANAGER->update();
	RECT temp;
	if (IntersectRect(&temp,&_player->getRcBody(), &_enterRc))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
		_player->pos.x = 1952;
		_player->pos.y = 770;
		SOUNDMANAGER->stop("shopBGM");
	}
	_enterRc = RectMakeCenter(650, 1290, 50, 50);

	_inven->update();
}
 
void shopScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();


	IMAGEMANAGER->findImage("shopMap")->render(getMemDC(),0- cam.left,0 - cam.top);//, 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("shopPixel")->render(getMemDC(), 0 - cam.left, 0 - cam.top);//, 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	}

	
	OBJECTMANAGER->render(getMemDC());
	IMAGEMANAGER->findImage("shopLayer")->render(getMemDC(), 0 - cam.left, 555 - cam.top);
	
	RectangleCam(getMemDC(), _enterRc, cam);
	
	_inven->render();
}
