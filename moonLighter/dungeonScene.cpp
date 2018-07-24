#include "stdafx.h"
#include "dungeonScene.h"

HRESULT dungeonScene::init()
{

	//lejADD 던전 맵 추가


	_em = new enemyController;
	_em->init();
	IMAGEMANAGER->addImage("Dungeon","./image/Dungeon/던전.bmp",WINSIZEX,WINSIZEY);
	CAMERAMANAGER->setMapSize(WINSIZEX, WINSIZEY);

	return S_OK;
}

void dungeonScene::release()
{
}

void dungeonScene::update()
{ 
	CAMERAMANAGER->update();
	OBJECTMANAGER->update();
}

void dungeonScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	IMAGEMANAGER->render("Dungeon", getMemDC(),0,0,cam.left,cam.top,WINSIZEX,WINSIZEY);

	OBJECTMANAGER->render(getMemDC());

}
