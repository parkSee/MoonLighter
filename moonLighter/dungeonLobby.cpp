#include "stdafx.h"
#include "dungeonLobby.h"


HRESULT dungeonLobby::init()
{
	//���߿� ���Ŵ��� �߰��ؼ� �Ű� �����̴ϴ�. 
	_player = new player;
	_player->init("player", tagFloat(WINSIZEX / 2 + 150, 1434));
	_player->setPixelImage(IMAGEMANAGER->findImage("dunIntroRed"));
	
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);
	
	CAMERAMANAGER->setMapSize(2460, 2100);

	//SOUNDMANAGER->play("townBGM");


	return S_OK;
}

void dungeonLobby::release()
{
	/*_player->release();
	SAFE_DELETE(_player);*/
}

void dungeonLobby::update()
{

	CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
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
