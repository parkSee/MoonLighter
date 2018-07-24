#include "stdafx.h"
#include "potion.h"


HRESULT potion::init()
{


	_pos = tagFloat(WINSIZEX / 2, WINSIZEY / 2);
	_img = IMAGEMANAGER->findImage("potion");

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
	//_img->render(hdc, pos.x, pos.y);

	IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
