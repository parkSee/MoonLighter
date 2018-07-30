#include "stdafx.h"
#include "dungeonLobby.h"


HRESULT dungeonLobby::init()
{
	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 
	_player = new player;
	_player->init("player", tagFloat(1240, 1980));
	_player->setPixelImage(IMAGEMANAGER->findImage("dunIntroRed"));
	
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);
	
	CAMERAMANAGER->setMapSize(2460, 2100);

	_lobbyObj = new lobbyContainer;
	_lobbyObj->init();

	_enterRc = RectMakeCenter(720, 953, 50, 50);
	return S_OK;
}

void dungeonLobby::release()
{
	
}

void dungeonLobby::update()
{

	CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
	OBJECTMANAGER->update();

	RECT temp; 

	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonScene");
	
	}

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonScene");
	}


	CAMERAMANAGER->update();

	_enterRc = RectMakeCenter(720, 953, 50, 50);
}

void dungeonLobby::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	IMAGEMANAGER->findImage("dunIntro")->render(getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);


	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("dunIntroRed")->render(getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);
	}

	RectangleCam(getMemDC(), _enterRc, cam);
	OBJECTMANAGER->render(getMemDC());
	
}
