#include "stdafx.h"
#include "dungeonScene.h"

HRESULT dungeonScene::init()
{
	//½Ã¿µÂ» ³» µ¿·á°¡ µÅ¶ó - ±«µµ Á¦ÀÌ
	//lejADD ´øÀü ¸Ê Ãß°¡
	_player = new player;
	_player->init("player", tagFloat(1631, 1848));
	_player->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	_em = new enemyController;
	_em->init();
	
	_im = new itemManager;
	_im->init();

	vector<gameObject*> _vWeeds = OBJECTMANAGER->findObjects(objectType::ENEMY, "weed");

	for (int i = 0; i < _vWeeds.size(); i++)
	{
		((weed*)_vWeeds[i])->setPixelImage(IMAGEMANAGER->findImage("dungeonRedZone"));
	
	}

	CAMERAMANAGER->setMapSize(3840, 2160);
	CAMERAMANAGER->connectTarget(1920, 1800);
	//CAMERAMANAGER->_pos.x = 1920;
	//CAMERAMANAGER->_pos.y = 1800;


	_enterRc[0] = RectMakeCenter(1916, 1455, 50, 50);
	_enterRc[1] = RectMakeCenter(1912, 1391, 50, 50);
	_enterRc[2] = RectMakeCenter(1341, 1080, 50, 50);
	_enterRc[3] = RectMakeCenter(1203, 1075, 50, 50);
	_enterRc[4] = RectMakeCenter(1935, 773, 50, 50);
	_enterRc[5] = RectMakeCenter(1951, 631, 50, 50);
	_enterRc[6] = RectMakeCenter(2482, 346, 50, 50);
	_enterRc[7] = RectMakeCenter(2618, 346, 50, 50);
	_enterRc[8] = RectMakeCenter(3760, 360, 50, 50);

	return S_OK;
}

void dungeonScene::release()
{
	
	_em->release();
	SAFE_DELETE(_em);
	//
	_im->release();
	SAFE_DELETE(_im);
}

void dungeonScene::update()
{
	//CAMERAMANAGER->update();

	//CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);

	OBJECTMANAGER->update();

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("bossRoomScene");
	}
<<<<<<< HEAD
	
	_im->update();
=======

>>>>>>> 77b635cc87d82f6c2a16b0f3a7034f0863023f67
	this->moveDungeon();


	CAMERAMANAGER->cameraSlideMove(_player->getSpeed());

	_im->update();
}

void dungeonScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	IMAGEMANAGER->render("dungeonMap", getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);

	OBJECTMANAGER->render(getMemDC());

	_im->render();
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
	


	for (int i = 0; i < 9; ++i)
	{
		RectangleCam(getMemDC(), _enterRc[i], cam);
	}


	char str[128];
	sprintf_s(str, "%f, %f", _player->pos.x, _player->pos.y);
	TextOut(getMemDC(), 200, 200, str, strlen(str));
}

void dungeonScene::moveDungeon()
{

	RECT temp;
	
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[0]))
	{
		CAMERAMANAGER->connectTarget((int)1920, (int)1080);
		_player->pos.x = 1916;
		_player->pos.y = 1266;
	}
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[1]))
	{
		CAMERAMANAGER->connectTarget((int)1920, (int)1800);
		_player->pos.x = 1916;
		_player->pos.y = 1644;
	}
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[2]))
	{
		//CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
		CAMERAMANAGER->connectTarget((int)640, (int)1080);
		_player->pos.x = 647;
		_player->pos.y = 1077;
	}
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[3]))
	{
		CAMERAMANAGER->connectTarget((int)1920, (int)1080);
		_player->pos.x = 1400;
		_player->pos.y = 1266;
	}
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[4]))
	{
		CAMERAMANAGER->connectTarget((int)1920, (int)360);
		_player->pos.x = 1520;
		_player->pos.y = 360;
	}
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[5]))
	{
		CAMERAMANAGER->connectTarget((int)1920, (int)1080);
		_player->pos.x = 1920;
		_player->pos.y = 1080;
	}
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[6]))
	{
		CAMERAMANAGER->connectTarget((int)3200, (int)360);
		_player->pos.x = 3200;
		_player->pos.y = 360;
	}
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[7]))
	{
		CAMERAMANAGER->connectTarget((int)1920, (int)360);
		_player->pos.x = 1520;
		_player->pos.y = 360;
	}
	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc[8]))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("bossRoomScene");
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
