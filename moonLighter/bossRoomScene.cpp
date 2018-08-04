#include "stdafx.h"
#include "bossRoomScene.h"

HRESULT bossRoomScene::init()
{

	_player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	//	_player->init("player", tagFloat(1580, 1900));
	_player->pos.x = 1580;
	_player->pos.y = 1900;

	_player->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));

	 _boss = new boss;
	_boss->init("boss", tagFloat(1600, 1000));
	OBJECTMANAGER->addObject(objectType::ENEMY, _boss);
	_boss->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));
	_boss->setBossSpeed(1.0f);
	_bossHp = new progressBar;
	_bossHp->init("보스체력", "보스체력껍데기", 100, 600, 1000, 14);
	_currentHp = 300;
	_dmgCount = _blackBgCount=0;
	_blackBgAlpha = 0;
	_deadCount = 0;
	_damaged = false;
	_dmgCountBool = false;
	for (int i = 0; i < MAXBOSS; i++)
	{
		_clone[i] = false;
	}
	_blackBgBool = false;
	

	_blackBg = IMAGEMANAGER->findImage("검은화면");


	CAMERAMANAGER->setMapSize(3152, 2131);

/*
	_test = new progressBar;
	_test->init("testF", "testB", WINSIZEX / 2, WINSIZEY / 2, 20, 600);*/
	


	return S_OK;
}

void bossRoomScene::release()
{


}

void bossRoomScene::update()
{
	
	if (((boss*)OBJECTMANAGER->findObject(objectType::ENEMY, "boss"))->getStart() == true)
	{
		CAMERAMANAGER->connectTarget(((boss*)OBJECTMANAGER->findObject(objectType::ENEMY, "boss"))->pos.x, ((boss*)OBJECTMANAGER->findObject(objectType::ENEMY, "boss"))->pos.y);
		
		CAMERAMANAGER->cameraSlideMove(8.0f);
	}
	else
	{
		CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
		CAMERAMANAGER->update();
	}

	OBJECTMANAGER->update();

	// csyADD [보스륨 cpp - c누르면 타운씬 넘어간다]
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
	}

	/*_test->setX(WINSIZEX/2);
	_test->setY(WINSIZEY-200);
	_test->update();
	_test->setHeightGuge(_currentHp, 200);*/

	_bossHp->update();
	
	_bossHp->setX(150);
	_bossHp->setY(600);
	
	//_boss->damagged();
	RECT tempRc;
	if (IntersectRect(&tempRc, &((player*)_player)->getRcSword(), &_boss->getCollisionRC()) && _damaged==false)
	{
		_damaged = true;
		_dmgCountBool = true;
		_currentHp -= 20;
	}

	//for(int i=0;i<MAXBOSS;i++)
	//{
	//	if (_clone[i])
	//	{
	//		if (IntersectRect(&tempRc, &((player*)_player)->getRcSword(), &_boss2->getCollisionRC()) && _damaged == false)
	//		{
	//
	//			_damaged = true;
	//			_dmgCountBool = true;
	//			_currentHp -= 10;
	//			_deadCount++;
	//			
	//			if (_deadCount == 2)
	//			{
	//				removeClone();
	//			}
	//		}
	//	}
	//}
		
	
	vector<gameObject*> _cloneBoss = OBJECTMANAGER->findObjects(objectType::ENEMY, "cloneBoss");
	for (int i = 0; i < _cloneBoss.size(); i++)
	{
		if (IntersectRect(&tempRc, &((player*)_player)->getRcSword(), &((boss*)_cloneBoss[i])->getCollisionRC()) &&_damaged==false)
		{
			_damaged = true;
			_dmgCountBool = true;
			_currentHp -= 10;
			_deadCount++;
	
			if (_deadCount == 2)
			{
				removeClone(i);
			}
		}
	}
	



	_bossHp->setGauge(_currentHp, 300);

	if (_dmgCountBool)
	{
		_dmgCount++;
	}
	if (_dmgCount>30)
	{
		_dmgCount = 0;
		_dmgCountBool = false;
		_damaged = false;
		
	}
	for (int i = 0; i < MAXBOSS ;i++)
	{
		if (_currentHp < 280 - 50 * i  && _clone[i]==false)
		{
			_clone[i] = true;
			this->cloneBoss();
			CAMERAMANAGER->shakeCamera(5.0f, 0.001f);
		}
	}
	
	

}

void bossRoomScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	IMAGEMANAGER->render("bossRoom", getMemDC(), 0, 0, cam.left, cam.top, WINSIZEX, WINSIZEY);

	OBJECTMANAGER->render(getMemDC());
	_bossHp->render();
	char str[128];
	sprintf(str, "_dmgCount:%d , _currentHp: %d , _damaged = %d ,_deadCount: %d", _dmgCount,_currentHp,_damaged,_deadCount);
	TextOut(getMemDC(), 100, WINSIZEY / 2, str, strlen(str));
	_blackBg->alphaRender(getMemDC(), _blackBgAlpha);
	//_test->renderHeight();
	
}

void bossRoomScene::cloneBoss()
{
	int rndNum = RND->getInt(2);
	if ( rndNum == 0)rndNum = -1;
	_boss2 = new boss;
	_boss2->setBossSpeed(3.0f);
	_boss2->init("cloneBoss", tagFloat(_boss->pos.x+ (rndNum)*(500), _boss->pos.y));
	OBJECTMANAGER->addObject(objectType::ENEMY, _boss2);
	_boss2->setPixelImage(IMAGEMANAGER->findImage("bossRoomRedZoon"));

}

void bossRoomScene::removeClone(int index)
{
	vector<gameObject*> _cloneBoss = OBJECTMANAGER->findObjects(objectType::ENEMY, "cloneBoss");
	_cloneBoss[index]->setIsLive(false);
	_deadCount = 0;

}

