#include "stdafx.h"
#include "golem.h"

HRESULT golem::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);
	_golem[0] = IMAGEMANAGER->findImage("°ñ·½Á¤¸é");
	_attackedGolem[0] = IMAGEMANAGER->findImage("Á¤¸é¸Â´Â»¡°­");
	_attackedGolem[1] = IMAGEMANAGER->findImage("Á¤¸é¸Â´ÂÇÏ¾ç");
	_golem[1] = IMAGEMANAGER->findImage("°ñ·½¿ÞÂÊ");
	_attackedGolem[2] = IMAGEMANAGER->findImage("¿ÞÂÊ¸Â´Â»¡°­");
	_attackedGolem[3] = IMAGEMANAGER->findImage("¿ÞÂÊ¸Â´ÂÇÏ¾ç");
	_golem[2] = IMAGEMANAGER->findImage("°ñ·½¿À¸¥ÂÊ");
	_attackedGolem[4] = IMAGEMANAGER->findImage("¿À¸¥ÂÊ¸Â´Â»¡°­");
	_attackedGolem[5] = IMAGEMANAGER->findImage("¿À¸¥ÂÊ¸Â´ÂÇÏ¾ç");
	_golem[3] = IMAGEMANAGER->findImage("°ñ·½µÚÂÊ");
	_attackedGolem[6] = IMAGEMANAGER->findImage("µÚÂÊ¸Â´Â»¡°­");
	_attackedGolem[7] = IMAGEMANAGER->findImage("µÚÂÊ¸Â´ÂÇÏ¾ç");

	EFFECTMANAGER->addEffect("»Ð»Ð", "»Ð", 0.2f, 20);

	_hp = new progressBar;
	_hp->init("»¡°£Ã¼·Â¹Ù", "Ã¼·Â²®µ¥±â", pos.x, pos.y, 73, 8);
	_hp->setGauge(200, 200);
	_currentHp = 200;



	 rc = RectMakeCenter(pos.x, pos.y, _golem[0]->getFrameWidth(), _golem[0]->getFrameHeight());

	_count = _attackedCount = _tempCurrent = 0;



	for (int i = 0; i < 4; i++)
	{
		_attackCountBool[i] = false;
		_attackCount[i] = 0;
		_currentX[i] = 0;
		_currentY[i] = 0;
	}
	_left = false;
	_right = false;
	_up = false;
	_down = false;
	_startAttack = false;
	_isAttack = false;
	_isAttacked = false;
	_isAttacked2 = false;
	_noneAttacked = true;
	_isDead = false;
	return S_OK;
}

void golem::release()
{
	_hp->release();
	SAFE_DELETE(_hp);
}

void golem::update()
{
	_count++;
	

	if (!_startAttack)move();
	imgRectMake();
	golemFrame();
	golemAttack();
	hp();
	_hp->update();

	//key();
	
	if (KEYMANAGER->isStayKeyDown('E'))
	{
		//_isDead = true;
		//EFFECTMANAGER->play("»Ð»Ð", pos.x + 3 - CAMERAMANAGER->getRenderRc().left, pos.y + 10 - CAMERAMANAGER->getRenderRc().top);
		EFFECTMANAGER->play("»Ð»Ð",pos.x- CAMERAMANAGER->getRenderRc().left, pos.y - CAMERAMANAGER->getRenderRc().top);

	}

	

}

void golem::render()
{
	
	if (_isDead)  //Á×¾úÀ»¶§ ·£´õ
	{
		//_dead->frameRender(getMemDC(), pos.x - 55, pos.y - 20);


		//if (_count % 5 == 0)
		//{
		//	_dead->setFrameX(_tempCurrent);
		//	_tempCurrent++;
		//	if (_tempCurrent > _dead->getMaxFrameX())
		//	{
		//		_tempCurrent = 0;
		//		_isDead = false;
		//	}
		//}
		_isDead = false;
	}


	RECT cam = CAMERAMANAGER->getRenderRc();
	RectangleCam(getMemDC(), rc, cam);

	if (tempX > 0 && tempY > 0 && tempX*tempX > tempY*tempY)
	{
		_right = true; _left = false; _down = false; _up = false;
		if (_noneAttacked)_golem[2]->frameRender(getMemDC(), rc.left + 6 - cam.left, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);//¿À¸¥ÂÊ

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

			_attackedGolem[5]->frameRender(getMemDC(), rc.left - cam.left + 6, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);
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


			_attackedGolem[4]->frameRender(getMemDC(), rc.left - cam.left + 6, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);
		}
	}
	if (tempX > 0 && tempY< 0 && tempX*tempX > tempY*tempY)
	{
		_right = true; _left = false; _down = false; _up = false;
		if (_noneAttacked)_golem[2]->frameRender(getMemDC(), rc.left + 6 - cam.left, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);//¿À¸¥ÂÊ

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

			_attackedGolem[5]->frameRender(getMemDC(), rc.left - cam.left + 6, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);
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


			_attackedGolem[4]->frameRender(getMemDC(), rc.left - cam.left + 6, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);
		}
	}
	if (tempX < 0 && tempY > 0 && tempX*tempX > tempY*tempY)
	{
		_right = false; _left = true; _down = false; _up = false;
		if (_noneAttacked)_golem[1]->frameRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top, _currentX[1], _currentY[1]);//¿ÞÂÊ

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

			_attackedGolem[3]->frameRender(getMemDC(), rc.left - cam.left - 51, rc.top + 5 - cam.top, _currentX[1], _currentY[1]);
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


			_attackedGolem[2]->frameRender(getMemDC(), rc.left - cam.left - 51, rc.top + 5 - cam.top, _currentX[1], _currentY[1]);
		}
	}
	if (tempX < 0 && tempY < 0 && tempX*tempX > tempY*tempY)
	{
		_right = false; _left = true; _down = false; _up = false;
		if (_noneAttacked)_golem[1]->frameRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top, _currentX[1], _currentY[1]);//¿ÞÂÊ

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

			_attackedGolem[3]->frameRender(getMemDC(), rc.left - cam.left - 51, rc.top + 5 - cam.top, _currentX[1], _currentY[1]);
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


			_attackedGolem[2]->frameRender(getMemDC(), rc.left - cam.left - 51, rc.top + 5 - cam.top, _currentX[1], _currentY[1]);
		}
	}
	if (tempX > 0 && tempY > 0 && tempY*tempY > tempX*tempX)
	{
		_right = false; _left = false; _down = true; _up = false;

		if (_noneAttacked)_golem[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX[0], _currentY[0]);//¾Æ·¡

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

			_attackedGolem[1]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX[0], _currentY[0]);
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


			_attackedGolem[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX[0], _currentY[0]);

		}



	}
	if (tempX < 0 && tempY >0 && tempY*tempY > tempX*tempX)
	{
		_right = false; _left = false; _down = true; _up = false;

		if (_noneAttacked)_golem[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX[0], _currentY[0]);//¾Æ·¡

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

			_attackedGolem[1]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX[0], _currentY[0]);
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


			_attackedGolem[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, _currentX[0], _currentY[0]);
		}
	}
	if (tempX > 0 && tempY <0 && tempY*tempY > tempX*tempX)
	{
		_right = false; _left = false; _down = false; _up = true;
		if (_noneAttacked)_golem[3]->frameRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, _currentX[3], _currentY[3]);//À§

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

			_attackedGolem[7]->frameRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, _currentX[3], _currentY[3]);
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


			_attackedGolem[6]->frameRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, _currentX[3], _currentY[3]);
		}
	}
	if (tempX < 0 && tempY <0 && tempY*tempY > tempX*tempX)
	{
		_right = false; _left = false; _down = false; _up = true;
		if (_noneAttacked)_golem[3]->frameRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, _currentX[3], _currentY[3]);//À§

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

			_attackedGolem[7]->frameRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, _currentX[3], _currentY[3]);
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


			_attackedGolem[6]->frameRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, _currentX[3], _currentY[3]);
		}
	}

	char str[100];
	sprintf(str, "distance : %f  , _startAttack : %d , _isAttack : %d ", distance, _startAttack, _isAttack);
	TextOut(getMemDC(), 100, 100, str, strlen(str));




	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		_isAttacked = true;
		_noneAttacked = false;
	}


	_hp->render();
	
	
	





}

void golem::imgRectMake()
{
	rc = RectMakeCenter(pos.x, pos.y, _golem[0]->getFrameWidth(), _golem[0]->getFrameHeight());

}

void golem::hp()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	_hp->setX((pos.x - IMAGEMANAGER->findImage("°ñ·½Á¤¸é")->getFrameWidth() / 2 +5) - cam.left);
	_hp->setY((pos.y - 80) - cam.top);
	_hp->setGauge(_currentHp, 200);
}

void golem::golemFrame()
{
	for (int i = 0; i < 4; i++)
	{
		if (!_attackCountBool[i])
		{
			if (_count % 5 == 0)
			{

				_golem[i]->setFrameX(_currentX[i]);
				_currentX[i]++;

				if (_currentX[i] > 47)
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
				_golem[i]->setFrameX(_currentX[i]);
				_currentX[i]++;

				if (_currentX[i] >_golem[i]->getMaxFrameX())
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

void golem::golemAttack()
{
	gameObject* _player = OBJECTMANAGER->findObject(objectType::PLAYER, "player");

	distance = getDistance(pos.x, pos.y, _player->pos.x, _player->pos.y);

	if (distance < 90)
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
		if (_down)
		{
			_attackCountBool[0] = true;
			_currentX[0] = 48;
		}
		if (_left)
		{
			_attackCountBool[1] = true;
			_currentX[1] = 48;

		}
		if (_right)
		{
			_attackCountBool[2] = true;
			_currentX[2] = 48;
		}

		if (_up)
		{
			_attackCountBool[3] = true;
			_currentX[3] = 48;
		}
	}

}

void golem::move()
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
void golem::key()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_left = true;
		_right = false;
		_up = false;
		_down = false;
		pos.x -= 1;
	}
	//¿À¸¥ÂÊ ÀÌµ¿
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_left = false;
		_right = true;
		_up = false;
		_down = false;

		pos.x += 1.f;

	}
	//À§·ÎÀÌµ¿
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_left = false;
		_right = false;
		_up = true;
		_down = false;

		pos.y -= 1.f;

	}
	//¾Æ·¡ÂÊÀÌµ¿
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_left = false;
		_right = false;
		_up = false;
		_down = true;

		pos.y += 1.f;

	}


	// °ñ·½ °ø°Ý



}
