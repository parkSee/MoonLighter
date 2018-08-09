#include "stdafx.h"
#include "dungeonScene.h"

HRESULT dungeonScene::init()
{
	//�ÿ�» �� ���ᰡ �Ŷ� - ���� ����
	//lejADD ���� �� �߰�
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


	_cameraMove = false;
	_cameraMoveCount = 0;
	_cameraDistance = 0;

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
		SCENEMANAGER->loadScene("bossRoomScene");
		SOUNDMANAGER->stop("dungeonBGM");
	}

	
	this->moveDungeon();
	
	CAMERAMANAGER->cameraSlideMove(_player->getSpeed());

	_im->update();
}

void dungeonScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	IMAGEMANAGER->render("dungeonMap", getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);

	OBJECTMANAGER->render(getMemDC());

	_im->render(getMemDC());
	//RectangleCam(getMemDC(), upRc, cam);
	//RectangleCam(getMemDC(), RectMakeCenter(640, 740, 50, 50), cam);
	//RectangleCam(getMemDC(), RectMakeCenter(640, 690, 50, 50), cam);
	/*
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);

	SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));

	Rectangle(getMemDC(), CAMERAMANAGER->getRenderRc());


	SelectObject(getMemDC(), oldPen);
	DeleteObject(pen);
	*/
	


	//for (int i = 0; i < 9; ++i)
	//{
	//	RectangleCam(getMemDC(), _enterRc[i], cam);
	//}


	//char str[128];
	//sprintf_s(str, "%f, %f", _player->pos.x, _player->pos.y);
	//TextOut(getMemDC(), 200, 200, str, strlen(str));
	//
	//char str2[128];
	//sprintf(str2, "%f", _cameraDistance);
	//TextOut(getMemDC(), 100, 500, str2, strlen(str2));
	_player->renderUI(); //csyADD [�伺�� ���� �̷��� �÷��̾� ���� UI �����ϼ���]
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
	else if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[2]))
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
	else if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[3]))
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
	else if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[4]))
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
	else if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[5]))
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
	else if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[6]))
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
	else if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[7]))
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
	else if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[8]))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("bossRoomScene");
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
