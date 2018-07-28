#include "stdafx.h"
#include "redCristal.h"


HRESULT redCristal::init()
{
	_pos = tagFloat(WINSIZEX / 3, WINSIZEY / 2);
	_img = IMAGEMANAGER->findImage("redCristal");
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
