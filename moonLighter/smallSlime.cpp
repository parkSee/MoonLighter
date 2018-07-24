#include "stdafx.h"
#include "smallSlime.h"


HRESULT smallSlime::init(string _objName, tagFloat _pos)
{

	gameObject::init(_objName, _pos);
	_smallSlime = IMAGEMANAGER->addFrameImage("작은슬라임", "./image/enemy/작은슬라임.bmp", 3000, 55, 60, 1);
	_count = _currentX = _currentY = 0;
	rc = RectMakeCenter(pos.x, pos.y, _smallSlime->getFrameWidth(), _smallSlime->getFrameHeight());

	return S_OK;
}

void smallSlime::release()
{
}

void smallSlime::update()
{
	_count++;
	smallSlimeFrame();
	rc = RectMakeCenter(pos.x, pos.y, _smallSlime->getFrameWidth(), _smallSlime->getFrameHeight());
}

void smallSlime::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	_smallSlime->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
}

void smallSlime::smallSlimeFrame()
{
	if (_count % 7 == 0)
	{
		
		_smallSlime->setFrameX(_currentX);
		_smallSlime->setFrameY(0);
		_currentX++;


		if (_currentX > 23)
		{
			_currentX = 0;
		}

	}
}

