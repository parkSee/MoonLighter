#include "stdafx.h"
#include "dungeonScene.h"

HRESULT dungeonScene::init()
{

	//lejADD ���� �� �߰�
	//player* _player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	//_player->init("player", tagFloat(WINSIZEX - WINSIZEX / 4, WINSIZEY / 2));
	
	_player = new player;
	_player->init("player", tagFloat(WINSIZEX / 2, WINSIZEY / 2));
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	_em = new enemyController;
	_em->init();

	IMAGEMANAGER->addImage("Dungeon","./image/Dungeon/����.bmp",WINSIZEX,WINSIZEY);
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

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
	}

}

void dungeonScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	IMAGEMANAGER->render("Dungeon", getMemDC(),0,0,cam.left,cam.top,WINSIZEX,WINSIZEY);

	OBJECTMANAGER->render(getMemDC());


}