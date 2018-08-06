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
	_aiKid->init("aiKid", tagFloat(650, 1303));
	OBJECTMANAGER->addObject(objectType::AI, _aiKid);

	//_aiGirl = new AIGirl;
	//_aiGirl->init("aiGirl", tagFloat(650, 1303));
	//OBJECTMANAGER->addObject(objectType::AI, _aiGirl);

	//_aiLink = new AILink;
	//_aiLink->init("aiGirl", tagFloat(650, 1303));
	//OBJECTMANAGER->addObject(objectType::AI, _aiLink);

	

	_inven = new inventory;
	_inven->init();
	
	CAMERAMANAGER->setMapSize(WINSIZEX, 1440);

	SOUNDMANAGER->play("shopBGM");

	_enterRc = RectMakeCenter(650, 1290, 50, 50);

	

	_furniture = new furnitureContainer;
	_furniture->init();


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
	if (IntersectRect(&temp,&_player->getRcBody(), &_enterRc))
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");
		_player->pos.x = 1952;
		_player->pos.y = 770;
		SOUNDMANAGER->stop("shopBGM");
	}
	_enterRc = RectMakeCenter(650, 1290, 50, 50);

	_inven->update();
}
 
void shopScene::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();


	IMAGEMANAGER->findImage("shopMap")->render(getMemDC(),0- cam.left,0 - cam.top);//, 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->findImage("shopPixel")->render(getMemDC(), 0 - cam.left, 0 - cam.top);//, 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	}

	
	OBJECTMANAGER->render(getMemDC());
	IMAGEMANAGER->findImage("shopLayer")->render(getMemDC(), 570 - cam.left, 603 - cam.top);
	

	RectangleCam(getMemDC(), _enterRc, cam);
	
	_inven->render();
}
