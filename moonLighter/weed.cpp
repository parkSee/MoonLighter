#include "stdafx.h"
#include "weed.h"


HRESULT weed::init(string _objName, tagFloat _pos)
{

	gameObject::init(_objName, _pos);
	_weed = IMAGEMANAGER->findImage("잡초");
	_hp = new progressBar;
	_hp->init("빨간체력바", "체력껍데기", pos.x, pos.y, 73, 8);
	_hp->setGauge(200, 200);
	_currentHp = 200;
	_attackedWeed[0] = IMAGEMANAGER->findImage("잡초빨강");
	_attackedWeed[1] = IMAGEMANAGER->findImage("잡초하양");
	_weedFrameX = _weedFrameY = _count = _attackedCount = 0;
	rc = RectMakeCenter(pos.x, pos.y, _weed->getFrameWidth(), _weed->getFrameHeight());

	_noneAttacked = true;//공격안받았을때
	_isAttacked = false; // 공격받았다는 신호
	_isAttacked2 = false;
	_xCollision = false;
	_yCollision = false;



	return S_OK;
}

void weed::release()
{
	_hp->release();
	SAFE_DELETE(_hp);
}

void weed::update()
{
	

	_count++;
	imgRectMake();
	weedFrame();
	move();
	pixelCollision();
	hp();
	_hp->update();
	

	
	

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		//_isDead = true;
		EFFECTMANAGER->play("뿅뿅", pos.x + 7, pos.y + 20);
		
	}




}

void weed::render()
{
	//Rectangle(getMemDC(), rc);
	RECT cam = CAMERAMANAGER->getRenderRc();

	if (_noneAttacked)_weed->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _weedFrameX, _weedFrameY);

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
		
		_attackedWeed[1]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _weedFrameX, _weedFrameY);
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

		
		_attackedWeed[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _weedFrameX, _weedFrameY);
	}
	if (KEYMANAGER->isStayKeyDown('P'))
	{
		_isAttacked = true;
		_noneAttacked = false;
		_currentHp-= 50;
	}

	Rectangle(getMemDC(), _rc[0]);
	Rectangle(getMemDC(), _rc[1]);
	Rectangle(getMemDC(), _rc[2]);
	Rectangle(getMemDC(), _rc[3]);

	char str[128];
	sprintf_s(str, "%d", _xCollision);
	TextOut(getMemDC(), 100, 200, str, strlen(str));

	
	_hp->render();
}



void weed::imgRectMake()
{
	rc = RectMakeCenter(pos.x, pos.y, _weed->getFrameWidth(), _weed->getFrameHeight());
}

void weed::hp()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	_hp->setX((pos.x - IMAGEMANAGER->findImage("잡초")->getFrameWidth() / 2) - cam.left);
	_hp->setY((pos.y - 50) - cam.top);
	_hp->setGauge(_currentHp, 200);
}

void weed::weedFrame()
{
	if (_count % 7 == 0)
	{
		_weed->setFrameX(_weedFrameX);
		_weed->setFrameY(0);
		_weedFrameX++;


		if (_weedFrameX > IMAGEMANAGER->findImage("잡초")->getMaxFrameX())
		{
			_weedFrameX = 0;
		}

	}
}

void weed::move()
{
	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	angle = getAngle(pos.x, pos.y, _player->pos.x, _player->pos.y);
	speed = 0.7f;
	if (_xCollision == false)pos.x += speed * cosf(angle);
	if (_yCollision == false)pos.y += speed * -sinf(angle);

	if (_isAttacked)
	{
		pos.x += 5 * cosf(PI - angle);
		pos.y += 5 * sinf(PI - angle);
	}

}

void weed::pixelCollision()
{
	_rc[0] = RectMakeCenter(pos.x + _weed->getFrameWidth() / 2, pos.y, 2, _weed->getFrameHeight());//오른쪽
	_rc[1] = RectMakeCenter(pos.x - _weed->getFrameWidth() / 2, pos.y, 2, _weed->getFrameHeight());//왼쪽
	_rc[2] = RectMakeCenter(pos.x, pos.y - _weed->getFrameHeight() / 2, _weed->getFrameWidth(), 2);//위
	_rc[3] = RectMakeCenter(pos.x, pos.y + _weed->getFrameHeight() / 2, _weed->getFrameWidth(), 2);//아래


	_rc0X = pos.x + _weed->getFrameWidth() / 2;
	_rc0Y = pos.y - _weed->getFrameHeight() / 2;

	_rc1X = pos.x - _weed->getFrameWidth() / 2;
	_rc1Y = pos.y - _weed->getFrameHeight() / 2;

	_rc2Y = pos.y - _weed->getFrameHeight() / 2;
	_rc2X = pos.x - _weed->getFrameWidth() / 2;


	_rc3Y = pos.y + _weed->getFrameHeight() / 2;
	_rc3X = pos.x - _weed->getFrameWidth() / 2;



	for (int j = _rc0Y + 5; j < pos.y + _weed->getFrameHeight() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), pos.x + _weed->getFrameWidth() / 2, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.x = pos.x + _weed->getFrameWidth() / 2 - 36;
			break;
		}


	}
	for (int j = _rc1Y + 5; j < pos.y + _weed->getFrameHeight() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), pos.x - _weed->getFrameWidth() / 2, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.x = pos.x - _weed->getFrameWidth() / 2 + 36;
			break;
		}

	}
	for (int j = _rc2X + 5; j < pos.x + _weed->getFrameWidth() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), j, pos.y + _weed->getFrameHeight() / 2);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.y = pos.y + _weed->getFrameWidth() / 2 - 36;
			break;
		}

	}
	for (int j = _rc2X + 5; j < pos.x + _weed->getFrameWidth() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), j, pos.y - _weed->getFrameHeight() / 2);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.y = pos.y - _weed->getFrameWidth() / 2 + 36;
			break;
		}

	}

}

