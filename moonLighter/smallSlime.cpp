#include "stdafx.h"
#include "smallSlime.h"
#include"player.h"

HRESULT smallSlime::init(string _objName, tagFloat _pos)
{

	gameObject::init(_objName, _pos);
	_smallSlime = IMAGEMANAGER->findImage("작은슬라임");
	_smallSlimeShadow = IMAGEMANAGER->findImage("작은슬라임그림자");
	_attackedSmallSlime[0] = IMAGEMANAGER->findImage("작은슬라임빨강");
	_attackedSmallSlimeShadow[0] = IMAGEMANAGER->findImage("작은슬라임빨강그림자");
	_attackedSmallSlime[1] = IMAGEMANAGER->findImage("작은슬라임하양");
	_attackedSmallSlimeShadow[1] = IMAGEMANAGER->findImage("작은슬라임하양그림자");
	_dmgFontTen = IMAGEMANAGER->findImage("대미지폰트");
	_dmgFontOne = IMAGEMANAGER->findImage("대미지폰트");
	_hp = new progressBar;
	_hp->init("빨간체력바", "체력껍데기", pos.x, pos.y, 73, 8);
	_hp->setGauge(200, 200);
	_currentHp = 200;
	_count = _currentX = _attackedCount = _currentY = _dmgCount = 0;
	rc = RectMakeCenter(pos.x, pos.y, _smallSlime->getFrameWidth(), _smallSlime->getFrameHeight());
	_rc2 = RectMakeCenter(pos.x, pos.y, _smallSlime->getFrameWidth(), _smallSlime->getFrameHeight());
	_dmgFontRc[0] = RectMakeCenter(pos.x - 30, pos.y, _dmgFontTen->getFrameWidth(), _dmgFontTen->getFrameHeight());
	_dmgFontRc[1] = RectMakeCenter(pos.x, pos.y, _dmgFontTen->getFrameWidth(), _dmgFontTen->getFrameHeight());

	 _dmgImgY =-70;
	 _dmgImgCount=0;
	 _alpha = 0;
	 _dmgImgCountBool=false;

	 EFFECTMANAGER->addEffect("뿅뿅", "뿅", 0.2f, 20);

	_noneAttacked = true;//공격안받았을때
	_isAttacked = false; // 공격받았다는 신호
	_isAttacked2 = false;
	_xCollision = false;
	_yCollision = false;
	_damaaged = false;

	_deadEffectBool = false;
	_deadBool = false;
	_dmg = false;
	_isAttacked3 = false;

	return S_OK;
}

void smallSlime::release()
{
	_hp->release();
	SAFE_DELETE(_hp);
}

void smallSlime::update()
{
	_count++;
	imgRectMake();
	smallSlimeFrame();
	if (_currentHp >0)move();
	pixelCollision();
	hp();
	this->damagged();
	_hp->update();
	if (_deadBool)dead();
	

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
	_hp->render();
	//RectangleCam(getMemDC(), rc, cam);

	if (_currentHp > 0)
	{
		if (_noneAttacked)
		{
			_smallSlime->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY);
			_smallSlimeShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY,80);
		}

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

			_attackedSmallSlime[1]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY);
			_attackedSmallSlimeShadow[1]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY,80);
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


			_attackedSmallSlime[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY);
			_attackedSmallSlimeShadow[0]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY,80);
		}
	}
	else
	{
		if (_noneAttacked)
		{
			_smallSlime->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY);
			_smallSlimeShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY,80);

		}

		if (_isAttacked3)
		{
			_attackedCount++;
			if (_attackedCount > 10)
			{
				_isAttacked2 = false;
				_isAttacked = false;
				_isAttacked3 = false;
				_attackedCount = 0;
				_deadBool = true;


			}
			_attackedSmallSlime[1]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 230);
			_attackedSmallSlimeShadow[1]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top,_currentX,_currentY, 80);

		}

		if (_isAttacked2)
		{
			_attackedCount++;
			if (_attackedCount > 5)
			{
				_isAttacked2 = false;
				_isAttacked = false;
				_isAttacked3 = true;
				_attackedCount = 0;


			}

			_attackedSmallSlime[1]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY);
			_attackedSmallSlimeShadow[1]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY,80);
		}
		if (_isAttacked)
		{
			_attackedCount++;
			if (_attackedCount > 5)
			{
				_isAttacked = false;
				_isAttacked2 = true;
				_attackedCount = 0;
			}


			_attackedSmallSlime[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY);
			_attackedSmallSlimeShadow[0]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY,80);
		}
	}


	if (KEYMANAGER->isOnceKeyDown('L'))
	{
		_isAttacked = true;
		_noneAttacked = false;
	}

	if (0 < _dmgImgCount && _dmgImgCount < 30)
	{
		_dmgImgCount++;
		_dmgFontTen->frameRender(getMemDC(), _dmgFontRc[0].left - cam.left, _dmgFontRc[0].top - cam.top, 8, 0);
		_dmgFontOne->frameRender(getMemDC(), _dmgFontRc[1].left - cam.left, _dmgFontRc[1].top - cam.top, 6, 0);
		_dmgImgY -= 0.5f;
	}



	if (_dmgImgCount >= 30)
	{
		_dmgImgCount = 0;
		_dmgImgY = -70;
	}
	
}

void smallSlime::imgRectMake()
{
	rc = RectMakeCenter(pos.x, pos.y, _smallSlime->getFrameWidth(), _smallSlime->getFrameHeight());
	_rc2 = RectMakeCenter(pos.x, pos.y, _smallSlime->getFrameWidth(), _smallSlime->getFrameHeight());
	_dmgFontRc[0] = RectMakeCenter(pos.x - 10, pos.y + _dmgImgY, _dmgFontTen->getFrameWidth(), _dmgFontTen->getFrameHeight());
	_dmgFontRc[1] = RectMakeCenter(pos.x + 20, pos.y + _dmgImgY, _dmgFontTen->getFrameWidth(), _dmgFontTen->getFrameHeight());
	_collisionRc = RectMakeCenter(pos.x, pos.y, 20, 20);
}

void smallSlime::hp()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	_hp->setGauge(_currentHp, 200);
	_hp->setX((pos.x - 2 * IMAGEMANAGER->findImage("작은슬라임")->getFrameWidth() / 3) - cam.left);
	_hp->setY((pos.y - 50) - cam.top);
}

void smallSlime::damagged()
{
	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	RECT tempRc;

	if (IntersectRect(&tempRc, &((player*)_player)->getRcSword(), &rc))
	{
		_damaaged = true;

	}
	if (IntersectRect(&tempRc, &((player*)_player)->getRcSword(), &_rc2) && _dmg == false)
	{
		_damaaged = true;
		_dmg = true;
		_currentHp -= 120;
		SOUNDMANAGER->play("slime_hit", 0.5f);
	}

	if (_damaaged)
	{
		_dmgImgCount++;
		_dmgCount++;
		_damaaged = false;
		_isAttacked = true;
		_noneAttacked = false;



	}

	if (0 < _dmgCount && _dmgCount <= 15)
	{
		_dmgCount++;
		pos.x += 7 * cosf(PI - angle);
		pos.y += 7 * sinf(PI - angle);
	}

	if (_dmgCount > 15)
	{

		_dmg = false;
		_dmgCount = 0;
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

void smallSlime::dead()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	if (_deadBool && _deadEffectBool == false)
	{
		EFFECTMANAGER->play("뿅뿅", pos.x + 7, pos.y + 20);
		SOUNDMANAGER->play("enemy_death", 1.f);
		_deadEffectBool = true;
		OBJECTMANAGER->getItemManager()->appear(itemType::LIQUIDITEM, tagFloat(pos.x, pos.y));
	}
	setIsLive(false);
}







