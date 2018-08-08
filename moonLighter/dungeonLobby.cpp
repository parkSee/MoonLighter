#include "stdafx.h"
#include "dungeonLobby.h"


HRESULT dungeonLobby::init()
{
	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 

	_player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	if (_player->getIsDead() == true)
	{
		_player->pos.x = 720;
		_player->pos.y = 1000;
	}
	else
	{
		_player->pos.x = 1240;
		_player->pos.y = 1980;
	}
	_player->setPixelImage(IMAGEMANAGER->findImage("dunIntroRed"));
	
	CAMERAMANAGER->setMapSize(2460, 2100);

	_lobbyObj = new lobbyContainer;
	_lobbyObj->init();

	_enterRc = RectMakeCenter(720, 953, 50, 50);
	_doorSensorRc = RectMakeCenter(720, 1000, 100, 150);
	_returnRc = RectMakeCenter(1255, 2091, 100, 50);



	_count = _index = _index2 = 0;
	_isDoorOpen = false;
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

	CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
	OBJECTMANAGER->update();
	
	++_count;

	CAMERAMANAGER->update();
	
	this->willEnterFrame();

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonScene");
		SOUNDMANAGER->stop("townBGM");
	}
	RECT temp;
	if (IntersectRect(&temp, &_player->getRcBody(), &_returnRc))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
		SOUNDMANAGER->stop("townBGM");
		_player->pos.x = 2850;
		_player->pos.y = 788;
	}
}

void dungeonLobby::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	IMAGEMANAGER->findImage("dunIntro")->render(getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);
	if (_player->getIsDead() == false)
	{
		if (_isDungeonIn == false)											    //던전 문 오픈 출력
		{
			if (IntersectRect(&temp, &_player->getRcProbe(), &_enterRc))            //던전입장 출력
			{
				IMAGEMANAGER->findImage("dunIntroShowEnterText")->frameRender(getMemDC(), 750 - cam.left, 870 - cam.top);
			}
			IMAGEMANAGER->findImage("dunIntroDoorOpen")->frameRender(getMemDC(), 672 - cam.left, 905 - cam.top);
		}
		else                                                                    //플레이어 윌 흡입 출력
		{
			IMAGEMANAGER->findImage("dunIntroGoInDungeon")->frameRender(getMemDC(), 672 - cam.left, 905 - cam.top);
		}
	}
	else                                                                        //플레이어 윌 뱉기 출력
	{
		IMAGEMANAGER->findImage("dunIntroGoOutDungeon")->frameRender(getMemDC(), 672 - cam.left, 905 - cam.top);
	}
	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("dunIntroRed")->render(getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);
	}
	OBJECTMANAGER->render(getMemDC());



	RectangleCam(getMemDC(), _returnRc,cam);

	_player->renderUI();

}

void dungeonLobby::willEnterFrame()
{
	if (_player->getIsDead() == false)
	{
		if ((IntersectRect(&temp, &_player->getRcProbe(), &_enterRc) && KEYMANAGER->isOnceKeyDown('J')) && _isDungeonIn == false)   //던전입장
		{
			_index = 0;
			_player->setIsActive(false);
			_isDungeonIn = true;
			SOUNDMANAGER->play("dungeon_entrance_slime_door_absorb");
		}
		if (_isDungeonIn == false)
		{
			if (IntersectRect(&temp, &_player->getRcBody(), &_doorSensorRc))   //열려라 참깨
			{
				_isDoorOpen = true;
				if (SOUNDMANAGER->isPlaySound("dungeon_entrance_slime_door_opened_loop") == false)
				{
					SOUNDMANAGER->play("dungeon_entrance_slime_door_opened_loop");
				}
				IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameX(_index);
				IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameY(0);
				if (_count % 5 == 0)
				{
					++_index;
					if (_index > IMAGEMANAGER->findImage("dunIntroDoorOpen")->getMaxFrameX()) { _index = 10; }
				}
			}
			else                                                              //닫혀라 참깨
			{
				SOUNDMANAGER->stop("dungeon_entrance_slime_door_opened_loop");
				if (SOUNDMANAGER->isPlaySound("dungeon_entrance_slime_door_close") == false && _isDoorOpen == true)
				{
					SOUNDMANAGER->play("dungeon_entrance_slime_door_close");
				}
				IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameX(_index);
				IMAGEMANAGER->findImage("dunIntroDoorOpen")->setFrameY(0);
				if (_count % 2 == 0)
				{
					--_index;
					if (_index < 0)
					{
						_index = 0;
						_isDoorOpen = false;
					}
				}
			}
		}
		else                                                                 //플레이어 윌 흡입 출력
		{
			IMAGEMANAGER->findImage("dunIntroGoInDungeon")->setFrameX(_index);
			IMAGEMANAGER->findImage("dunIntroGoInDungeon")->setFrameY(0);
			if (_count % 7 == 0)
			{
				++_index;
				if (_index > IMAGEMANAGER->findImage("dunIntroGoInDungeon")->getMaxFrameX())
				{
					OBJECTMANAGER->reset();
					SCENEMANAGER->loadScene("dungeonScene");
					SOUNDMANAGER->stop("townBGM");
				}
			}
		}
		if (IntersectRect(&temp, &_player->getRcProbe(), &_enterRc))            //던전입장 출력
		{
			IMAGEMANAGER->findImage("dunIntroShowEnterText")->setFrameX(_index2);
			IMAGEMANAGER->findImage("dunIntroShowEnterText")->setFrameY(0);
			if (_count % 10 == 0)
			{
				++_index2;
				if (_index2 > IMAGEMANAGER->findImage("dunIntroShowEnterText")->getMaxFrameX()) { _index2 = IMAGEMANAGER->findImage("dunIntroShowEnterText")->getMaxFrameX(); }
			}
		}
		else { _index2 = 0; }
	}
	else                                                                      //플레이어 윌 내뱉기 출력  ( 던전에서 죽었을 때 )
	{
		if (SOUNDMANAGER->isPlaySound("dungeon_entrance_slime_door_spit") == false && _index == 8)
		{
			SOUNDMANAGER->play("dungeon_entrance_slime_door_spit");
		}
		IMAGEMANAGER->findImage("dunIntroGoOutDungeon")->setFrameX(_index);
		IMAGEMANAGER->findImage("dunIntroGoOutDungeon")->setFrameY(0);
		if (_count % 6 == 0)
		{
			++_index;
			if (_index > IMAGEMANAGER->findImage("dunIntroGoOutDungeon")->getMaxFrameX())
			{
				_index = 0;
				_player->setIsDead(false);
				_player->setIsAutomatic(false);
				_player->setIsActive(true);
				_player->setRevive();
				_player->setIsIdleUp(false);
			}
		}
	}
}
