#include "stdafx.h"
#include "player.h"



HRESULT player::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);
	
	_index = _count = 0;
	_time = 0.0f;
	_speed = 3.3f;
	_acceleration = 1.5f;
	_isUp = false;
	_isRight = false;
	_isRolling = false;
	_isInvincible = false;

	will = new image;
	will = IMAGEMANAGER->findImage("will");
	//will->init("Image/will_shop2.bmp", 1800, 2160, 10, 12, true, RGB(255, 0, 255));
	_rc = RectMake(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());
	
	_probeX = pos.x + (will->getFrameWidth() / 2);
	_probeY = pos.y + (will->getFrameHeight() / 2);
	
	CAMERAMANAGER->connectTarget(pos.x, pos.y);
	
	return S_OK;
}

void player::release(void)
{
	gameObject::release();
}

void player::update(void)
{
	gameObject::update();

	CAMERAMANAGER->connectTarget(pos.x, pos.y);

	/*
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		
		pos.x -= 5;

		_probeX = pos.x - 35;

		for (int i = _probeX + 5; i >= _probeX - 5; --i)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), i, pos.y);
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (r == 255 && g == 0 && b == 0)
			{
				pos.x = i + 35;
				break;
			}
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		pos.x += 5;

		_probeX = pos.x + 35;

		for (int i = _probeX - 5; i < _probeX + 5; ++i)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), i, pos.y);
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (r == 255 && g == 0 && b == 0)
			{
				pos.x = i - 35;
				break;
			}
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		pos.y -= 5;

		_probeY = pos.y - 35;

		for (int i = pos.y + 35; i >= pos.y - 35; i--)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), pos.x, i);
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (r == 255 && g == 0 && b == 0)
			{
				pos.y = i + 35;
				break;
			}
		}

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		pos.y += 5;

		_probeY = pos.y+ 35;

		for (int i = _probeY - 10; i < _probeY + 10; ++i)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), pos.x, i);
			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (r == 255 && g == 0 && b == 0)
			{
				pos.y = i - 35;
				break;
			}
		}


	}
	
	if (KEYMANAGER->isStayKeyDown('T'))
	{
		CAMERAMANAGER->shakeCamera(5.0f, 11.0f);
	}
	*/

	rc = RectMakeCenter(pos.x, pos.y, 70, 70);
	
	
	//this->collision();
	
	move();
}

void player::render(void)
{
	
	RECT cam = CAMERAMANAGER->getRenderRc();

	//RectangleMake(getMemDC(), pos.x - cam.left, pos.y - cam.top, 70, 70);
	//Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top, rc.right - cam.left, rc.bottom - cam.top);
	//RectangleMake(getMemDC(), pos.x - cam.left, _probeY - cam.top, 10, 10);
	//RectangleMake(getMemDC(),_probeX- cam.left, pos.y - cam.top, 10, 10);

	will->frameRender(getMemDC(), pos.x - cam.left, pos.y - cam.top);
	//IMAGEMANAGER->findImage("will")->frameRender(getMemDC(), pos.x - cam.left, pos.y - cam.top);

	if (KEYMANAGER->isToggleKey(VK_DELETE))
	{
		Rectangle(getMemDC(), _rc);
	}
	if (KEYMANAGER->isToggleKey(VK_END))
	{
		Rectangle(getMemDC(), _rcProbe);
	}
	

}


//���ʹ̿� �浹ó��
void player::collision()
{
	RECT temp;
	//findObjects�� �ش� Ÿ�԰� Ű���� ������ �ִ� Ŭ������ ���Ϳ� ��Ƽ� ���� ��ȯ ���ִ� ������ �մϴ�.
	//������! ���� �ּҰ��� ����Ű�� �ֽ��ϴ�. 
	vector<gameObject*> _mini = OBJECTMANAGER->findObjects(objectType::ENEMY, "enemy");

	
	for (int i = 0; i < _mini.size(); ++i)
	{
		if (IntersectRect(&temp, &rc, &_mini[i]->rc))
		{
			//������Ʈ �Ŵ��� ������Ʈ�� ������
			/*
			//���� ������Ʈ�� ��������ʴٸ�
			if (miter->second[i]->isLive() == false)
			{
				miter->second[i]->release();
				SAFE_DELETE(miter->second[i]);
				miter->second.erase(miter->second.begin() + i);
				--i;
				continue;
			}
			
			��� �ڵ尡 �ִµ� �浹�� ������ mini�� �׾���! ��� ������Ʈ �Ŵ����ʿ� Set�Լ��� ��ȣ�� �����ϴ� 
			�׷� ������Ʈ �Ŵ��� �ʿ��� ���͸� ���� �մϴ�. 
			��� �츰 ������ ���͸� ����� ��¼�� ���ص� �׾��ٰ� isLive = false�� �ٲ��ִ°͸����ε� ���͸� �������ݴϴ�.

			����� �츰 ���ʹ̿��� ���������� �ƴ� ������Ʈ �Ŵ����� ���������� �ϰ� �ֱ⿡ ��ü���⿡ �´� �ڵ��� �ϰ� �ִ°��Դϴ�.

			*/
			_mini[i]->setIsLive(false);
			
		}
	}


}

void player::move()
{
	++_count;

	//if(_scene == ���� or ����)
	if (_isRolling != true)
	{
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_isUp = true;
			will->setFrameX(_index);
			will->setFrameY(4);
			if (_count % 10 == 0)
			{
				++_index;
				if (_index > 7)
				{
					_index = 0;
				}
			}
			pos.y -= _speed;
			_probeX = pos.x;
			_probeY = pos.y;
			for (int i = _probeY +10; i < _probeY + 30; ++i)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), _probeX, i);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					pos.y = i;
					break;
				}
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_isUp = false;
			will->setFrameX(_index);
			will->setFrameY(5);
			if (_count % 10 == 0)
			{
				++_index;
				if (_index > 7)
				{
					_index = 0;
				}
			}
			pos.y += _speed;
			_probeX = pos.x;
			_probeY = pos.y + will->getFrameHeight();
			for (int i = _probeY - 10; i < _probeY - 30; --i)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), _probeX, i);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					pos.y = _probeY;
					break;
				}
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_isRight = true;
			will->setFrameX(_index);
			will->setFrameY(6);
			if (_count % 10 == 0)
			{
				++_index;
				if (_index > 7)
				{
					_index = 0;
				}
			}
			pos.x += _speed;
			_probeX = pos.x + will->getFrameWidth();
			_probeY = pos.y;
			for (int i = _probeX - 10; i < _probeX - 30; --i)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), i, _probeY);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					pos.x = i;
					break;
				}
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_isRight = false;
			will->setFrameX(_index);
			will->setFrameY(7);
			if (_count % 10 == 0)
			{
				--_index;
				if (_index < 0)
				{
					_index = 7;
				}
			}
			pos.x -= _speed;
			_probeX = pos.x - will->getFrameWidth()/2;
			_probeY = pos.y;
			for (int i = _probeX - 30; i < _probeX + 30; ++i)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("radZone")->getMemDC(), i, _probeY);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					pos.x = i;
					break;
				}
			}

		}
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_index = 0;
			_isRolling = true;
			_isInvincible = true;
			_acceleration = 0.5f;
		}
	}
	else
	{
		if (_isUp)
		{
			will->setFrameX(_index);
			will->setFrameY(8);
			if (_count % 10 == 0)
			{
				++_index;
				if (_index > 7)
				{
					_index = 0;
					_isRolling = false;
					_isInvincible = false;
				}
			}
			
			pos.y -= (_speed + _acceleration);
		}
		if (_isUp == false)
		{
			will->setFrameX(_index);
			will->setFrameY(9);
			if (_count % 10 == 0)
			{
				++_index;
				if (_index > 7)
				{
					_index = 0;
					_isRolling = false;
					_isInvincible = false;
				}
			}
			pos.y += (_speed + _acceleration);
		}
		if (_isRight)
		{
			will->setFrameX(_index);
			will->setFrameY(10);
			if (_count % 10 == 0)
			{
				++_index;
				if (_index > 7)
				{
					_index = 0;
					_isRolling = false;
					_isInvincible = false;
				}
			}
			pos.x += (_speed + _acceleration);
		}
		if(_isRight == false)
		{
			will->setFrameX(_index);
			will->setFrameY(11);
			if (_count % 10 == 0)
			{
				++_index;
				if (_index > 7)
				{
					_index = 0;
					_isRolling = false;
					_isInvincible = false;
				}
			}
			pos.x -= (_speed + _acceleration);
		}
	}
	_rc = RectMake(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());
	_rcProbe = RectMake(_probeX, _probeY, _probeX + 30, _probeY + 30);
	
		
	
	
	


	/*
	//else if((_scene == ���� )
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		pos.y -= speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		pos.y += speed;

	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		pos.x -= speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		pos.x += speed;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{

	}

	*/
}
