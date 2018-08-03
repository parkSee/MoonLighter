#include "stdafx.h"
#include "dungeonLobby.h"


HRESULT dungeonLobby::init()
{
	//���߿� ���Ŵ��� �߰��ؼ� �Ű� �����̴ϴ�. 
	_player = new player;
	_player->init("player", tagFloat(1240, 1980));
	_player->setPixelImage(IMAGEMANAGER->findImage("dunIntroRed"));
	
	//OBJECTMANAGER->addObject(objectType::PLAYER, _player);
	
	CAMERAMANAGER->setMapSize(2460, 2100);

	_lobbyObj = new lobbyContainer;
	_lobbyObj->init();

	_enterRc = RectMakeCenter(720, 953, 50, 50);
	_doorSensorRc = RectMakeCenter(720, 1000, 100, 150);

	_count = _index = _index2 = 0;
	_isClose_Player = false;
	_isDungeonIn = false;
	return S_OK;
}

void dungeonLobby::release()
{
	_lobbyObj->release();
	SAFE_DELETE(_lobbyObj);
}

void dungeonLobby::update()
{
	++_count;

	CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
	OBJECTMANAGER->update();

	if ((IntersectRect(&temp, &_player->getRcProbe(), &_enterRc) && KEYMANAGER->isOnceKeyDown('J')) && _isDungeonIn == false)   //��������
	{
		_index = 0;
		_isDungeonIn = true;
		_player->setPlayerMove(false);
	}
	if (_isDungeonIn == false)
	{
		if (IntersectRect(&temp, &_player->getRcBody(), &_doorSensorRc))   //������ ����
		{
			_isClose_Player = true;
			IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameX(_index);
			IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameY(0);
			if (_count % 7 == 0)
			{
				++_index;
				if (_index > IMAGEMANAGER->findImage("dunIntroDoorOpen")->getMaxFrameX()) { _index = 10; }
			}
		}
		else                                                              //������ ����
		{
			_isClose_Player = false;
			IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameX(_index);
			IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameY(0);
			if (_count % 7 == 0)
			{
				--_index;
				if (_index < 0) { _index = 0; }
			}
		}

	}
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonScene");
	}
	if (KEYMANAGER->isOnceKeyDown('P'))    //�׽�����
	{
		if (_isDungeonIn == false) { _isDungeonIn = true; }
		else { _isDungeonIn = false; }
	}
	CAMERAMANAGER->update();
	_player->update();
	
	_enterRc = RectMakeCenter(720, 953, 50, 50);
	_doorSensorRc = RectMakeCenter(720, 1000, 100, 150);
}

void dungeonLobby::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	IMAGEMANAGER->findImage("dunIntro")->render(getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);
	
	if (IntersectRect(&temp, &_player->getRcProbe(), &_enterRc))            //�������� ���
	{
		IMAGEMANAGER->findImage("dunIntroShowEnterText")->setFrameX(_index2);
		IMAGEMANAGER->findImage("dunIntroShowEnterText")->setFrameY(0);
		if (_count % 10 == 0)
		{
			++_index2;
			if (_index2 > IMAGEMANAGER->findImage("dunIntroShowEnterText")->getMaxFrameX()) { _index2 = IMAGEMANAGER->findImage("dunIntroShowEnterText")->getMaxFrameX(); }
		}
		IMAGEMANAGER->findImage("dunIntroShowEnterText")->frameRender(getMemDC(), 750 - cam.left, 870 - cam.top);
	}
	else { _index2 = 0; }
	if (!_isDungeonIn)
	{
		if (_isClose_Player)                                            //������ ���� ���
		{
			IMAGEMANAGER->findImage("dunIntroDoorOpen")->frameRender(getMemDC(), 672 - cam.left, 905 - cam.top);
		}
		else                                                            //������ ���� ���
		{
			IMAGEMANAGER->findImage("dunIntroDoorOpen")->frameRender(getMemDC(), 672 - cam.left, 905 - cam.top);
		}
	}
	if (_isDungeonIn)                                                   //�÷��̾� �� ���� ���
	{
		IMAGEMANAGER->findImage("dunIntroGoInDungeon")->setFrameX(_index);
		IMAGEMANAGER->findImage("dunIntroGoInDungeon")->setFrameY(0);
		if (_count % 10 == 0)
		{
			++_index;
			if (_index > IMAGEMANAGER->findImage("dunIntroGoInDungeon")->getMaxFrameX())
			{
				OBJECTMANAGER->reset();
				SCENEMANAGER->loadScene("dungeonScene");
			}
		}
		IMAGEMANAGER->findImage("dunIntroGoInDungeon")->frameRender(getMemDC(), 672 - cam.left, 905 - cam.top);
	}
	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("dunIntroRed")->render(getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);
	}
	
	OBJECTMANAGER->render(getMemDC());
	if (_isDungeonIn == false)                                                   
	{
		_player->render();
	}
}
