#include "stdafx.h"
#include "townScene.h"

HRESULT townScene::init()
{

	//���߿� ���Ŵ��� �߰��ؼ� �Ű� �����̴ϴ�. 
	_player = new player;
	_player->init("player", tagFloat(WINSIZEX / 2, WINSIZEY / 2));
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	_container = new objectContainer;
	_container->init();

	enterRc = RectMakeCenter(1944, 602, 100, 50);

	//IMAGEMANAGER->addImage("redZone", "./Image/town_object/town_pixel.bmp", 3000, 2460);
		//_loading->loadImage("redZone", "./Image/town_object/town_pixel.bmp", 3000, 2460);
	CAMERAMANAGER->setMapSize(3000, 2460);

	SOUNDMANAGER->play("townBGM");

	return S_OK;
}

void townScene::release()
{
	
}

void townScene::update()
{
	
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonScene");
		SOUNDMANAGER->stop("townBGM");
	}
	
	RECT temp;
	if (IntersectRect(&temp, &_player->rc, &enterRc))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("shopScene");
		SOUNDMANAGER->stop("townBGM");
	}

	OBJECTMANAGER->update();

	CAMERAMANAGER->update();

	enterRc = RectMakeCenter(1944, 602, 100, 50);
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
	RectangleCam(getMemDC(), enterRc, rc);



}
