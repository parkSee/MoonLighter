#include "stdafx.h"
#include "golem.h"
#include"player.h"

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

	_dmgFontTen = IMAGEMANAGER->findImage("´ë¹ÌÁöÆùÆ®");
	_dmgFontOne = IMAGEMANAGER->findImage("´ë¹ÌÁöÆùÆ®");
	_dmgImgY = -100;
	_dmgImgCount = 0;
	_dmgImgCountBool = false;
	_dmgFontRc[0] = RectMakeCenter(pos.x - 30, pos.y, _dmgFontTen->getFrameWidth(), _dmgFontTen->getFrameHeight());
	_dmgFontRc[1] = RectMakeCenter(pos.x, pos.y, _dmgFontTen->getFrameWidth(), _dmgFontTen->getFrameHeight());

	

	 rc = RectMakeCenter(pos.x, pos.y, _golem[0]->getFrameWidth(), _golem[0]->getFrameHeight());
	 _rc2 = RectMakeCenter(pos.x, pos.y, _golem[0]->getFrameWidth(), _golem[0]->getFrameHeight());
	_count = _attackedCount = _tempCurrent = _dmgCount = 0;



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
	_damaaged = false;
	_deadBool = false;
	_deadEffectBool = false;
	_deadBool = false;
	_dmg = false;
	_isAttacked3 = false;
	_attackBool = false;


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
	
	
	if (!_startAttack && _currentHp >0)move();
	imgRectMake();
	golemFrame();
	golemAttack();
	this->pixelCollision();
	this->damaged();
	hp();
	_hp->update();
	if (_deadBool)dead();
	//key();
	
	

	

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
	if (_currentHp > 0)
	{
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
	}
	else
	{
		if (tempX > 0 && tempY > 0 && tempX*tempX > tempY*tempY)
		{
			_right = true; _left = false; _down = false; _up = false;
			if (_noneAttacked)_golem[2]->frameRender(getMemDC(), rc.left + 6 - cam.left, rc.top - 9 - cam.top, _currentX[2], _currentY[2]);//¿À¸¥ÂÊ

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
				_attackedGolem[5]->frameAlphaRender(getMemDC(), rc.left - cam.left + 6, rc.top - 9 - cam.top, 230);

			}

			if (_isAttacked2)
			{
				_attackedCount++;
				if (_attackedCount > 3)
				{
					_isAttacked2 = false;
					_isAttacked = false;
					_isAttacked3 = true;
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
				_attackedGolem[5]->frameAlphaRender(getMemDC(), rc.left - cam.left + 6, rc.top - 9 - cam.top, 230);

			}

			if (_isAttacked2)
			{
				_attackedCount++;
				if (_attackedCount > 3)
				{
					_isAttacked2 = false;
					_isAttacked = false;
					_isAttacked3 = true;
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
				_attackedGolem[3]->frameAlphaRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top, 230);

			}

			if (_isAttacked2)
			{
				_attackedCount++;
				if (_attackedCount > 3)
				{
					_isAttacked2 = false;
					_isAttacked = false;
					_isAttacked3 = true;
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
				_attackedGolem[3]->frameAlphaRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top, 230);

			}


			if (_isAttacked2)
			{
				_attackedCount++;
				if (_attackedCount > 3)
				{
					_isAttacked2 = false;
					_isAttacked = false;
					_isAttacked3 = true;
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
				_attackedGolem[1]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 230);

			}


			if (_isAttacked2)
			{
				_attackedCount++;
				if (_attackedCount > 3)
				{
					_isAttacked2 = false;
					_isAttacked = false;
					_isAttacked3 = true;
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
				_attackedGolem[1]->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 230);

			}

			if (_isAttacked2)
			{
				_attackedCount++;
				if (_attackedCount > 3)
				{
					_isAttacked2 = false;
					_isAttacked = false;
					_isAttacked3 = true;
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
				_attackedGolem[7]->frameAlphaRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, 230);

			}

			if (_isAttacked2)
			{
				_attackedCount++;
				if (_attackedCount > 3)
				{
					_isAttacked2 = false;
					_isAttacked = false;
					_isAttacked3 = true;
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
				_attackedGolem[7]->frameAlphaRender(getMemDC(), rc.left - cam.left + 1, rc.top - 9 - cam.top, 230);

			}

			if (_isAttacked2)
			{
				_attackedCount++;
				if (_attackedCount > 3)
				{
					_isAttacked2 = false;
					_isAttacked = false;
					_isAttacked3 = true;
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
	}

	char str[100];
	sprintf(str, "distance : %f  , _startAttack : %d , _isAttack : %d ", distance, _startAttack, _isAttack);
	TextOut(getMemDC(), 100, 100, str, strlen(str));




	


	_hp->render();
	
	
	
	//RectangleCam(getMemDC(), _rc[0], cam);
	//RectangleCam(getMemDC(), _rc[1], cam);
	//RectangleCam(getMemDC(), _rc[2], cam);
	//RectangleCam(getMemDC(), _rc[3], cam);
	if (0 < _dmgImgCount && _dmgImgCount < 30)
	{
		_dmgImgCount++;
		_dmgFontTen->frameRender(getMemDC(), _dmgFontRc[0].left - cam.left, _dmgFontRc[0].top - cam.top, 9, 0);
		_dmgFontOne->frameRender(getMemDC(), _dmgFontRc[1].left - cam.left, _dmgFontRc[1].top - cam.top, 0, 0);
		_dmgImgY -= 0.5f;
	}



	if (_dmgImgCount >= 30)
	{
		_dmgImgCount = 0;
		_dmgImgY = -100;
	}
	

	if (_startAttack)
	{
		if (50 < _currentX[0] && _currentX[0] < 60)
		{
			_attackRc = RectMakeCenter(pos.x, pos.y + 50, 50, 50);
		}

		if (50 < _currentX[1] && _currentX[0] < 60)
		{
			_attackRc = RectMakeCenter(pos.x - 50, pos.y, 50, 50);
		}

		if (50 < _currentX[2] && _currentX[0] < 60)
		{
			_attackRc = RectMakeCenter(pos.x + 50, pos.y, 50, 50);
		}

		if (50 < _currentX[3] && _currentX[0] < 60)
		{
			_attackRc = RectMakeCenter(pos.x, pos.y - 50, 50, 50);
		}
	}
	else
	{
		_attackRc = RectMakeCenter(pos.x, pos.y + 2000, 50, 50);
	}
	
	RectangleCam(getMemDC(), _attackRc, cam);
}

void golem::imgRectMake()
{
	rc = RectMakeCenter(pos.x, pos.y, _golem[0]->getFrameWidth(), _golem[0]->getFrameHeight());
	_rc2 = RectMakeCenter(pos.x, pos.y, _golem[0]->getFrameWidth(), _golem[0]->getFrameHeight());
	_dmgFontRc[0] = RectMakeCenter(pos.x - 10, pos.y + _dmgImgY, _dmgFontTen->getFrameWidth(), _dmgFontTen->getFrameHeight());
	_dmgFontRc[1] = RectMakeCenter(pos.x + 20, pos.y + _dmgImgY, _dmgFontTen->getFrameWidth(), _dmgFontTen->getFrameHeight());

}

void golem::hp()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	_hp->setX((pos.x - IMAGEMANAGER->findImage("°ñ·½Á¤¸é")->getFrameWidth() / 2 +5) - cam.left);
	_hp->setY((pos.y - 80) - cam.top);
	_hp->setGauge(_currentHp, 200);
}

void golem::damaged()
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
		SOUNDMANAGER->play("golem_hit", 0.5f);

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
void golem::pixelCollision()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	_rc[0] = RectMakeCenter(pos.x + _golem[0]->getFrameWidth() / 2, pos.y, 2, _golem[0]->getFrameHeight());//¿À¸¥ÂÊ
	_rc[1] = RectMakeCenter(pos.x - _golem[0]->getFrameWidth() / 2, pos.y, 2, _golem[0]->getFrameHeight());//¿ÞÂÊ
	_rc[2] = RectMakeCenter(pos.x, pos.y - _golem[0]->getFrameHeight() / 2, _golem[0]->getFrameWidth(), 2);//À§
	_rc[3] = RectMakeCenter(pos.x, pos.y + _golem[0]->getFrameHeight() / 2, _golem[0]->getFrameWidth(), 2);//¾Æ·¡


	_rc0X = pos.x +  _golem[0]->getFrameWidth() / 2;
	_rc0Y = pos.y -  _golem[0]->getFrameHeight() / 2;

	_rc1X = pos.x -  _golem[0]->getFrameWidth() / 2;
	_rc1Y = pos.y -  _golem[0]->getFrameHeight() / 2;

	_rc2Y = pos.y -  _golem[0]->getFrameHeight() / 2;
	_rc2X = pos.x -  _golem[0]->getFrameWidth() / 2;


	_rc3Y = pos.y +  _golem[0]->getFrameHeight() / 2;
	_rc3X = pos.x -  _golem[0]->getFrameWidth() / 2;

	


	for (int j = _rc0Y + 5; j < pos.y + _golem[0]->getFrameHeight() / 2 - 5; j++)
	{
	
		COLORREF color = GetPixel(_pixelImg->getMemDC(), pos.x + _golem[0]->getFrameWidth() / 2, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
	
		if (r == 255 && g == 0 && b == 0)
		{
			pos.x = pos.x + _golem[0]->getFrameWidth() / 2 - 41;
			break;
		}
	
	
	}
	for (int j = _rc1Y + 5; j < pos.y + _golem[0]->getFrameHeight() / 2 - 5; j++)
	{
	
		COLORREF color = GetPixel(_pixelImg->getMemDC(), pos.x - _golem[0]->getFrameWidth() / 2, j);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
	
		if (r == 255 && g == 0 && b == 0)
		{
			pos.x = pos.x - _golem[0]->getFrameWidth() / 2 + 41;
			break;
		}
	
	}
	for (int j = _rc2X + 5; j < pos.x + _golem[0]->getFrameWidth() / 2 - 5; j++)
	{
	
		COLORREF color = GetPixel(_pixelImg->getMemDC(), j, pos.y + _golem[0]->getFrameHeight() / 2);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
	
		if (r == 255 && g == 0 && b == 0)
		{
			pos.y = pos.y + _golem[0]->getFrameWidth() / 2 - 41;
			break;
		}
	
	}
	for (int j = _rc2X + 5; j < pos.x + _golem[0]->getFrameWidth() / 2 - 5; j++)
	{
	
		COLORREF color = GetPixel(_pixelImg->getMemDC(), j, pos.y - _golem[0]->getFrameHeight() / 2);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
	
		if (r == 255 && g == 0 && b == 0)
		{
			pos.y = pos.y - _golem[0]->getFrameWidth() / 2 + 41;
			break;
		}
	
	}
	

	
}

void golem::dead()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	if (_deadBool && _deadEffectBool == false)
	{
		_deadEffectBool = true;
		EFFECTMANAGER->play("»Ð»Ð", pos.x + 7, pos.y + 20);
		SOUNDMANAGER->play("enemy_death", 1.f);
		OBJECTMANAGER->getItemManager()->appear(itemType::GOLEMCORE, tagFloat(pos.x, pos.y));
		OBJECTMANAGER->getItemManager()->appear(itemType::REBAR, tagFloat(pos.x, pos.y));
	}
	setIsLive(false);
}




