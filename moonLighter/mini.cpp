#include "stdafx.h"
#include "mini.h"

//局呈固 茄付府 积己

HRESULT mini::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);

	pos = _pos;

	rc = RectMakeCenter(pos.x, pos.y, 50, 50);
	count = 0;
	isRight = false;

	return S_OK;
}

void mini::release()
{
}

void mini::update()
{
	this->move();



	rc = RectMakeCenter(pos.x, pos.y, 50, 50);
}

void mini::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top, rc.right - cam.left, rc.bottom - cam.top);

}

void mini::move()
{
	
	pos.x++;

}

