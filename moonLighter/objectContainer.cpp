#include "stdafx.h"
#include "objectContainer.h"


HRESULT objectContainer::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);

	pos = _pos;

	_img = IMAGEMANAGER->addImage("house", "./Image/home.bmp", 353, 392, true, RGB(255, 0, 255));
	
	return S_OK;
}

void objectContainer::release()
{
}

void objectContainer::update()
{
	rc = RectMakeCenter(pos.x, pos.y, _img->getWidth(), _img->getHeight());
}

void objectContainer::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	IMAGEMANAGER->render("house", getMemDC(), rc.left - cam.left, rc.top - cam.top);

	//Rectangle(getMemDC(), rc.left - cam.left,rc.top-cam.top, rc.right- cam.left, rc.bottom - cam.top);
}
