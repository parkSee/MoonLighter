#include "stdafx.h"
#include "rebar.h"


HRESULT rebar::init()
{
	_pos = tagFloat(WINSIZEX / 2, WINSIZEY / 3);
	_img = IMAGEMANAGER->findImage("rebar");
	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

	return S_OK;
}

void rebar::release()
{
}

void rebar::update()
{
}

void rebar::render()
{
	RECT camRC;
	camRC = CAMERAMANAGER->getRenderRc();
	_img->render(getMemDC(), _pos.x - camRC.left, _pos.y - camRC.top);

	//IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
