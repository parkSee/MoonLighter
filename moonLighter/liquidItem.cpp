#include "stdafx.h"
#include "liquidItem.h"

HRESULT liquidItem::init()
{
	_pos = tagFloat(2200, 1800);
	_img = IMAGEMANAGER->findImage("liquidItem");
	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

	return S_OK;
}

void liquidItem::release()
{
}

void liquidItem::update()
{
}

void liquidItem::render()
{
	RECT camRC;
	camRC = CAMERAMANAGER->getRenderRc();
	_img->render(getMemDC(), _pos.x - camRC.left, _pos.y - camRC.top);

	//IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
