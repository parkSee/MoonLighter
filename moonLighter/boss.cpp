#include "stdafx.h"
#include "boss.h"

HRESULT boss::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);

	_boss[0] = IMAGEMANAGER->findImage("�����������");
	_attackedBoss[0] = IMAGEMANAGER->findImage("����������ʻ���");
	_attackedBoss[1] = IMAGEMANAGER->findImage("������������Ͼ�");
	_boss[1] = IMAGEMANAGER->findImage("�������������");
	_attackedBoss[2] = IMAGEMANAGER->findImage("������������ʻ���");
	_attackedBoss[3] = IMAGEMANAGER->findImage("��������������Ͼ�");
	_boss[2] = IMAGEMANAGER->findImage("�����ڿ�����");
	_attackedBoss[4] = IMAGEMANAGER->findImage("�����ڿ����ʻ���");
	_attackedBoss[5] = IMAGEMANAGER->findImage("�����ڿ������Ͼ�");
	_boss[3] = IMAGEMANAGER->findImage("�����ڿ���");
	_attackedBoss[6] = IMAGEMANAGER->findImage("�����ڿ��ʻ���");
	_attackedBoss[7] = IMAGEMANAGER->findImage("�����ڿ����Ͼ�");

	

	_boss[8] = IMAGEMANAGER->findImage("��������");





	

	EFFECTMANAGER->addEffect("������������Ʈ�ٿ������2", "������������Ʈ�ٿ������", 0.2f, 20);
	EFFECTMANAGER->addEffect("������������Ʈ�ٿ����2", "������������Ʈ�ٿ����", 0.2f, 20);
	EFFECTMANAGER->addEffect("������������Ʈ������2", "������������Ʈ������", 0.2f, 20);
	EFFECTMANAGER->addEffect("������������Ʈ��������2", "������������Ʈ��������", 0.2f, 20);
	EFFECTMANAGER->addEffect("��������Ʈ������2", "��������Ʈ������", 0.2f, 20);
	EFFECTMANAGER->addEffect("��������Ʈ����2", "��������Ʈ����", 0.2f, 20);

	_hp = new progressBar;
	_hp->init("����ü�¹�", "ü�²�����", pos.x, pos.y, 73, 8);
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
	pixelCollision();
	hp();
	_hp->update();

	
}

void boss::render()
{
	
	RECT cam = CAMERAMANAGER->getRenderRc();

	RectangleCam(getMemDC(), rc, cam);

	if (tempX > 0 && tempY > 0 && tempX*tempX > tempY*tempY)
	{
		_rightUp = false; _leftUp = false; _rightDown = true; _leftDown = false;
		if (_noneAttacked)_boss[1]->frameRender(getMemDC(), rc.left -30 - cam.left, rc.top +5 - cam.top, _currentX[1], _currentY[1]);//������

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
		if (_noneAttacked)_boss[2]->frameRender(getMemDC(), rc.left -30 - cam.left, rc.top + 5 - cam.top, _currentX[2], _currentY[2]);//������

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
		if (_noneAttacked)_boss[0]->frameRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top, _currentX[0], _currentY[0]);//����

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
		if (_noneAttacked)_boss[3]->frameRender(getMemDC(), rc.left - 51 - cam.left, rc.top + 5 - cam.top, _currentX[3], _currentY[3]);//����

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

		if (_noneAttacked)_boss[1]->frameRender(getMemDC(), rc.left - cam.left -30 , rc.top - cam.top +5, _currentX[1], _currentY[1]);//�Ʒ�

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

		if (_noneAttacked)_boss[0]->frameRender(getMemDC(), rc.left - cam.left -50, rc.top - cam.top +5, _currentX[0], _currentY[0]);//�Ʒ�

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
		if (_noneAttacked)_boss[2]->frameRender(getMemDC(), rc.left - cam.left -30, rc.top + 5 - cam.top, _currentX[2], _currentY[2]);//��

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
		if (_noneAttacked)_boss[3]->frameRender(getMemDC(), rc.left - cam.left - 50, rc.top + 5 - cam.top, _currentX[3], _currentY[3]);//��

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
	char str[128];
	sprintf_s(str, "leftDown ;%d ,LeftUp : %d , RightDown : %d, Right Up : %d", _leftDown, _leftUp, _rightDown, _rightUp);
	TextOut(getMemDC(), 300, 300, str, strlen(str));

	//RectangleCam(getMemDC(), _rc[0], cam);
	//RectangleCam(getMemDC(), _rc[1], cam);
	//RectangleCam(getMemDC(), _rc[2], cam);
	//RectangleCam(getMemDC(), _rc[3], cam);
	
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

	RECT cam = CAMERAMANAGER->getRenderRc();
	
	_rc[0] = RectMakeCenter(pos.x + _boss[0]->getFrameWidth() / 2, pos.y, 2, _boss[0]->getFrameHeight());//������
	_rc[1] = RectMakeCenter(pos.x - _boss[0]->getFrameWidth() / 2, pos.y, 2, _boss[0]->getFrameHeight());//����
	_rc[2] = RectMakeCenter(pos.x, pos.y - _boss[0]->getFrameHeight() / 2, _boss[0]->getFrameWidth(), 2);//��
	_rc[3] = RectMakeCenter(pos.x, pos.y + _boss[0]->getFrameHeight() / 2, _boss[0]->getFrameWidth(), 2);//�Ʒ�


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