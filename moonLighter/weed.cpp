#include "stdafx.h"
#include "weed.h"


HRESULT weed::init(string _objName, tagFloat _pos)
{

	gameObject::init(_objName,_pos);
	_weed = IMAGEMANAGER->addFrameImage("説段", "./image/enemy/説段.bmp", 4200, 90, 60, 1);
	_weedFrameX = _weedFrameY = _count = 0;
	rc = RectMakeCenter(pos.x, pos.y, _weed->getFrameWidth(), _weed->getFrameHeight());

	return S_OK;
}

void weed::release()
{
}

void weed::update()
{
	_count++;
	weedFrame();
	rc = RectMakeCenter(pos.x, pos.y, _weed->getFrameWidth(), _weed->getFrameHeight());
}

void weed::render()
{
	//Rectangle(getMemDC(), rc);
	RECT cam = CAMERAMANAGER->getRenderRc();
	_weed->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
}

void weed::weedFrame()
{
	if (_count % 7 == 0)
	{
		_weed->setFrameX(_weedFrameX);
		_weed->setFrameY(0);
		_weedFrameX++;


		if (_weedFrameX > IMAGEMANAGER->findImage("説段")->getMaxFrameX())
		{
			_weedFrameX = 0;
		}

	}
}

