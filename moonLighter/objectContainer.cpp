#include "stdafx.h"
#include "objectContainer.h"


HRESULT objectContainer::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);


	_img[0] = IMAGEMANAGER->addImage("build_Retaile", "./Image/build_Retaile.bmp",10,123, 279, 294, true, RGB(255, 0, 255));
	
	return S_OK;
}

void objectContainer::release()
{
}

void objectContainer::update()
{
	//rc = RectMakeCenter(pos.x, pos.y, _img[0]->getWidth(), _img[0]->getHeight());
}

void objectContainer::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	IMAGEMANAGER->render("build_Retaile", getMemDC(),10 - cam.left, 123 - cam.top);

	//Rectangle(getMemDC(), rc.left - cam.left,rc.top-cam.top, rc.right- cam.left, rc.bottom - cam.top);
}
