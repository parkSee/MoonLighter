#include "stdafx.h"
#include "bigSlime.h"


HRESULT bigSlime::init(string _objName, tagFloat _pos)
{

	gameObject::init(_objName, _pos);
	_bigSlime = IMAGEMANAGER->findImage("큰슬라임");
	_attackedBigSlime[0] = IMAGEMANAGER->findImage("큰슬라임빨강");
	_attackedBigSlime[1] = IMAGEMANAGER->findImage("큰슬라임하양");
	//EFFECTMANAGER->addEffect("뿅뿅",)
	rc = RectMakeCenter(pos.x, pos.y, _bigSlime->getFrameWidth(), _bigSlime->getFrameHeight());
	_alpha = 255;
	_count = _currentX = _attackedCount = _currentY = 0;
	_slimeBool = false;
	_noneAttacked = true;//공격안받았을때
	_isAttacked = false; // 공격받았다는 신호
	_isAttacked2 = false;
	 _xCollision =false;
	 _yCollision =false;

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

	if (_isAttacked)
	{
		pos.x += 5 * cosf(PI - angle);
		pos.y += 5 * sinf(PI - angle);
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		//_isDead = true;
		EFFECTMANAGER->play("뿅뿅", pos.x + 5, pos.y + 20);
	}

	this->pixelCollision();

}

void bigSlime::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	//Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top, rc.right - cam.left, rc.bottom - cam.top);
	if (_noneAttacked)_bigSlime->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _alpha);

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
		_attackedBigSlime[1]->setFrameX(_currentX);
		_attackedBigSlime[1]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _alpha);
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

		_attackedBigSlime[0]->setFrameX(_currentX);
		_attackedBigSlime[0]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _alpha);
	}
	if (KEYMANAGER->isOnceKeyDown('K'))
	{
		_isAttacked = true;
		_noneAttacked = false;
	}

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
	angle = getAngle(pos.x, pos.y, _player->pos.x, _player->pos.y);
	speed = 1.1f;

	if (_xCollision == false)pos.x += speed * cosf(angle);
	if (_yCollision == false)pos.y += speed * -sinf(angle);



}

void bigSlime::pixelCollision()
{
	_rc[0] = RectMakeCenter(pos.x + _bigSlime->getFrameWidth() / 2, pos.y, 2, _bigSlime->getFrameHeight());//오른쪽
	_rc[1] = RectMakeCenter(pos.x - _bigSlime->getFrameWidth() / 2, pos.y, 2, _bigSlime->getFrameHeight());//왼쪽
	_rc[2] = RectMakeCenter(pos.x, pos.y - _bigSlime->getFrameHeight() / 2, _bigSlime->getFrameWidth(), 2);//위
	_rc[3] = RectMakeCenter(pos.x, pos.y + _bigSlime->getFrameHeight() / 2, _bigSlime->getFrameWidth(), 2);//아래


	_rc0X = pos.x + _bigSlime->getFrameWidth() / 2;
	_rc0Y = pos.y - _bigSlime->getFrameHeight() / 2;

	_rc1X = pos.x - _bigSlime->getFrameWidth() / 2;
	_rc1Y = pos.y - _bigSlime->getFrameHeight() / 2;

	_rc2Y = pos.y - _bigSlime->getFrameHeight() / 2;
	_rc2X = pos.x - _bigSlime->getFrameWidth() / 2;


	_rc3Y = pos.y + _bigSlime->getFrameHeight() / 2;
	_rc3X = pos.x - _bigSlime->getFrameWidth() / 2;



	for (int j = _rc0Y + 5; j < pos.y + _bigSlime->getFrameHeight() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), pos.x + _bigSlime->getFrameWidth() / 2, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.x = pos.x + _bigSlime->getFrameWidth() / 2 - 53;
			break;
		}


	}
	for (int j = _rc1Y + 5; j < pos.y + _bigSlime->getFrameHeight() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), pos.x - _bigSlime->getFrameWidth() / 2, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.x = pos.x - _bigSlime->getFrameWidth() / 2 + 53;
			break;
		}

	}
	for (int j = _rc2X + 5; j < pos.x + _bigSlime->getFrameWidth() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), j, pos.y + _bigSlime->getFrameHeight() / 2);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.y = pos.y + _bigSlime->getFrameWidth() / 2 - 53;
			break;
		}

	}
	for (int j = _rc2X + 5; j < pos.x + _bigSlime->getFrameWidth() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), j, pos.y - _bigSlime->getFrameHeight() / 2);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.y = pos.y - _bigSlime->getFrameWidth() / 2 + 53;
			break;
		}

	}
}
