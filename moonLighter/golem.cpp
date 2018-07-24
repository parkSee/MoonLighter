#include "stdafx.h"
#include "golem.h"

HRESULT golem::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName,_pos);
	_golem[0] = IMAGEMANAGER->addFrameImage("°ñ·½", "./image/enemy/°ñ·½Á¤¸é.bmp", 4800, 170, 60, 1);
	_golem[1] = IMAGEMANAGER->addFrameImage("°ñ·½¿ÞÂÊ", "./image/enemy/°ñ·½¿ÞÂÊ.bmp", 7800, 125, 60, 1);
	_golem[2] = IMAGEMANAGER->addFrameImage("°ñ·½¿À¸¥ÂÊ", "./image/enemy/°ñ·½¿À¸¥ÂÊ.bmp", 7800, 140, 60, 1);
	_golem[3] = IMAGEMANAGER->addFrameImage("°ñ·½µÚÂÊ", "./image/enemy/°ñ·½µÚÂÊ.bmp", 4800, 140, 60, 1);
	
	

	RECT rc = RectMakeCenter(pos.x, pos.y, _golem[0]->getFrameWidth(), _golem[0]->getFrameHeight());
	
	_count = _currentY  = 0;
	

	for (int i = 0; i < 4; i++)
	{
		_attackCountBool[i] = false;
		_attackCount[i] = 0;
		_currentX[i] = 0;
	}
	_left = false;
	_right = false;
	_up = false;
	_down = false;
	
	
	return S_OK;
}

void golem::release()
{



}

void golem::update()
{
	_count++;

	rc = RectMakeCenter(pos.x, pos.y, _golem[0]->getFrameWidth(), _golem[0]->getFrameHeight());
	
	

	golemFrame();
	
	
	//key();

	
}

void golem::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();
	
	
	
	
	_golem[0]->frameRender(getMemDC(), rc.left-cam.left, rc.top-cam.top);//¾Æ·¡
	if (_left)_golem[1]->frameRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top);//¿ÞÂÊ
	if (_right)_golem[2]->frameRender(getMemDC(), rc.left + 6 - cam.left, rc.top - 9 - cam.top);//¿À¸¥ÂÊ
	if (_up)_golem[3]->frameRender(getMemDC(), rc.left + 1 - cam.left, rc.top - 9 - cam.top);//À§
	

}

void golem::golemFrame()
{
	for (int i = 0; i < 4; i++)
	{
		if (!_attackCountBool[i])
		{
			if (_count % 7 == 0)
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
			if (_attackCount[i] % 7 == 0)
			{
				_golem[i]->setFrameX(_currentX[i]);
				_currentX[i]++;
				if (_currentX[i] >_golem[i]->getMaxFrameX())
				{
					_currentX[i] = 0;
					_attackCount[i] = 0;
					_attackCountBool[i] = false;
				}

			}
		}
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
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
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
