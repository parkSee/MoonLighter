#include "stdafx.h"
#include "twig.h"


HRESULT twig::init()
{
	_pos = tagFloat(WINSIZEX / 4, WINSIZEY / 2);
	_img = IMAGEMANAGER->findImage("twig");
	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

	return S_OK;
}

void twig::release()
{
}

void twig::update()
{
}

void twig::render()
{
	RECT camRC;
	camRC = CAMERAMANAGER->getRenderRc();
	_img->render(getMemDC(), _pos.x - camRC.left, _pos.y - camRC.top);

	//IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
