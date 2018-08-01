#include "stdafx.h"
#include "boss.h"
#include"player.h"

HRESULT boss::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);

	_boss[0] = IMAGEMANAGER->findImage("보스정면왼쪽");
	_attackedBoss[0] = IMAGEMANAGER->findImage("보스정면왼쪽빨강");
	_attackedBoss[1] = IMAGEMANAGER->findImage("보스정면왼쪽하양");
	_boss[1] = IMAGEMANAGER->findImage("보스정면오른쪽");
	_attackedBoss[2] = IMAGEMANAGER->findImage("보스정면오른쪽빨강");
	_attackedBoss[3] = IMAGEMANAGER->findImage("보스정면오른쪽하양");
	_boss[2] = IMAGEMANAGER->findImage("보스뒤오른쪽");
	_attackedBoss[4] = IMAGEMANAGER->findImage("보스뒤오른쪽빨강");
	_attackedBoss[5] = IMAGEMANAGER->findImage("보스뒤오른쪽하양");
	_boss[3] = IMAGEMANAGER->findImage("보스뒤왼쪽");
	_attackedBoss[6] = IMAGEMANAGER->findImage("보스뒤왼쪽빨강");
	_attackedBoss[7] = IMAGEMANAGER->findImage("보스뒤왼쪽하양");
	_boss[4] = IMAGEMANAGER->findImage("보스생성");

	

	EFFECTMANAGER->addEffect("보스공격이펙트다운오른쪽2", "보스공격이펙트다운오른쪽", 0.2f, 20);
	EFFECTMANAGER->addEffect("보스공격이펙트다운왼쪽2", "보스공격이펙트다운왼쪽", 0.2f, 1);
	EFFECTMANAGER->addEffect("보스공격이펙트업왼쪽2", "보스공격이펙트업왼쪽", 0.2f, 20);
	EFFECTMANAGER->addEffect("보스공격이펙트업오른쪽2", "보스공격이펙트업오른쪽", 0.2f, 20);
	EFFECTMANAGER->addEffect("보스이펙트오른쪽2", "보스이펙트오른쪽", 0.2f, 20);
	EFFECTMANAGER->addEffect("보스이펙트왼쪽2", "보스이펙트왼쪽", 0.2f, 20);

	_hp = new progressBar;
	_hp->init("빨간체력바", "체력껍데기", pos.x, pos.y, 73, 8);
	_hp->setGauge(200, 200);
	_currentHp = 200;



	 rc = RectMakeCenter(pos.x, pos.y, _boss[0]->getFrameWidth(), _boss[0]->getFrameHeight());

	_count = _attackedCount = _tempCurrent = _dmgCount =_dmgHp= 0;



	for (int i = 0; i < 4; i++)
	{
		_attackCountBool[i] = false;
		_attackCount[i] = 0;
		_currentX[i] = 0;
		_currentY[i] = 0;
	}
	_currentX[4] = 0;
	_currentY[4] = 0;
	_leftUp = false;
	_rightUp = false;
	_leftDown = false;
	_rightDown = false;
	_startAttack = false;
	_isAttack = false;
	_isAttacked = false;
	_isAttacked2 = false;
	_noneAttacked = true;
	_isDead = false;
	_damaaged = false;
	_start = false;
	_playing = false;

	return S_OK;
}

void boss::release()
{
	_hp->release();
	SAFE_DELETE(_hp);
}

void boss::update()
{
	_count++;
	
	
	if (!_startAttack)move();
	imgRectMake();
	bossFrame();
	bossAttack();
	this->damagged();
	//pixelCollision();
	hp();
	_hp->update();

	_detectRect = RectMakeCenter(pos.x, pos.y, 500, 500);

	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	RECT tempRc;

	if (IntersectRect(&tempRc, &((player*)_player)->getRcBody(), &_detectRect))
	{
		_start = true;

	}
	
}

void boss::render()
{
	
	RECT cam = CAMERAMANAGER->getRenderRc();

	//RectangleCam(getMemDC(), rc, cam);

	//_boss[5]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top,_currentX[5],_currentY[5]);

	//if (_count % 3 == 0)
	//{
	//	_currentX[5]++;
	//	if (_currentX[5] > _boss[5]->getMaxFrameX())
	//	{
	//		_currentX[5] = 0;
	//	}
	//}
	_boss[4]->frameRender(getMemDC(), rc.left - cam.left - 30, rc.top - cam.top, _currentX[4], _currentY[4]);

	if (_start)
	{
		if (_count % 3 == 0)
		{
			_currentX[4]++;
			if (_currentX[4] > _boss[4]->getMaxFrameX())
			{
				_currentX[4] = 0;
				_playing = true;
			}
		}
	}
	
	if (_playing)
	{
		_currentX[4] = 0;
		if (tempX > 0 && tempY > 0 && tempX*tempX > tempY*tempY)
		{
			_rightUp = false; _leftUp = false; _rightDown = true; _leftDown = false;
			if (_noneAttacked)_boss[1]->frameRender(getMemDC(), rc.left - 30 - cam.left, rc.top + 5 - cam.top, _currentX[1], _currentY[1]);//오른쪽

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

				_attackedBoss[3]->frameRender(getMemDC(), rc.left - cam.left - 30, rc.top + 5 - cam.top, _currentX[1], _currentY[1]);
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


				_attackedBoss[2]->frameRender(getMemDC(), rc.left - cam.left - 30, rc.top + 5 - cam.top, _currentX[1], _currentY[1]);
			}
		}
		if (tempX > 0 && tempY< 0 && tempX*tempX > tempY*tempY)
		{
			_rightUp = true; _leftUp = false; _rightDown = false; _leftDown = false;
			if (_noneAttacked)_boss[2]->frameRender(getMemDC(), rc.left - 30 - cam.left, rc.top + 5 - cam.top, _currentX[2], _currentY[2]);//오른쪽

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

				_attackedBoss[5]->frameRender(getMemDC(), rc.left - 30 - cam.left, rc.top + 5 - cam.top, _currentX[2], _currentY[2]);
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


				_attackedBoss[4]->frameRender(getMemDC(), rc.left - 30 - cam.left, rc.top + 5 - cam.top, _currentX[2], _currentY[2]);
			}
		}
		if (tempX < 0 && tempY > 0 && tempX*tempX > tempY*tempY)
		{
			_rightUp = false; _leftUp = false; _rightDown = false; _leftDown = true;
			if (_noneAttacked)_boss[0]->frameRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top, _currentX[0], _currentY[0]);//왼쪽

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

				_attackedBoss[1]->frameRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top, _currentX[0], _currentY[0]);
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


				_attackedBoss[0]->frameRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top, _currentX[0], _currentY[0]);
			}
		}
		if (tempX < 0 && tempY < 0 && tempX*tempX > tempY*tempY)
		{
			_rightUp = false; _leftUp = true; _rightDown = false; _leftDown = false;
			if (_noneAttacked)_boss[3]->frameRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top, _currentX[3], _currentY[3]);//왼쪽

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

				_attackedBoss[7]->frameRender(getMemDC(), rc.left - cam.left - 51, rc.top + 5 - cam.top, _currentX[3], _currentY[3]);
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


				_attackedBoss[6]->frameRender(getMemDC(), rc.left - cam.left - 51, rc.top + 5 - cam.top, _currentX[3], _currentY[3]);
			}
		}
		if (tempX > 0 && tempY > 0 && tempY*tempY > tempX*tempX)
		{
			_rightUp = false; _leftUp = false; _rightDown = true; _leftDown = false;

			if (_noneAttacked)_boss[1]->frameRender(getMemDC(), rc.left - cam.left - 30, rc.top - cam.top + 5, _currentX[1], _currentY[1]);//아래

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

				_attackedBoss[3]->frameRender(getMemDC(), rc.left - cam.left - 30, rc.top - cam.top + 5, _currentX[1], _currentY[1]);
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


				_attackedBoss[2]->frameRender(getMemDC(), rc.left - cam.left - 30, rc.top - cam.top + 5, _currentX[1], _currentY[1]);

			}



		}
		if (tempX < 0 && tempY >0 && tempY*tempY > tempX*tempX)
		{
			_rightUp = false; _leftUp = false; _rightDown = false; _leftDown = true;

			if (_noneAttacked)_boss[0]->frameRender(getMemDC(), rc.left - cam.left - 50, rc.top - cam.top + 5, _currentX[0], _currentY[0]);//아래

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

				_attackedBoss[1]->frameRender(getMemDC(), rc.left - cam.left - 50, rc.top - cam.top + 5, _currentX[0], _currentY[0]);
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


				_attackedBoss[0]->frameRender(getMemDC(), rc.left - cam.left - 50, rc.top - cam.top + 5, _currentX[0], _currentY[0]);
			}
		}
		if (tempX > 0 && tempY <0 && tempY*tempY > tempX*tempX)
		{
			_rightUp = true; _leftUp = false; _rightDown = false; _leftDown = false;
			if (_noneAttacked)_boss[2]->frameRender(getMemDC(), rc.left - cam.left - 30, rc.top + 5 - cam.top, _currentX[2], _currentY[2]);//위

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

				_attackedBoss[5]->frameRender(getMemDC(), rc.left - cam.left - 30, rc.top + 5 - cam.top, _currentX[2], _currentY[2]);
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


				_attackedBoss[4]->frameRender(getMemDC(), rc.left - cam.left - 30, rc.top + 5 - cam.top, _currentX[2], _currentY[2]);
			}
		}
		if (tempX < 0 && tempY <0 && tempY*tempY > tempX*tempX)
		{
			_rightUp = true; _leftUp = false; _rightDown = false; _leftDown = false;
			if (_noneAttacked)_boss[3]->frameRender(getMemDC(), rc.left - cam.left - 50, rc.top + 5 - cam.top, _currentX[3], _currentY[3]);//위

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

				_attackedBoss[7]->frameRender(getMemDC(), rc.left - cam.left - 50, rc.top + 5 - cam.top, _currentX[3], _currentY[3]);
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


				_attackedBoss[6]->frameRender(getMemDC(), rc.left - cam.left - 50, rc.top + 5 - cam.top, _currentX[3], _currentY[3]);
			}
		}
	//	//char str[128];
	//	//sprintf_s(str, "leftDown ;%d ,LeftUp : %d , RightDown : %d, Right Up : %d", _leftDown, _leftUp, _rightDown, _rightUp);
	//	//TextOut(getMemDC(), 300, 300, str, strlen(str));

	//	//RectangleCam(getMemDC(), _rc[0], cam);
	//	//RectangleCam(getMemDC(), _rc[1], cam);
	//	//RectangleCam(getMemDC(), _rc[2], cam);
	//	//RectangleCam(getMemDC(), _rc[3], cam);

	}
	if (!_attackCountBool[0])
	{
		tempX2 = pos.x;
		tempY2 = pos.y;
	}

	if (_currentX[0] == 10)
	{
		//EFFECTMANAGER->play("보스공격이펙트다운왼쪽2", pos.x - cam.left, pos.y - cam.top);
		EFFECTMANAGER->play("보스공격이펙트다운왼쪽2", pos.x-80, pos.y+50);
	}
	//_attackedBoss[0]->frameRender(getMemDC(), rc.left - cam.left - 50, rc.top - cam.top + 5, _currentX[0], _currentY[0]);
	if (_currentX[1] == 10)
	{
		//EFFECTMANAGER->play("보스공격이펙트다운왼쪽2", pos.x - cam.left, pos.y - cam.top);
		EFFECTMANAGER->play("보스공격이펙트다운오른쪽2", pos.x , pos.y + 50);
	}
	if (_currentX[2] == 10)
	{
		//EFFECTMANAGER->play("보스공격이펙트다운왼쪽2", pos.x - cam.left, pos.y - cam.top);
		EFFECTMANAGER->play("보스공격이펙트업오른쪽2", pos.x +30, pos.y +10);
		
	}
	if (_currentX[3] == 10)
	{
		//EFFECTMANAGER->play("보스공격이펙트다운왼쪽2", pos.x - cam.left, pos.y - cam.top);
		EFFECTMANAGER->play("보스공격이펙트업왼쪽2", pos.x - 120, pos.y + 15);
	}
}

void boss::imgRectMake()
{
	 rc = RectMakeCenter(pos.x, pos.y, _boss[0]->getFrameWidth(), _boss[0]->getFrameHeight());
}

int boss::damagged()
{
	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	RECT tempRc;

	if (IntersectRect(&tempRc, &((player*)_player)->getRcSword(), &rc))
	{
		_damaaged = true;
		

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
		pos.x += 10 * cosf(PI - angle);
		pos.y += 10 * sinf(PI - angle);
	}

	if (_dmgCount > 15)
	{
		_dmgCount = 0;
		_dmgHp = 10;
	}


	return _dmgHp;
}

void boss::hp()
{
}

void boss::bossFrame()
{
	for (int i = 0; i < 4; i++)
	{
		if (!_attackCountBool[i])
		{
			if (_count % 5 == 0)
			{

				_boss[i]->setFrameX(_currentX[i]);
				_currentX[i]++;

				if (_currentX[i] > 7)
				{
					_currentX[i] = 0;
				}

			}
		}
		if (_attackCountBool[i])
		{
			_attackCount[i]++;
			if (_attackCount[i] % 3 == 0)
			{
				_boss[i]->setFrameX(_currentX[i]);
				_currentX[i]++;

				if (_currentX[i] >_boss[i]->getMaxFrameX())
				{
					_currentX[i] = 0;
					_attackCount[i] = 0;
					_attackCountBool[i] = false;
					_startAttack = false;
					_isAttack = false;
				}

			}
		}
	}

}

void boss::bossAttack()
{
	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");

	distance = getDistance(pos.x-40 , pos.y+10, _player->pos.x, _player->pos.y);

	if (distance < 150)
	{
		_startAttack = true;
	}
	else
	{
		_startAttack = false;
	}



	if (_startAttack && _isAttack == false)
	{
		_isAttack = true;
		if (_leftDown)
		{
			_attackCountBool[0] = true;
			_currentX[0] = 9;
			
			
		}
		if (_rightDown)
		{
			_attackCountBool[1] = true;
			_currentX[1] = 9;
		}
		if (_rightUp)
		{
			_attackCountBool[2] = true;
			_currentX[2] = 9;
		}

		if (_leftUp)
		{
			_attackCountBool[3] = true;
			_currentX[3] = 9;
		}
	}

}

void boss::move()
{
	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");
	angle = getAngle(pos.x, pos.y, _player->pos.x, _player->pos.y);
	speed = 0.5f;
	distance = getDistance(pos.x, pos.y, _player->pos.x, _player->pos.y);

	pos.x += speed * cosf(angle);
	pos.y += speed * -sinf(angle);
	tempX = speed * cosf(angle);
	tempY = speed * -sinf(angle);

	if (_isAttacked)
	{
		pos.x += 5 * cosf(PI - angle);
		pos.y += 5 * sinf(PI - angle);
	}
}

void boss::pixelCollision()
{

	RECT cam = CAMERAMANAGER->getRenderRc();
	
	_rc[0] = RectMakeCenter(pos.x + _boss[0]->getFrameWidth() / 2, pos.y, 2, _boss[0]->getFrameHeight());//오른쪽
	_rc[1] = RectMakeCenter(pos.x - _boss[0]->getFrameWidth() / 2, pos.y, 2, _boss[0]->getFrameHeight());//왼쪽
	_rc[2] = RectMakeCenter(pos.x, pos.y - _boss[0]->getFrameHeight() / 2, _boss[0]->getFrameWidth(), 2);//위
	_rc[3] = RectMakeCenter(pos.x, pos.y + _boss[0]->getFrameHeight() / 2, _boss[0]->getFrameWidth(), 2);//아래


	_rc0X = pos.x + _boss[0]->getFrameWidth() / 2;
	_rc0Y = pos.y - _boss[0]->getFrameHeight() / 2;

	_rc1X = pos.x - _boss[0]->getFrameWidth() / 2;
	_rc1Y = pos.y - _boss[0]->getFrameHeight() / 2;

	_rc2Y = pos.y - _boss[0]->getFrameHeight() / 2;
	_rc2X = pos.x - _boss[0]->getFrameWidth() / 2;


	_rc3Y = pos.y + _boss[0]->getFrameHeight() / 2;
	_rc3X = pos.x - _boss[0]->getFrameWidth() / 2;




	for (int j = _rc0Y + 5; j < pos.y + _boss[0]->getFrameHeight() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), pos.x + _boss[0]->getFrameWidth() / 2, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.x = pos.x + _boss[0]->getFrameWidth() / 2 - 129;
			break;
		}


	}
	for (int j = _rc1Y + 5; j < pos.y + _boss[0]->getFrameHeight() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), pos.x - _boss[0]->getFrameWidth() / 2, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.x = pos.x - _boss[0]->getFrameWidth() / 2 + 129;
			break;
		}

	}
	for (int j = _rc2X + 5; j < pos.x + _boss[0]->getFrameWidth() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), j, pos.y + _boss[0]->getFrameHeight() / 2);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.y = pos.y + _boss[0]->getFrameWidth() / 2 - 129;
			break;
		}

	}
	for (int j = _rc2X + 5; j < pos.x + _boss[0]->getFrameWidth() / 2 - 5; j++)
	{

		COLORREF color = GetPixel(_pixelImg->getMemDC(), j, pos.y - _boss[0]->getFrameHeight() / 2);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (r == 255 && g == 0 && b == 0)
		{
			pos.y = pos.y - _boss[0]->getFrameWidth() / 2 + 129;
			break;
		}

	}

}
