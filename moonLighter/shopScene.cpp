#include "stdafx.h"
#include "shopScene.h"


//csyADD [인벤 출력 테스트 용 추가]

HRESULT shopScene::init()
{

	_vol = SAVEDATA->getVolume();

	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 
	_player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	_player->pos.x = WINSIZEX / 2;
	_player->pos.y = 1000;
	_player->setPixelImage(IMAGEMANAGER->findImage("shopPixel"));

	_shopDoor = IMAGEMANAGER->findImage("shopDoor");

	
		
	_aiKid = new AIKids;
	_aiKid->init("aiKid", tagFloat(650, 1303));
	OBJECTMANAGER->addObject(objectType::AI, _aiKid);
	
	_aiGirl = new AIGirl;
	_aiGirl->init("aiGirl", tagFloat(650, 1303));
	OBJECTMANAGER->addObject(objectType::AI, _aiGirl);
	
	_aiLink = new AILink;
	_aiLink->init("aiGirl", tagFloat(650, 1303));
	OBJECTMANAGER->addObject(objectType::AI, _aiLink);
	
	
	_display = SAVEDATA->get_display();

	
	CAMERAMANAGER->setMapSize(WINSIZEX, 1440);

	SOUNDMANAGER->play("shopBGM",_vol);

	_buttonUi = IMAGEMANAGER->findImage("buttonUi");
	_buttonAction = IMAGEMANAGER->findImage("button");
	_jButton = IMAGEMANAGER->findImage("jButton");
	_layer = IMAGEMANAGER->findImage("shop_door_layer");
	
	_enterRc = RectMakeCenter(650, 1290, 50, 50);

	

	_furniture = new furnitureContainer;
	_furniture->init();

	_exitCount = 0;
	_outCount = 0;
	_count2 = 0;
	_exitCount = 0;
	_index3 = 0;
	_count3 = 0;
	_isExit = _isOpen = false;
	_j = false;
	_button = false;
	_ui = false;
	_AICount=0;

	_count = _index  = _index2 = 0;

	return S_OK;
}

void shopScene::release()
{
	_display->release();
}

void shopScene::update()
{
	_AICount++;

	if (_AICount == 50)
	{
		_aiKid->set_startAIKids(true);
	}
	if (_AICount == 250)
	{
		_aiGirl->set_startAIGirl(true);
	}
	if (_AICount == 500)
	{
		_aiLink->set_startAILink(true);
	}
	if (_aiKid->get_startAIKids() && _aiGirl->get_startAIGirl() && _aiLink->get_startAILink())
	{
		_AICount = 0;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))
	{
		_aiKid->set_startAIKids(false);
		_aiGirl->set_startAIGirl(false);
		_aiLink->set_startAILink(false);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD1))
	{
		_aiKid->set_startAIKids(true);
		_aiGirl->set_startAIGirl(true);
		_aiLink->set_startAILink(true);
	}


	OBJECTMANAGER->update();
	CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
	CAMERAMANAGER->update();
	
	RECT temp;

	

	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc))
	{
		_ui = true;

		if (KEYMANAGER->isStayKeyDown('J'))
		{
			_button = true;
			_outCount++;
		}
		if (KEYMANAGER->isOnceKeyUp('J'))
		{
			_button = false;
			_count2 = 0;
			_index2 = 0;
			_exitCount = _outCount;
		}
		SAVEDATA->set_display(_display);

	}
	else
	{
		_ui = false;
		_index = 0;
		_index2 = 0;
	}
	
	if(_ui)uiFrame();
	if(_button)buttonActionFrame();

	_enterRc = RectMakeCenter(650, 1230, 50, 50);

	RECT rcTemp;
	if (IntersectRect(&rcTemp, &_aiKid->rc, &_enterRc) || IntersectRect(&rcTemp, &_aiGirl->rc, &_enterRc)|| IntersectRect(&rcTemp, &_aiLink->rc, &_enterRc))
	{
		this->doorFrame();
	}
	else
	{
		this->RdoorFrame();
	}

	if ( 1<_exitCount&&_exitCount < 10)
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
		_player->pos.x = 1952;
		_player->pos.y = 770;
		SOUNDMANAGER->stop("shopBGM");
		
		_outCount = 0;
	}
	if (_index2 == _buttonAction->getMaxFrameX())
	{
		_outCount = 0;
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
		_player->pos.x = 1952;
		_player->pos.y = 770;
		SOUNDMANAGER->stop("shopBGM");

	}

	if (KEYMANAGER->isStayKeyDown('Y'))
	{
		doorFrame();
	}
	if (KEYMANAGER->isStayKeyDown('U'))
	{
		RdoorFrame();
	}
	_display->update();
}
 
void shopScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	RECT temp;

	IMAGEMANAGER->findImage("shopMap")->render(getMemDC(),0- cam.left,0 - cam.top);//, 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("shopPixel")->render(getMemDC(), 0 - cam.left, 0 - cam.top);//, 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	}

	
	OBJECTMANAGER->render(getMemDC());
	IMAGEMANAGER->findImage("shopLayer")->render(getMemDC(), 570 - cam.left, 603 - cam.top);
	_layer->render(getMemDC(), 558 - cam.left, 1234 - cam.top);
	
	
		if(_ui && !_button)_buttonUi->frameRender(getMemDC(), 751 - cam.left, 1160 - cam.top);
		if(_button)_buttonAction->frameRender(getMemDC(), 751 - cam.left, 1160 - cam.top);
	
		_shopDoor->frameRender(getMemDC(), 600 - cam.left, 1170 - cam.top);
	
	_display->render();
	//RectangleCam(getMemDC(), _enterRc, cam);
	
	_player->renderUI(); //csyADD [요성님 이제 이렇게 플레이어 관련 UI 랜더하세요]
}

void shopScene::uiFrame()
{

	_count++;

	_buttonUi->setFrameX(_index);

	if (_count % 10 == 0)
	{
		++_index;
		if (_index > _buttonUi->getMaxFrameX())
		{
			_index = _buttonUi->getMaxFrameX();

		}
	}


}

void shopScene::buttonActionFrame()
{
	_count2++;

	_buttonAction->setFrameX(_index2);

	if (_count2 % 5 == 0)
	{
		++_index2;
		if (_index2 > _buttonAction->getMaxFrameX())
		{
			_index2 = _buttonAction->getMaxFrameX();

		}
	}



}

void shopScene::doorFrame()
{
	_count3++;

	_shopDoor->setFrameX(_index3);

	if (_count3 % 5 == 0)
	{
		++_index3;
		if (_index3 > _shopDoor->getMaxFrameX())
		{
			_index3 = _shopDoor->getMaxFrameX();

		}
	}

}

void shopScene::RdoorFrame()
{
	_count3++;

	_shopDoor->setFrameX(_index3);

	if (_count3 % 5 == 0)
	{
		--_index3;
		if (_index3 < 0)
		{
			_index3 =0;

		}
	}
}

