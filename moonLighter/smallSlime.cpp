#include "stdafx.h"
#include "smallSlime.h"


HRESULT smallSlime::init(string _objName, tagFloat _pos)
{

	gameObject::init(_objName, _pos);
	_smallSlime = IMAGEMANAGER->findImage("작은슬라임");
	_attackedSmallSlime[0] = IMAGEMANAGER->findImage("작은슬라임빨강");
	_attackedSmallSlime[1] = IMAGEMANAGER->findImage("작은슬라임하양");
	_count = _currentX = _attackedCount = _currentY = 0;
	rc = RectMakeCenter(pos.x, pos.y, _smallSlime->getFrameWidth(), _smallSlime->getFrameHeight());


	_noneAttacked = true;//공격안받았을때
	_isAttacked = false; // 공격받았다는 신호
	_isAttacked2 = false;
	_xCollision = false;
	_yCollision = false;


	return S_OK;
}

void smallSlime::release()
{
}

void smallSlime::update()
{
	_count++;
	smallSlimeFrame();
	move();
	rc = RectMakeCenter(pos.x, pos.y, _smallSlime->getFrameWidth(), _smallSlime->getFrameHeight());

	if (_isAttacked)
	{
		pos.x += 5 * cosf(PI - angle);
		pos.y += 5 * sinf(PI - angle);
	}
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		//_isDead = true;
		EFFECTMANAGER->play("뿅뿅", pos.x + 10, pos.y + 10);
	}

	pixelCollision();
}

void smallSlime::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();


	if (_noneAttacked)_smallSlime->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);

	if (_isAttacked2)
	{
		_attackedCount++;
		if (_attackedCount > 3)
		{
			_isAttacked2 = false;
			_isAttacked = false;
			_noneAttacked = true;
			_attackedCount = 0;
		}
		_attackedSmallSlime[1]->setFrameX(_currentX);
		_attackedSmallSlime[1]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
	}
	if (_isAttacked)
	{
		_attackedCount++;
		if (_attackedCount > 3)
		{
			_isAttacked = false;
			_isAttacked2 = true;
			_attackedCount = 0;
		}

		_attackedSmallSlime[0]->setFrameX(_currentX);
		_attackedSmallSlime[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
	}
	if (KEYMANAGER->isOnceKeyDown('L'))
	{
		_isAttacked = true;
		_noneAttacked = false;
	}
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

void smallSlime::pixelCollision()
{
	_rc[0] = RectMakeCenter(pos.x + _smallSlime->getFrameWidth() / 2, pos.y, 2, _smallSlime->getFrameHeight());//오른쪽
	_rc[1] = RectMakeCenter(pos.x - _smallSlime->getFrameWidth() / 2, pos.y, 2, _smallSlime->getFrameHeight());//왼쪽
	_rc[2] = RectMakeCenter(pos.x, pos.y - _smallSlime->getFrameHeight() / 2, _smallSlime->getFrameWidth(), 2);//위
	_rc[3] = RectMakeCenter(pos.x, pos.y + _smallSlime->getFrameHeight() / 2, _smallSlime->getFrameWidth(), 2);//아래


	_rc0X = pos.x + _smallSlime->getFrameWidth() / 2;
	_rc0Y = pos.y - _smallSlime->getFrameHeight() / 2;

	_rc1X = pos.x - _smallSlime->getFrameWidth() / 2;
	_rc1Y = pos.y - _smallSlime->getFrameHeight() / 2;

	_rc2Y = pos.y - _smallSlime->getFrameHeight() / 2;
	_rc2X = pos.x - _smallSlime->getFrameWidth() / 2;


	_rc3Y = pos.y + _smallSlime->getFrameHeight() / 2;
	_rc3X = pos.x - _smallSlime->getFrameWidth() / 2;



	for (int j = _rc0Y + 5; j < pos.y + _smallSlime->getFrameHeight() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), pos.x + _smallSlime->getFrameWidth() / 2, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.x = pos.x + _smallSlime->getFrameWidth() / 2 - 27;
			break;
		}


	}
	for (int j = _rc1Y + 5; j < pos.y + _smallSlime->getFrameHeight() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), pos.x - _smallSlime->getFrameWidth() / 2, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.x = pos.x - _smallSlime->getFrameWidth() / 2 + 27;
			break;
		}

	}
	for (int j = _rc2X + 5; j < pos.x + _smallSlime->getFrameWidth() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), j, pos.y + _smallSlime->getFrameHeight() / 2);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.y = pos.y + _smallSlime->getFrameWidth() / 2 - 27;
			break;
		}

	}
	for (int j = _rc2X + 5; j < pos.x + _smallSlime->getFrameWidth() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), j, pos.y - _smallSlime->getFrameHeight() / 2);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.y = pos.y - _smallSlime->getFrameWidth() / 2 + 27;
			break;
		}

	}
}

void smallSlime::move()
{
	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	angle = getAngle(pos.x, pos.y, _player->pos.x, _player->pos.y);
	speed = 1.2f;

	if (_xCollision == false)pos.x += speed * cosf(angle);
	if (_yCollision == false)pos.y += speed * -sinf(angle);
}







