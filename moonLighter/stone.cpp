#include "stdafx.h"
#include "stone.h"


HRESULT stone::init(string _objName, tagFloat _pos, image * imgName)
{
	gameObject::init(_objName, _pos);

	_img = imgName;
	rc = RectMakeCenter(pos.x, pos.y, _img->getWidth(), _img->getHeight());

	return S_OK;
}

void stone::release()
{
}

void stone::update()
{
}

void stone::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	//	Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top, rc.right - cam.left, rc.bottom - cam.top);
	_img->render(getMemDC(), rc.left - cam.left, rc.top - cam.top);


}


