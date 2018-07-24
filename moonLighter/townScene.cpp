#include "stdafx.h"
#include "townScene.h"

HRESULT townScene::init()
{

	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 
	_player = new player;
	_player->init("player", tagFloat(WINSIZEX / 2, WINSIZEY / 2));
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	_container = new objectContainer;
	_container->init();

	CAMERAMANAGER->setMapSize(3000, 2460);

	return S_OK;
}

void townScene::release()
{

}

void townScene::update()
{
	

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		SCENEMANAGER->loadScene("dungeonScene");
	}
	OBJECTMANAGER->update();
	CAMERAMANAGER->update();
}

void townScene::render()
{
	RECT rc = CAMERAMANAGER->getRenderRc();


	IMAGEMANAGER->findImage("map")->render(getMemDC(), 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);

	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("radZone")->render(getMemDC(), 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	}
	//_background->render(getMemDC(), 0, 0, renderRC.left, renderRC.top, WINSIZEX, WINSIZEY);

	/*HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);

	SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));

	Rectangle(getMemDC(), CAMERAMANAGER->getRenderRc());


	SelectObject(getMemDC(), oldPen);
	DeleteObject(pen); 
	*/
	CAMERAMANAGER->render(getMemDC());

	
	OBJECTMANAGER->render(getMemDC());



}
