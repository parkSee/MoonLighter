#include "stdafx.h"
#include "potion.h"


HRESULT potion::init()
{
	_pos = tagFloat(WINSIZEX / 2, WINSIZEY / 2);
	_img = IMAGEMANAGER->findImage("potion");

	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

	return S_OK;
}

void potion::release()
{
}

void potion::update()
{
}

void potion::render()
{
	RECT camRC;
	camRC = CAMERAMANAGER->getRenderRc();
	_img->render(getMemDC(), _pos.x - camRC.left, _pos.y - camRC.top);

	//IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
