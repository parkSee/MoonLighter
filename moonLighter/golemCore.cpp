#include "stdafx.h"
#include "golemCore.h"

//csyADD [golemCore 아이템의 좌표, 이미지, 충돌박스 초기화 및 랜더 추가]

HRESULT golemCore::init()
{
	_pos = tagFloat(WINSIZEX / 2, WINSIZEY / 4);
	_img = IMAGEMANAGER->findImage("potion");
	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

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
