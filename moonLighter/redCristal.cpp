#include "stdafx.h"
#include "redCristal.h"

//csyADD [redCristal 아이템의 좌표, 이미지, 충돌박스 초기화 및 랜더 추가]

HRESULT redCristal::init()
{
	_pos = tagFloat(WINSIZEX / 3, WINSIZEY / 2);
	_img = IMAGEMANAGER->findImage("potion");
	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

	return S_OK;
}

void redCristal::release()
{
}

void redCristal::update()
{
}

void redCristal::render()
{
	RECT camRC;
	camRC = CAMERAMANAGER->getRenderRc();
	_img->render(getMemDC(), _pos.x - camRC.left, _pos.y - camRC.top);

	//IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
