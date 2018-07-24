#include "stdafx.h"
#include "bigSlime.h"
#include"player.h"

HRESULT bigSlime::init(string _objName, tagFloat _pos)
{

	gameObject::init(_objName, _pos);
	_bigSlime = IMAGEMANAGER->addFrameImage("큰슬라임", "./image/enemy/큰슬라임.bmp", 6000, 110, 60, 1);
	rc = RectMakeCenter(pos.x, pos.y, _bigSlime->getFrameWidth(), _bigSlime->getFrameHeight());
	_alpha = 255;
	_count = _currentX = _currentY = 0;
	_slimeBool = false;

	return S_OK;
}

void bigSlime::release()
{
}

void bigSlime::update()
{
	_count++;
	bigSlimeFrame();
	rc = RectMakeCenter(pos.x, pos.y, _bigSlime->getFrameWidth(), _bigSlime->getFrameHeight());

	if (KEYMANAGER->isOnceKeyDown('B'))
	{
		_slimeBool = true;
		_currentX = 24;
	}

	move();
}

void bigSlime::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top, rc.right - cam.left, rc.bottom - cam.top);
	_bigSlime->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _alpha);
	
}

void bigSlime::bigSlimeFrame()
{
	if (_count % 7 == 0)
	{

		_bigSlime->setFrameX(_currentX);

		_currentX++;

		if (_slimeBool)
		{
			if (_currentX >= 34)
				_alpha = 200;
			if (_currentX > _bigSlime->getMaxFrameX())
			{
				_currentX = 0;
				_slimeBool = false;
			}
		}

		if (!_slimeBool)
		{
			if (_currentX > 23)
			{
				_currentX = 0;
			}
		}

	}
}

void bigSlime::move()
{
	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	float angle = getAngle(pos.x, pos.y, _player->pos.x + (_player->rc.right - _player->rc.left), _player->pos.y+ (_player->rc.bottom - _player->rc.top));
	float speed = 2.0f;
	
	pos.x += speed * cosf(angle);
	pos.y += speed * -sinf(angle);
	


}
