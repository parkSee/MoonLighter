#include "stdafx.h"
#include "item.h"


HRESULT item::init(tagFloat pos , image* _im)
{

	_img = _im;
	_pos = pos;
	_price = 100;
	_rc = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());
	_isActive = false;

	return S_OK;
}

void item::release()
{

}

void item::update()
{
}

void item::render(HDC hdc)
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	if (_isActive == true)
	{
		//RectangleCam(hdc, _rc, cam);
		_img->render(hdc, _pos.x - cam.left, _pos.y - cam.top);
	}
	
}

