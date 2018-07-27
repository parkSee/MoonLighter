#include "stdafx.h"
#include "bigSlime.h"


HRESULT bigSlime::init(string _objName, tagFloat _pos)
{

	gameObject::init(_objName, _pos);
	_bigSlime = IMAGEMANAGER->findImage("ū������");
	_attackedBigSlime[0] = IMAGEMANAGER->findImage("ū�����ӻ���");
	_attackedBigSlime[1] = IMAGEMANAGER->findImage("ū�������Ͼ�");
	//EFFECTMANAGER->addEffect("�л�",)
	rc = RectMakeCenter(pos.x, pos.y, _bigSlime->getFrameWidth(), _bigSlime->getFrameHeight());
	_alpha = 255;
	_count = _currentX = _attackedCount = _currentY = 0;
	_slimeBool = false;
	_noneAttacked = true;//���ݾȹ޾�����
	_isAttacked = false; // ���ݹ޾Ҵٴ� ��ȣ
	_isAttacked2 = false;


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
		EFFECTMANAGER->play("�л�", pos.x + 5, pos.y + 20);
	}

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

	pos.x += speed * cosf(angle);
	pos.y += speed * -sinf(angle);



}
