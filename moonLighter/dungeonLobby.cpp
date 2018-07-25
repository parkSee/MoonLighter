#include "stdafx.h"
#include "dungeonLobby.h"


HRESULT dungeonLobby::init()
{
	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 
	_player = new player;
	_player->init("player", tagFloat(WINSIZEX / 2 + 150, 1434));
	_player->setPixelImage(IMAGEMANAGER->findImage("dunIntroRed"));
	
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);
	
	CAMERAMANAGER->setMapSize(1680, 1434);

	//SOUNDMANAGER->play("townBGM");


	return S_OK;
}

void dungeonLobby::release()
{
}

void dungeonLobby::update()
{

	OBJECTMANAGER->update();

	CAMERAMANAGER->update();
}

void dungeonLobby::render()
{
	RECT rc = CAMERAMANAGER->getRenderRc();

	IMAGEMANAGER->findImage("dunIntro")->render(getMemDC(), 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);


	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("dunIntroRed")->render(getMemDC(), 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	}


	OBJECTMANAGER->render(getMemDC());

}
