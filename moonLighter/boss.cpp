#include "stdafx.h"
#include "boss.h"

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

	
	
	
	
	
	
	
	
	
	
	
	

	_boss[8] = IMAGEMANAGER->findImage("보스생성");





	

	EFFECTMANAGER->addEffect("보스공격이펙트다운오른쪽2", "보스공격이펙트다운오른쪽", 0.2f, 20);
	EFFECTMANAGER->addEffect("보스공격이펙트다운왼쪽2", "보스공격이펙트다운왼쪽", 0.2f, 20);
	EFFECTMANAGER->addEffect("보스공격이펙트업왼쪽2", "보스공격이펙트업왼쪽", 0.2f, 20);
	EFFECTMANAGER->addEffect("보스공격이펙트업오른쪽2", "보스공격이펙트업오른쪽", 0.2f, 20);
	EFFECTMANAGER->addEffect("보스이펙트오른쪽2", "보스이펙트오른쪽", 0.2f, 20);
	EFFECTMANAGER->addEffect("보스이펙트왼쪽2", "보스이펙트왼쪽", 0.2f, 20);

	_hp = new progressBar;
	_hp->init("빨간체력바", "체력껍데기", pos.x, pos.y, 73, 8);
	_hp->setGauge(200, 200);
	_currentHp = 200;



	 rc = RectMakeCenter(pos.x, pos.y, _boss[0]->getFrameWidth(), _boss[0]->getFrameHeight());

	_count = _attackedCount = _tempCurrent = 0;



	for (int i = 0; i < 4; i++)
	{
		_attackCountBool[i] = false;
		_attackCount[i] = 0;
		_currentX[i] = 0;
		_currentY[i] = 0;
	}
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
	hp();
	_hp->update();

	
}

void boss::render()
{
	
	RECT cam = CAMERAMANAGER->getRenderRc();
	if (tempX > 0 && tempY > 0 && tempX*tempX > tempY*tempY)
	{
		_rightUp = false; _leftUp = false; _rightDown = true; _leftDown = false;
		if (_noneAttacked)_boss[1]->frameRender(getMemDC(), rc.left -30 - cam.left, rc.top +5 - cam.top, _currentX[1], _currentY[1]);//오른쪽

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

			_attackedBoss[3]->frameRender(getMemDC(), rc.left - cam.left + 6, rc.top - 9 - cam.top, _currentX[1], _currentY[1]);
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


			_attackedBoss[2]->frameRender(getMemDC(), rc.left - cam.left + 6, rc.top - 9 - cam.top, _currentX[1], _currentY[1]);
		}
	}
	if (tempX > 0 && tempY< 0 && tempX*tempX > tempY*tempY)
	{
		_rightUp = true; _leftUp = false; _rightDown = false; _leftDown = false;
		if (_noneAttacked)_boss[2]->frameRender(getMemDC(), rc.left -30 - cam.left, rc.top + 5 - cam.top, _currentX[2], _currentY[2]);//오른쪽

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

			_attackedBoss[5]->frameRender(getMemDC(), rc.left - cam.left + 6, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);
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


			_attackedBoss[4]->frameRender(getMemDC(), rc.left - cam.left + 6, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);
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

			_attackedBoss[1]->frameRender(getMemDC(), rc.left - cam.left - 51, rc.top + 5 - cam.top, _currentX[0], _currentY[0]);
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


			_attackedBoss[0]->frameRender(getMemDC(), rc.left - cam.left - 51, rc.top + 5 - cam.top, _currentX[0], _currentY[0]);
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

		if (_noneAttacked)_boss[1]->frameRender(getMemDC(), rc.left - cam.left -30 , rc.top - cam.top +5, _currentX[1], _currentY[1]);//아래

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

			_attackedBoss[3]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX[1], _currentY[1]);
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


			_attackedBoss[2]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX[1], _currentY[1]);

		}



	}
	if (tempX < 0 && tempY >0 && tempY*tempY > tempX*tempX)
	{
		_rightUp = false; _leftUp = false; _rightDown = false; _leftDown = true;

		if (_noneAttacked)_boss[0]->frameRender(getMemDC(), rc.left - cam.left -50, rc.top - cam.top +5, _currentX[0], _currentY[0]);//아래

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

			_attackedBoss[1]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX[0], _currentY[0]);
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


			_attackedBoss[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX[0], _currentY[0]);
		}
	}
	if (tempX > 0 && tempY <0 && tempY*tempY > tempX*tempX)
	{
		_rightUp = true; _leftUp = false; _rightDown = false; _leftDown = false;
		if (_noneAttacked)_boss[2]->frameRender(getMemDC(), rc.left - cam.left -30, rc.top + 5 - cam.top, _currentX[2], _currentY[2]);//위

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

			_attackedBoss[5]->frameRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);
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


			_attackedBoss[4]->frameRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);
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

			_attackedBoss[7]->frameRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, _currentX[3], _currentY[3]);
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


			_attackedBoss[6]->frameRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, _currentX[3], _currentY[3]);
		}
	}
	
	
}

void boss::imgRectMake()
{
	 rc = RectMakeCenter(pos.x, pos.y, _boss[0]->getFrameWidth(), _boss[0]->getFrameHeight());
}

void boss::damagged()
{
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

				if (_currentX[i] > 8)
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

	distance = getDistance(pos.x, pos.y, _player->pos.x, _player->pos.y);

	if (distance < 100)
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
}
