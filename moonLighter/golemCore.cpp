#include "stdafx.h"
#include "golemCore.h"

//csyADD [golemCore cpp - 테스트 용 포지션 변경]

HRESULT golemCore::init()
{
	_pos = tagFloat(1620, 1730);
	_img = IMAGEMANAGER->findImage("golemCore");
	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

	// OBJECTMANAGER->findObject(objectType::ENEMY,"golem") //csyADD 이거는 어떻게 사용해야할지 테스트 한거

	return S_OK;
}

void golemCore::release()
{
}

void golemCore::update()
{
}

void golemCore::render()
{
	RECT camRC;
	camRC = CAMERAMANAGER->getRenderRc();
	_img->render(getMemDC(), _pos.x - camRC.left, _pos.y - camRC.top);

	//IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
