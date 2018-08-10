#include "stdafx.h"
#include "cameraManager.h"

HRESULT cameraManager::init()
{
	_pos.x = WINSIZEX / 2;
	_pos.y = WINSIZEY / 2;

	_oldPos = _pos;
	_renderRc = RectMakeCenter(_pos.x, _pos.y, WINSIZEX, WINSIZEY);

	_mapSize.x = WINSIZEX;
	_mapSize.y = WINSIZEY;

	_shakeStrenth = 0;
	_shakeTimer = 0;
	
	_isShake = false;
	_isShaking = false;
	_shakePos = tagFloat(0, 0);
	_shakeTimer = 0;
	_shakeStrenth = 0;

	return S_OK;
}

void cameraManager::release()
{

}

void cameraManager::update()
{

	this->cameraMove();

	if (_renderRc.left < 0)
	{
		_pos.x -= _renderRc.left;
	}
	if (_renderRc.right > _mapSize.x)
	{
		_pos.x -= _renderRc.right - _mapSize.x;
	}
	if (_renderRc.top < 0)
	{
		_pos.y -= _renderRc.top;
	}
	if (_renderRc.bottom > _mapSize.y)
	{
		_pos.y -= _renderRc.bottom - _mapSize.y;
	}

	
}

void cameraManager::render(HDC hdc)
{
	/*char str[125];
	sprintf_s(str, "%f", _shakeTimer);
	TextOut(hdc, WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));*/

}

void cameraManager::cameraMove()
{
	_pos.x = _target.x;
	_pos.y = _target.y;

	if (_isShake)
	{
		static int dir = 1;

		_shakeTimer -= TIMEMANAGER->getElapedTime();

		_shakePos.x += _shakeStrenth * dir;
		_shakePos.y += _shakeStrenth * dir;

		dir *= -1;

		if (_shakeTimer < 0)
		{
			_isShake = false;
			_shakePos = tagFloat(0, 0);
			_shakeTimer = 0;
		}
	}

	//·£´õ ·ºÆ® ÁÂÇ¥ ÃÊ±âÈ­
	_renderRc = RectMakeCenter(_pos.x, _pos.y, WINSIZEX, WINSIZEY);

}

void cameraManager::cameraSlideMove(float speed)
{
	//Å¸°Ù°ú ÁÂÇ¥°¡ ¸ÂÁö¾ÊÀ¸¸é?
	if (_target.x != _pos.x || _target.y != _pos.y)
	{
		_angle = getAngle(_pos.x, _pos.y, _target.x, _target.y);
		
		
		_oldPos = _pos;

		_pos.x += cosf(_angle) * speed;
		_pos.y += -sinf(_angle)* speed;

		if ((_oldPos.x < _target.x && _target.x < _pos.x) ||
			(_oldPos.x > _target.x && _target.x > _pos.x))
		{
			_pos.x = _target.x;
		}
		if ((_oldPos.y < _target.y && _target.y < _pos.y) ||
			(_oldPos.y > _target.y && _target.y > _pos.y))
		{
			_pos.y = _target.y;
		}
	}

	if (_renderRc.left < 0)
	{
		//_pos.x -= _renderRc.left;
		_pos.x = WINSIZEX/2;
		_target.x = _pos.x;
	}
	if (_renderRc.right > _mapSize.x)
	{
		//_pos.x -= _renderRc.right - _mapSize.x;
		_pos.x = _mapSize.x - WINSIZEX/2;
		_target.x = _pos.x;
	}
	if (_renderRc.top < 0)
	{
		//_pos.y -= _renderRc.top;
		_pos.y = WINSIZEY / 2;
		_target.y = _pos.y;
	}
	if (_renderRc.bottom > _mapSize.y)
	{
		//_pos.y -= _renderRc.bottom - _mapSize.y;
		_pos.y = _mapSize.y - WINSIZEY / 2;
		_target.y = _pos.y;
	}

	if (_isShake)
	{
		
		static int dir = 1;

		_shakeTimer -= TIMEMANAGER->getElapedTime();

		_shakePos.x += _shakeStrenth * dir;
		_shakePos.y += _shakeStrenth * dir;

		dir *= -1;

		if (_shakeTimer < 0)
		{
			_isShake = false;
			_shakePos = tagFloat(0, 0);
			_shakeTimer = 0;
		}
		
	}

	_renderRc = RectMakeCenter(_pos.x, _pos.y, WINSIZEX, WINSIZEY);
}

void cameraManager::connectTarget(float x, float y, float delayTime)
{
	if (delayTime <= 0.0f)
	{
		_target.x = x;
		_target.y = y;
	}
}

RECT cameraManager::getRenderRc()
{
	_renderRc = RectMakeCenter(_pos.x - _shakePos.x, _pos.y - _shakePos.y, WINSIZEX, WINSIZEY);

	return _renderRc;
}

RECT cameraManager::getRenderSourRc()
{
	_renderRc = RectMakeCenter(_pos.x, _pos.y, WINSIZEX, WINSIZEY);

	return _renderRc;
}

void cameraManager::savePosition()
{
	_savePos.x = _pos.x;
	_savePos.y = _pos.y;

}

void cameraManager::shakeCamera(float strenth, float time)
{
	_shakeTimer = time;
	_isShake = true;
	_shakeStrenth = strenth;
	

}
