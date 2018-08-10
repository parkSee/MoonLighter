#include "stdafx.h"
#include "dungeonScene.h"

HRESULT dungeonScene::init()
{
	//시영쨩 내 동료가 돼라 - 괴도 제이
	//lejADD 던전 맵 추가
	_vol = SAVEDATA->getVolume();
	SOUNDMANAGER->play("dungeonBGM", _vol);
	_player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	_player->setIsActive(true);

	
	_player->pos.x = 1920;
	_player->pos.y = 1800;

	_player->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));


	_em = new enemyController;
	_em->init();
	
	_im = OBJECTMANAGER->getItemManager();
	_im->init();

	vector<gameObject*> _vWeeds = OBJECTMANAGER->findObjects(objectType::ENEMY, "weed");

	for (int i = 0; i < _vWeeds.size(); i++)
	{
		((weed*)_vWeeds[i])->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	
	}

	CAMERAMANAGER->_pos.x = 1920;
	CAMERAMANAGER->_pos.y = 1800;
	
	CAMERAMANAGER->setMapSize(3840, 2160);
	CAMERAMANAGER->connectTarget(1920, 1800);


	_enterRc[0] = RectMakeCenter(1916, 1480, 50, 50);
	_enterRc[1] = RectMakeCenter(1920, 1370, 50, 50);
	_enterRc[2] = RectMakeCenter(1341, 1080, 50, 50);
	_enterRc[3] = RectMakeCenter(1203, 1075, 50, 50);
	_enterRc[4] = RectMakeCenter(1935, 773, 50, 50);
	_enterRc[5] = RectMakeCenter(1951, 631, 50, 50);
	_enterRc[6] = RectMakeCenter(2482, 346, 50, 50);
	_enterRc[7] = RectMakeCenter(2618, 346, 50, 50);
	_enterRc[8] = RectMakeCenter(3760, 360, 50, 50);

	for (int i = 0; i < 9; i++)
	{
		_doorCurrentX[i] = 0;
		_doorCurrentY[i] = 0;
		_doorCount[i] = 0;
		_doorBool[i] = false;
		
	}
	_door[0] = IMAGEMANAGER->findImage("door");
	_door[1] = IMAGEMANAGER->findImage("door아래");
	_door[2] = IMAGEMANAGER->findImage("door왼쪽");
	_door[3] = IMAGEMANAGER->findImage("door오른쪽");
	_door[4] = IMAGEMANAGER->findImage("door");
	_door[5] = IMAGEMANAGER->findImage("door아래");
	_door[6] = IMAGEMANAGER->findImage("door오른쪽");
	_door[7] = IMAGEMANAGER->findImage("door왼쪽");
	_door[8] = IMAGEMANAGER->findImage("door오른쪽");

	_cameraMove = false;
	_cameraMoveCount = 0;
	_cameraDistance = 0;
	_deadCount = 0;

	return S_OK;
}

void dungeonScene::release()
{
	
	_em->release();
	SAFE_DELETE(_em);
	//
	_im->release();
	
}

void dungeonScene::update()
{
	OBJECTMANAGER->update();

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("loadingBoss");
		SOUNDMANAGER->stop("dungeonBGM");
	}

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_doorBool[0] = true;
		
	}

	for (int i = 0; i < 9; i++)
	{
		if (_doorBool[i])
		{
			_doorCount[i]++;
			if (_doorCount[i] % 7 == 0)
			{
				_doorCurrentX[i]++;
			}
			if (_doorCurrentX[i] > _door[i]->getMaxFrameX())
			{
				_doorCurrentX[i] = _door[i]->getMaxFrameX();
				_doorCount[i] = 0;
				_doorBool[i] = false;
			}
		}
	}
	
	this->moveDungeon();
	
	CAMERAMANAGER->cameraSlideMove(_player->getSpeed());

	_im->update();
	_em->update();


	if (_em->getDeadCount() == 0)
	{
		if (_em->getstage1() == true)
		{
			_doorBool[0] = true;
		}
		if (_em->getstage2() == true)
		{
			_doorBool[1] = true;
			_doorBool[2] = true;
			_doorBool[4] = true;
		}
		if (_em->getstage3() == true)
		{
			_doorBool[3] = true;
		}
		if (_em->getstage4() == true)
		{
			_doorBool[5] = true;
			_doorBool[6] = true;
		}
		if (_em->getstage5() == true)
		{
			_doorBool[7] = true;
			_doorBool[8] = true;
		}
	}
}

void dungeonScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	
	IMAGEMANAGER->render("dungeonMap", getMemDC(), CAMERAMANAGER->getSX(), CAMERAMANAGER->getSY(), CAMERAMANAGER->getRenderSourRc().left, CAMERAMANAGER->getRenderSourRc().top, WINSIZEX, WINSIZEY);
	
	_door[0]->frameRender(getMemDC(), 1840-cam.left, 1440-cam.top,_doorCurrentX[0],_doorCurrentY[0]);

	_door[1]->frameRender(getMemDC(), 1840 - cam.left, 1345 - cam.top, _doorCurrentX[1], _doorCurrentY[1]);
	_door[2]->frameRender(getMemDC(), 1281 - cam.left, 1000 - cam.top, _doorCurrentX[2], _doorCurrentY[2]);
	_door[3]->frameRender(getMemDC(), 1175 - cam.left, 1005 - cam.top, _doorCurrentX[3], _doorCurrentY[3]);

	
	_door[4]->frameRender(getMemDC(), 1840 - cam.left, 720 - cam.top, _doorCurrentX[4], _doorCurrentY[4]);
	_door[5]->frameRender(getMemDC(), 1830 - cam.left, 625 - cam.top, _doorCurrentX[5], _doorCurrentY[5]);
	_door[6]->frameRender(getMemDC(), 2455 - cam.left, 280 - cam.top, _doorCurrentX[6], _doorCurrentY[6]);
	_door[7]->frameRender(getMemDC(), 2570 - cam.left, 280 - cam.top, _doorCurrentX[7], _doorCurrentY[7]);
	_door[8]->frameRender(getMemDC(), 3735 - cam.left, 280 - cam.top, _doorCurrentX[8], _doorCurrentY[8]);

	OBJECTMANAGER->render(getMemDC());
	
	_enterRc[0] = RectMakeCenter(1916, 1480, 50, 50);
	_enterRc[1] = RectMakeCenter(1920, 1370, 50, 50);
	_enterRc[2] = RectMakeCenter(1341, 1080, 50, 50);
	_enterRc[3] = RectMakeCenter(1203, 1075, 50, 50);
	_enterRc[4] = RectMakeCenter(1935, 773, 50, 50);
	_enterRc[5] = RectMakeCenter(1951, 631, 50, 50);
	_enterRc[6] = RectMakeCenter(2482, 346, 50, 50);
	_enterRc[7] = RectMakeCenter(2618, 346, 50, 50);
	_enterRc[8] = RectMakeCenter(3760, 360, 50, 50);



	_im->render(getMemDC());
	

	char str[128];
	sprintf_s(str, "%f, %f", _player->pos.x, _player->pos.y);
	TextOut(getMemDC(), 200, 200, str, strlen(str));
	//
	//char str2[128];
	//sprintf(str2, "%f", _cameraDistance);
	//TextOut(getMemDC(), 100, 500, str2, strlen(str2));
	_player->renderUI(); //csyADD [요성님 이제 이렇게 플레이어 관련 UI 랜더하세요]
}

void dungeonScene::moveDungeon()
{
	
	if (_em->getstage2())
	{
		_cameraMove = false;
	}
	if (_em->getstage3())
	{
		_cameraMove = false;
	}
	if (_em->getstage4())
	{
		_cameraMove = false;
	}
	if (_em->getstage5())
	{
		_cameraMove = false;
	}


	RECT temp;
	
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[0]))
	{
		_cameraMove = true;
		CAMERAMANAGER->connectTarget((int)1920, (int)1080);
		_player->setIsActive(false);
		if (_cameraDistance < 10)
		{
			_player->pos.x = 1916;
			_player->pos.y = 1250;
			_player->setIsActive(true);
		}
		if (_em->getstage2() == false && _cameraDistance < 10)
		{
			_em->stage2Init();
		}
		
	}
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[1]))
	{
		_cameraMove = true;
		CAMERAMANAGER->connectTarget((int)1920, (int)1800);
		_player->setIsActive(false);
		if (_cameraDistance < 10)
		{
			_player->pos.x = 1916;
			_player->pos.y = 1544;
			_player->setIsActive(true);
		}
		
	}
	 if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[2]))
	{
		_cameraMove = true;
		CAMERAMANAGER->connectTarget((int)640, (int)1080);
		_player->setIsActive(false);
		if (_cameraDistance < 10)
		{
			_player->pos.x = 1100;
			_player->pos.y = 1077;
			_player->setIsActive(true);
		}
		if (_em->getstage3() == false && _cameraDistance < 10)
		{
			_em->stage3Init();
		}

	}
	 if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[3]))
	{
		_cameraMove = true;
		CAMERAMANAGER->connectTarget((int)1920, (int)1080);
		_player->setIsActive(false);
		
		if (_cameraDistance < 10)
		{
			_player->pos.x = 1450;
			_player->pos.y = 1080;
			_player->setIsActive(true);
		}
	}
	 if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[4]))
	{
		_cameraMove = true;
		CAMERAMANAGER->connectTarget((int)1920, (int)360);
		_player->setIsActive(false);
		if (_cameraDistance < 10)
		{
			_player->pos.x = 1920;
			_player->pos.y = 460;
			_player->setIsActive(true);
		}
		if (_em->getstage4() == false && _cameraDistance < 10)
		{
			_em->stage4Init();
			
		}
	}
	 if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[5]))
	{
		_cameraMove = true;
		CAMERAMANAGER->connectTarget((int)1920, (int)1080);
		_player->setIsActive(false);
		
		if (_cameraDistance < 10)
		{
			_player->pos.x = 1920;
			_player->pos.y = 880;
			_player->setIsActive(true);
		}
	}
	 if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[6]))
	{
		_cameraMove = true;
		CAMERAMANAGER->connectTarget((int)3200, (int)360);
		_player->setIsActive(false);
		
		if (_cameraDistance < 10)
		{
			_player->pos.x = 2700;
			_player->pos.y = 360;
			_player->setIsActive(true);
		}
		if (_em->getstage5() == false && _cameraDistance < 10)
		{
			_em->stage5Init();
			
		}
	}
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[7]))
	{
		_cameraMove = true;
		CAMERAMANAGER->connectTarget((int)1920, (int)360);
		_player->setIsActive(false);
		
		if (_cameraDistance < 10)
		{
			_player->pos.x = 2400;
			_player->pos.y = 360;
			_player->setIsActive(true);
		}
	}
	 if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[8]))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("loadingBoss");
		SOUNDMANAGER->stop("dungeonBGM");
	}

	if (_cameraMove)
	{
		_cameraMoveCount++;
		_cameraDistance = getDistance(CAMERAMANAGER->_pos.x, CAMERAMANAGER->_pos.y, CAMERAMANAGER->getTarGet().x, CAMERAMANAGER->getTarGet().y);
	}
	else
	{
		_cameraDistance = 100;
	}

	

	

	/*if (IntersectRect(&temp, &RectMakeCenter(640, 740, 50, 50), &_player->rc))
	{
	CAMERAMANAGER->connectTarget(640, 330);
	_player->pos.y = 300;
	}


	if (IntersectRect(&temp, &RectMakeCenter(640, 690, 50, 50), &_player->rc))
	{
	CAMERAMANAGER->connectTarget(640, 1070); 
	_player->pos.y = 1000;
	}*/

}
