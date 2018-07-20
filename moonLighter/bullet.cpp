#include "stdafx.h"
#include "bullet.h"
//=============================================================
//	## bullet ## (공용총알 - 너희들이 만들면 된다)
//=============================================================
HRESULT bullet::init(const char * imageName, int bulletMax, float range)
{
	//총알 이미지 초기화
	_imageName = imageName;
	//총알갯수 및 사거리 초기화
	_bulletMax = bulletMax;
	_range = range;
	//_gravity = 0;

	count = index = 0;

	_landImg = IMAGEMANAGER->findImage("land");
	_effectImg = IMAGEMANAGER->addFrameImage("effect", "./Image/explosion.bmp", 832, 62, 26, 1, true, RGB(255, 0, 255));
	//effectX = 0;
	//effectY = 0;
	_isEffect = false;
	return S_OK;
}

void bullet::release(void)
{
}

void bullet::update(void)
{
	this->move();

	for(int i =0; i< _vBullet.size(); ++i)
	{
	
		COLORREF color = GetPixel(_landImg->getMemDC(), _vBullet[i].x, _vBullet[i].y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		//마젠타가 아니면 y위치를 맞춰라
		if (!(r == 255 && g == 0 && b == 255))
		{
			_vBullet[i].y -= _vBullet[i].bulletImage->getHeight() / 2;
			HBRUSH MyBrush, OldBrush;
			HPEN MyPen, OldPen;

			MyBrush = CreateSolidBrush(RGB(255, 0, 255));
			OldBrush = (HBRUSH)SelectObject(_landImg->getMemDC(), MyBrush);

			MyPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 255));
			OldPen = (HPEN)SelectObject(_landImg->getMemDC(), MyPen);

			EllipseMakeCenter(_landImg->getMemDC(), _vBullet[i].x, _vBullet[i].y, 100, 100);

			SelectObject(_landImg->getMemDC(), OldBrush);
			SelectObject(_landImg->getMemDC(), OldPen);

			DeleteObject(MyBrush);
			DeleteObject(OldBrush);

			DeleteObject(MyPen);
			DeleteObject(OldPen);
			
			effectX = _vBullet[i].x;
			effectY = _vBullet[i].y;

			_isEffect = true;
			
			this->removeBullet(i);
		
		}
	}

	if (_isEffect == true)
	{
		this->EffectFrame();
		CAMERAMANAGER->connectTarget(effectX, effectY);
	}


}

void bullet::render(void)
{
	RECT renderRC = CAMERAMANAGER->getRenderRc();
	

	_viBullet = _vBullet.begin();
	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->render(getMemDC(), _viBullet->rc.left - renderRC.left, _viBullet->rc.top- renderRC.top);
		
	
		//픽셀좌표읽는 렉트
		RECT rc = RectMakeCenter((_viBullet->x) - renderRC.left, (_viBullet->y) - renderRC.top, 10, 10);
		Rectangle(getMemDC(), rc);
	}
	if (_isEffect == true)
		IMAGEMANAGER->frameRender("effect", getMemDC(), effectX - renderRC.left, effectY-renderRC.top);


}

void bullet::fire(float x, float y, float angle, float speed)
{
	//총알 벡터에 담는것을 제한하자
	if (_bulletMax < _vBullet.size() + 1) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.speed = speed;
	bullet.angle = angle;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.gravity = 0;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getWidth(),
		bullet.bulletImage->getHeight());
	bullet.y = bullet.y + bullet.bulletImage->getHeight();

	//벡터에 담기
	_vBullet.push_back(bullet);
}

void bullet::move()
{
	_viBullet = _vBullet.begin();
	for (; _viBullet != _vBullet.end();)
	{
		_viBullet->gravity += 0.05;
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed;
		_viBullet->y += _viBullet->gravity;
		if (_viBullet->gravity >= 10.0f)
			_viBullet->gravity = 10.0f;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());

		CAMERAMANAGER->connectTarget(_viBullet->x, _viBullet->y);

		_viBullet->y + _viBullet->bulletImage->getHeight();
		//총알이 사거리보다 커졌을때
		float distance = getDistance(_viBullet->fireX, _viBullet->fireY,
			_viBullet->x, _viBullet->y);
		if (_range < distance)
		{
			_viBullet = _vBullet.erase(_viBullet);
			//_gravity = 0.0f;
		}
		else
		{
			++_viBullet;
		}
	}
}

void bullet::removeBullet(int index)
{
	_vBullet.erase(_vBullet.begin() + index);
}

void bullet::EffectFrame()
{
	
	count++;
	if (count % 3 == 0)
	{
		index++;
		if (index >_effectImg->getMaxFrameX())
		{
			*_trun = (*_trun + 1) % 2;
			index = 0;
			_isEffect = false;
		}
		_effectImg->setFrameX(index);
	}

}


//=============================================================
//	## missile ## (missile[0] -> 배열처럼 미리 장전해두고 총알발사)
//=============================================================
HRESULT missile::init(int bulletMax, float range)
{
	//사거리, 총알갯수 초기화
	_range = range;
	_bulletMax = bulletMax;

	//총알의 갯수만큼 구조체를 초기화 한 후 벡터에 담기
	for (int i = 0; i < bulletMax; i++)
	{
		//총알 구조체 선언
		tagBullet bullet;
		//제로메모리 또는 멤셋
		//구조체의 변수들의 값을 한번에 0으로 초기화 시켜준다
		ZeroMemory(&bullet, sizeof(tagBullet));
		bullet.bulletImage = new image;
		bullet.bulletImage->init("missile.bmp", 25, 124, true, RGB(255, 0, 255));
		bullet.speed = 5.0f;
		bullet.fire = false;

		//벡터에 담기
		_vBullet.push_back(bullet);
	}

	return S_OK;
}

void missile::release(void)
{
	for (int i = 0; i < _vBullet.size(); i++)
	{
		_vBullet[i].bulletImage->release();
		SAFE_DELETE(_vBullet[i].bulletImage);
	}
}

void missile::update(void)
{
	this->move();
}

void missile::render(void)
{
	/*
	for (int i = 0; i < _vBullet.size(); i++)
	{
		if (!_vBullet[i].fire) continue;
		_vBullet[i].bulletImage->render(getMemDC(), _vBullet[i].rc.left, _vBullet[i].rc.top);
	}
	*/

	_viBullet = _vBullet.begin();
	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;
		_viBullet->bulletImage->render(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
	}
}

void missile::fire(float x, float y)
{
	_viBullet = _vBullet.begin();
	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->fire) continue;

		_viBullet->fire = true;
		_viBullet->x = _viBullet->fireX = x;
		_viBullet->y = _viBullet->fireY = y;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());
		break;
	}
}

void missile::move()
{
	_viBullet = _vBullet.begin();
	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;

		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());

		//총알이 사거리보다 커졌을때 
		float distance = getDistance(_viBullet->fireX, _viBullet->fireY,
			_viBullet->x, _viBullet->y);
		if (_range < distance)
		{
			_viBullet->fire = false;
		}
	}
}

//=============================================================
//	## missileM1 ## (폭탄처럼 한발씩 발사하면서 생성하고 자동삭제)
//=============================================================
HRESULT missileM1::init(int bulletMax, float range)
{
	//총알갯수, 사거리 초기화
	_bulletMax = bulletMax;
	_range = range;

	return S_OK;
}

void missileM1::release(void)
{
}

void missileM1::update(void)
{
	move();
}

void missileM1::render(void)
{

	_viBullet = _vBullet.begin();
	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
	
		_viBullet->count++;
		if (_viBullet->count % 3 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);
			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}
			_viBullet->count = 0;
		}
	}
}

void missileM1::fire(float x, float y)
{
	//총알 벡터에 담는것을 제한하자
	if (_bulletMax < _vBullet.size() + 1) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new image;
	bullet.bulletImage->init("missile.bmp", 416, 64, 13, 1);
	bullet.speed = 5.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());

	//벡터에 담기
	_vBullet.push_back(bullet);
}

void missileM1::move()
{
	_viBullet = _vBullet.begin();
	for (; _viBullet != _vBullet.end();)
	{
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());

		//총알이 사거리보다 커졌을때
		float distance = getDistance(_viBullet->fireX, _viBullet->fireY,
			_viBullet->x, _viBullet->y);
		if (_range < distance)
		{
			_viBullet->bulletImage->release();
			SAFE_DELETE(_viBullet->bulletImage);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else
		{
			++_viBullet;
		}
	}
}

void missileM1::removeMissileM1(int index)
{
	_vBullet[index].bulletImage->release();
	SAFE_DELETE(_vBullet[index].bulletImage);
	_vBullet.erase(_vBullet.begin() + index);
}


