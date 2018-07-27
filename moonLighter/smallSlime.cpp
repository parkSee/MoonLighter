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

void smallSlime::move()
{
	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	angle = getAngle(pos.x, pos.y, _player->pos.x, _player->pos.y);
	speed = 1.2f;

	pos.x += speed * cosf(angle);
	pos.y += speed * -sinf(angle);
}


