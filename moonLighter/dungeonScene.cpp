#include "stdafx.h"
#include "dungeonScene.h"

HRESULT dungeonScene::init()
{

	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 
	//에너미 매니저 할당
	_em = new enemyController;
	_em->init();

	CAMERAMANAGER->setMapSize(3000, 2460);

	return S_OK;
}

void dungeonScene::release()
{
}

void dungeonScene::update()
{ 

	OBJECTMANAGER->update();
}

void dungeonScene::render()
{

	CAMERAMANAGER->render(getMemDC());

	OBJECTMANAGER->render(getMemDC());

}
