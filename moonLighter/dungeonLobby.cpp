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
	_doorSensorRc = RectMakeCenter(720, 953, 100, 100);

	_count = _index = 0;
	_IsClose_Player = false;
	return S_OK;
}

void dungeonLobby::release()
{
	_lobbyObj->release();
	SAFE_DELETE(_lobbyObj);
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
	if (IntersectRect(&temp, &_player->getRcBody(), &_doorSensorRc))
	{
		_IsClose_Player = true;
	}
	else
	{
		_IsClose_Player = false;
	}
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonScene");
	}


	CAMERAMANAGER->update();

	_enterRc = RectMakeCenter(720, 953, 50, 50);
	_doorSensorRc = RectMakeCenter(720, 953, 100, 300);
}

void dungeonLobby::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	IMAGEMANAGER->findImage("dunIntro")->render(getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);
	
	if (_IsClose_Player)
	{
		++_count;
		IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameX(_index);
		IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameY(0);
		if (_count % 7 == 0)
		{
			++_index;
			if (_index > IMAGEMANAGER->findImage("dunIntroDoorOpen")->getMaxFrameX())
			{
				_index = 10;
			}
		}
		IMAGEMANAGER->findImage("dunIntroDoorOpen")->frameRender(getMemDC(), 672 - cam.left, 905 - cam.top);
	}
	else
	{
		++_count;
		IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameX(_index);
		IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameY(0);
		if (_count % 7 == 0)
		{
			--_index;
			if (_index < 0)
			{
				_index = 0;
			}
		}
		IMAGEMANAGER->findImage("dunIntroDoorOpen")->frameRender(getMemDC(), 672 - cam.left, 905 - cam.top);
	}

	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("dunIntroRed")->render(getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);
	}

	if (KEYMANAGER->isOnceKeyDown('K'))
	{
		RectangleCam(getMemDC(), _doorSensorRc, cam);
	}
	
	//RectangleCam(getMemDC(), _enterRc, cam);
	OBJECTMANAGER->render(getMemDC());
	
}
