#include "stdafx.h"
#include "shopScene.h"

//csyADD [인벤 출력 테스트 용 추가]

HRESULT shopScene::init()
{
	//나중에 씬매니저 추가해서 옮겨 놓을겁니다. 
	_player = (player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	_player->pos.x = WINSIZEX / 2;
	_player->pos.y = 1000;
	_player->setPixelImage(IMAGEMANAGER->findImage("shopPixel"));

	_aiKid = new AIKids;
	_aiKid->init("aiKid", tagFloat(600, 1303));
	OBJECTMANAGER->addObject(objectType::AI, _aiKid);

	_inven = new inventory;
	_inven->init();
	
	CAMERAMANAGER->setMapSize(WINSIZEX, 1440);

	SOUNDMANAGER->play("shopBGM");

	_buttonUi = IMAGEMANAGER->findImage("buttonUi");
	_buttonAction = IMAGEMANAGER->findImage("button");
	_jButton = IMAGEMANAGER->findImage("jButton");

	
	_enterRc = RectMakeCenter(650, 1290, 50, 50);

	

	_furniture = new furnitureContainer;
	_furniture->init();

	_exitCount = 0;
	_isExit = _isOpen = false;

	_count = _index  = _index2 = 0;

	return S_OK;
}

void shopScene::release()
{
	SAFE_DELETE(_inven);
}

void shopScene::update()
{
	OBJECTMANAGER->update();
	CAMERAMANAGER->connectTarget(_player->pos.x, _player->pos.y);
	CAMERAMANAGER->update();
	RECT temp;


	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc))
	{
		this->uiFrame();

		if (KEYMANAGER->isStayKeyDown('J'))
		{
			_exitCount++;
			_isOpen = true;

			if (_exitCount > 10)
			{
				this->buttonActionFrame();

			}
		}
		if (KEYMANAGER->isOnceKeyUp('J'))
		{
			_isOpen = false;
			
			if (_exitCount < 10)
			{
				OBJECTMANAGER->reset();
				SCENEMANAGER->loadScene("townScene");
				_player->pos.x = 1952;
				_player->pos.y = 770;
				SOUNDMANAGER->stop("shopBGM");
				_exitCount = 0;
				

			}
			_exitCount = 0;
			_index = 0;
		}


	}
	else
		_index = 0;

	_enterRc = RectMakeCenter(650, 1290, 50, 50);

	_inven->update();
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
	

	if (_exitCount > 10)
	{
		_buttonAction->frameRender(getMemDC(), 751 - cam.left, 1160 - cam.top);
	}

	if (IntersectRect(&temp, &_player->getRcBody(), &_enterRc) && _isOpen == false)
	{
		_buttonUi->frameRender(getMemDC(), 751 - cam.left, 1160 - cam.top);

	}
	RectangleCam(getMemDC(), _enterRc, cam);
	
	_inven->render();
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
	_count++;

	_buttonAction->setFrameX(_index2);

	if (_count % 10 == 0)
	{
		++_index2;
		if (_index2 > _buttonAction->getMaxFrameX())
		{
			_index2 = _buttonAction->getMaxFrameX();

		}
	}



}

