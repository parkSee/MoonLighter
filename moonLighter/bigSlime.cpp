#include "stdafx.h"
#include "bigSlime.h"
#include "player.h"

HRESULT bigSlime::init(string _objName, tagFloat _pos)
{

	gameObject::init(_objName, _pos);
	_bigSlime = IMAGEMANAGER->findImage("큰슬라임");
	_attackedBigSlime[0] = IMAGEMANAGER->findImage("큰슬라임빨강");
	_attackedBigSlime[1] = IMAGEMANAGER->findImage("큰슬라임하양");
	_hp = new progressBar;
	_hp->init("빨간체력바", "체력껍데기", pos.x, pos.y, 73, 8);
	_hp->setGauge(200, 200);
	_currentHp = 200;
	//EFFECTMANAGER->addEffect("뿅뿅",)
	rc = RectMakeCenter(pos.x, pos.y, _bigSlime->getFrameWidth(), _bigSlime->getFrameHeight());
	_rc2 = RectMakeCenter(pos.x, pos.y, _bigSlime->getFrameWidth(), _bigSlime->getFrameHeight());
	_alpha = 255;
	speed = 1.1f;
	_count = _currentX = _attackedCount = _dmgCount=_currentY=_distance= _jellyCount  =0;
	_tempAngleX = RND->getFloat(6.2);
	
	_slimeBool = false;																
	_noneAttacked = true;//공격안받았을때
	_isAttacked = false; // 공격받았다는 신호
	_isAttacked2 = false;
	 _xCollision =false;
	 _yCollision =false;
	 _damaaged = false;
	 _deadEffectBool = false;
	 _deadBool = false;
	 _dmg = false; 
	 _isAttacked3 = false;
	 _jellyAttack = false;
	 _playerMove = true;


	return S_OK;
}

void bigSlime::release()
{
	_hp->release();
	SAFE_DELETE(_hp);
}

void bigSlime::update()
{
	_count++;
	imgRectMake();
	bigSlimeFrame();
	if (_currentHp >0)move();
	hp();
	this->damaged();
	pixelCollision();
	_hp->update();
	if (_deadBool)dead();
	Attack();
	

	if (KEYMANAGER->isOnceKeyDown('B'))
	{
		_slimeBool = true;
		_currentX = 24;
	}

	


	
}

void bigSlime::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	//Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top, rc.right - cam.left, rc.bottom - cam.top);
	//RectangleCam(getMemDC(), rc, cam);
	_hp->render();
	if (_currentHp > 0)
	{
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
	}
	else
	{
		if (_noneAttacked)_bigSlime->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);

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
			_attackedBigSlime[1]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 230);

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

			_attackedBigSlime[1]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY);
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


			_attackedBigSlime[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX, _currentY);
		}
	}

	
	

}

void bigSlime::imgRectMake()
{

	rc = RectMakeCenter(pos.x, pos.y, _bigSlime->getFrameWidth(), _bigSlime->getFrameHeight());
	_rc2 = RectMakeCenter(pos.x, pos.y, _bigSlime->getFrameWidth(), _bigSlime->getFrameHeight());
}

void bigSlime::hp()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	_hp->setGauge(_currentHp, 200);
	_hp->setX((pos.x - IMAGEMANAGER->findImage("큰슬라임")->getFrameWidth() / 3) - cam.left);
	_hp->setY((pos.y - 50) - cam.top);
}

void bigSlime::bigSlimeFrame()
{
	if (_count % 4 == 0)
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
	

	if (_xCollision == false)pos.x += speed * cosf(angle);
	if (_yCollision == false)pos.y += speed * -sinf(angle);

	if (_isAttacked)
	{
		pos.x += 5 * cosf(PI - angle);
		pos.y += 5 * sinf(PI - angle);
	}

}

void bigSlime::damaged()
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

	}

	if (_damaaged)
	{
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

void bigSlime::dead()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	if (_deadBool && _deadEffectBool == false)
	{
		_deadEffectBool = true;
		EFFECTMANAGER->play("뿅뿅", pos.x + 7, pos.y + 20);
	}
	setIsLive(false);
}

void bigSlime::Attack()
{
	
	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");

	_distance = getDistance(pos.x, pos.y, _player->pos.x, _player->pos.y);

	
	if (_distance < 100 && _jellyAttack==false)
	{
		
		_jellyCount++;
		speed = 8.0f;
		if (_distance < 10)
		{
			_slimeBool = true;

			((player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player"))->setPlayerMove(false);
			_playerMove = false;
			pos.x = _player->pos.x;
			pos.y = _player->pos.y;
			_xCollision = true;
			_yCollision = true;
			

		}
	}
	if (_distance < 50 && _slimeBool == false)
	{
		_slimeBool = true;
		_currentX = 24;
	}


	if (_jellyCount > 100 && _jellyCount < 150)
	{
		((player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player"))->setPlayerMove(false);
		_playerMove = false;
		_jellyCount++;
		_jellyAttack = true;
		_player->pos.x += 5 * cosf(_tempAngleX);
		_player->pos.y += 5 * sinf(_tempAngleX);
		speed = 1.1f;
		
	}
	if (_jellyCount == 150)
	{
		((player*)OBJECTMANAGER->findObject(objectType::PLAYER, "player"))->setPlayerMove(true);
		_xCollision = false;
		_yCollision = false;
		_jellyAttack = false;
		_playerMove = true;
		_slimeBool = false;
		_jellyCount = 0;
		_tempAngleX = RND->getFloat(6.2);
		
	}




}
