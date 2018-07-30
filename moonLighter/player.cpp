#include "stdafx.h"
#include "player.h"



HRESULT player::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);
	
	_index = _count = 0;
	_cntIsInvincible = 0;
	_time = 0.0f;
	_speed = 5.0f;
	_acceleration = 2.5f;
	_attCharge = 0;
	_maxHp = 1000;
	_currentHp = 1000;
	_isUp = true;
	_isDown = false;
	_isLeft = false;
	_isRight = false;
	_isRolling = false;
	_isInvincible = false;
	
	_isAttacking = false;
	_isRcSwordOn = false;

	a = false;

	will = IMAGEMANAGER->findImage("will");
	willAttack = IMAGEMANAGER->findImage("will_shortAttack");
	_hpBar = new progressBar;
	_hpBar->init("will_hpBar", 100, 30, 130, 228, 118, 38);
	_hpBar->setRect(10, 0);

	//���� effect �ʱ�ȭ
	_efcShortSword1 = new effect;
	_efcShortSword1->init(IMAGEMANAGER->findImage("will_shortSword1"), 0.3f);

	EFFECTMANAGER->addEffect("���ҵ�", "will_shortSword1", 0.3f, 50);








	//will->init("Image/will_shop2.bmp", 1800, 2160, 10, 12, true, RGB(255, 0, 255));
	//_rc = RectMake(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());

	_rcBody = RectMakeCenter(pos.x, pos.y, 60, 100);										//lysADD(�÷��̾� ���׾Ƹ� ��Ʈ �ʱ�ȭ)
	_rcSword = RectMakeCenter(pos.x, pos.y, 100, 100);										//�÷��̾� �� ���ݹ��� ��Ʈ �ʱ�ȭ
	rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());		//�÷��̾� �̹��� ��Ʈ �ʱ�ȭ
	
	_probeX = pos.x;
	_probeY = pos.y;
	
	

	//CAMERAMANAGER->connectTarget(pos.x, pos.y);

	return S_OK;
}

void player::release(void)
{
	gameObject::release();
	_efcShortSword1->release();
	SAFE_DELETE(_efcShortSword1);
}

void player::update(void)
{
	gameObject::update();
	
	//CAMERAMANAGER->connectTarget(pos.x, pos.y);

	/*
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		
		pos.x -= 5;

		_probeX = pos.x - 35;

		for (int i = _probeX + 5; i >= _probeX - 5; --i)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("redZone")->getMemDC(), i, pos.y);
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
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("redZone")->getMemDC(), i, pos.y);
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
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("redZone")->getMemDC(), pos.x, i);
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
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("redZone")->getMemDC(), pos.x, i);
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

	//rc = RectMakeCenter(pos.x, pos.y, 70, 70);
	
	 
	this->collision();
	this->move();
	_hpBar->update_isHit();
	this->enemyCheckCollision();
}

void player::render(void)
{
	
	RECT cam = CAMERAMANAGER->getRenderRc();

	//RectangleMake(getMemDC(), pos.x - cam.left, pos.y - cam.top, 70, 70);
	//Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top, rc.right - cam.left, rc.bottom - cam.top);
	//RectangleMake(getMemDC(), pos.x - cam.left, _probeY - cam.top, 10, 10);
	//RectangleMake(getMemDC(),_probeX- cam.left, pos.y - cam.top, 10, 10);

	if (!_isAttacking)	//���ݸ���� �ƴ� ��쿡 ���
	{
		will->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
	}
	else    //���� ����� ����� ���
	{
		willAttack->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
	}
	


	if (KEYMANAGER->isToggleKey(VK_F9))  //lysADD(ī�޶� ��Ʈ ���)
	{
		Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top, rc.right - cam.left, rc.bottom - cam.top);
	}
	if (KEYMANAGER->isToggleKey(VK_F10))	//lysADD(�ȼ��浹üũ ��Ʈ ���)
	{
		Rectangle(getMemDC(), _rcProbe.left - cam.left, _rcProbe.top - cam.top, _rcProbe.right - cam.left, _rcProbe.bottom - cam.top);
	}
	if (KEYMANAGER->isToggleKey(VK_F11))	//lysADD(���������, ���� �浹 ��Ʈ ���)
	{
		Rectangle(getMemDC(), _rcBody.left - cam.left, _rcBody.top - cam.top, _rcBody.right - cam.left, _rcBody.bottom - cam.top);
	}
	if (KEYMANAGER->isToggleKey(VK_F12))	//lysADD(���� ��� �� ���� ���� ��Ʈ ���)
	{
		Rectangle(getMemDC(), _rcSword.left - cam.left, _rcSword.top - cam.top, _rcSword.right - cam.left, _rcSword.bottom - cam.top);
	}
	
	
	_hpBar->render_isHit(); //ü�¹� ����
	this->enemyCheckCollision();
	//_efcShortSword1->render();
	//EFFECTMANAGER->render();
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
		if (IntersectRect(&temp, &_rcSword, &_mini[i]->rc))
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
		if (_isAttacking == false)
		{
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				_isIdle = false;
				_isUp = true;
				_isDown = false;
				_isRight = false;
				_isLeft = false;
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
				_probeY = pos.y - (will->getFrameHeight() / 4);
				rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth() / 2, will->getFrameHeight());
				_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);
				int disTemp = _rcProbe.top - rc.top;
				for (int i = _probeY; i > _probeY - 15; --i)
				{
					COLORREF color = GetPixel(_pixelImg->getMemDC(), _probeX, i);
					int r = GetRValue(color);
					int g = GetGValue(color);
					int b = GetBValue(color);

					if (r == 255 && g == 0 && b == 0)
					{
						pos.y = i + will->getFrameHeight() * 0.5 - disTemp;
						break;
					}
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_UP))
			{
				_isIdle = true;
			}
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				_isIdle = false;
				_isDown = true;
				_isUp = false;
				_isRight = false;
				_isLeft = false;
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
				_probeY = pos.y + (will->getFrameHeight() / 4);
				rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth() / 2, will->getFrameHeight());
				_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);
				int disTemp = _rcProbe.bottom - rc.bottom;
				for (int i = _probeY; i < _probeY + 15; ++i)
				{
					COLORREF color = GetPixel(_pixelImg->getMemDC(), _probeX, i);
					int r = GetRValue(color);
					int g = GetGValue(color);
					int b = GetBValue(color);

					if (r == 255 && g == 0 && b == 0)
					{
						pos.y = i - will->getFrameHeight() * 0.5 - disTemp;
						break;
					}
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
			{
				_isIdle = true;
			}
			if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_isIdle = false;
				_isDown = false;
				_isUp = false;
				_isRight = true;
				_isLeft = false;
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
				_probeX = pos.x + 20;
				_probeY = pos.y;
				rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth() / 2, will->getFrameHeight());
				_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);
				int disTemp = _rcProbe.right - _rcProbe.left;
				for (int i = _probeX; i < _probeX + 15; ++i)
				{
					COLORREF color = GetPixel(_pixelImg->getMemDC(), i, _probeY);
					int r = GetRValue(color);
					int g = GetGValue(color);
					int b = GetBValue(color);

					if (r == 255 && g == 0 && b == 0)
					{
						pos.x = i - disTemp;
						break;
					}
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
			{
				_isIdle = true;
			}
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_isDown = false;
				_isUp = false;
				_isIdle = false;
				_isLeft = true;
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
				_probeX = pos.x - 20;
				_probeY = pos.y;
				rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth() / 2, will->getFrameHeight());
				_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);
				int disTemp = _rcProbe.right - _rcProbe.left;
				for (int i = _probeX; i > _probeX - 15; --i)
				{
					COLORREF color = GetPixel(_pixelImg->getMemDC(), i, _probeY);
					int r = GetRValue(color);
					int g = GetGValue(color);
					int b = GetBValue(color);

					if (r == 255 && g == 0 && b == 0)
					{
						pos.x = i + disTemp;
						break;
					}
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
			{
				_isIdle = true;

			}
			if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
			{
				SOUNDMANAGER->play("will_roll", 0.7f);
				_index = 0;
				_isRolling = true;
				_isInvincible = true;
				_acceleration = 0.5f;
			}
			if (_isIdle == true)
			{
				if (_isUp)
				{
					will->setFrameX(_index);
					will->setFrameY(0);
					if (_count % 7 == 0)
					{
						++_index;
						if (_index > 9)
						{
							_index = 0;
						}
					}
				}
				else if (_isDown)
				{
					will->setFrameX(_index);
					will->setFrameY(1);
					if (_count % 7 == 0)
					{
						++_index;
						if (_index > 9)
						{
							_index = 0;
						}
					}
				}
				else if (_isRight)
				{
					will->setFrameX(_index);
					will->setFrameY(2);
					if (_count % 7 == 0)
					{
						++_index;
						if (_index > 9)
						{
							_index = 0;
						}
					}
				}
				else if (_isLeft)
				{
					will->setFrameX(_index);
					will->setFrameY(3);
					if (_count % 7 == 0)
					{
						++_index;
						if (_index > 9)
						{
							_index = 0;
						}
					}
				}
			}
		}
			//////////////////////////////////////////////////�ൿ////////////////

		if (KEYMANAGER->isOnceKeyDown('A'))		// ����
		{
			if (_isAttacking == false && _isRolling == false)
			{
				_isAttacking = true;
				_index = 0;
				SOUNDMANAGER->play("will_shortSwordAttack", 0.7f);
			}
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			_isHit = true;
			_damage = 150;
			_currentHp -= _damage;
			_hpBar->setIsHit();
			_hpBar->setGaugeOfDamage(_currentHp, _maxHp, _damage);
		}
		if (KEYMANAGER->isOnceKeyUp('S'))
		{
			_isHit = false;
		}
		if (KEYMANAGER->isStayKeyDown('D'))
		{
			EFFECTMANAGER->play("���ҵ�", _ptMouse.x, _ptMouse.y);
		}
		if (_isAttacking == true)
		{
			if (_count % 7 == 0)
			{
				++_index;
			}

			if (_isUp)
			{
				willAttack->setFrameX(_index);
				willAttack->setFrameY(0);
				if (_index > willAttack->getMaxFrameX())
				{
					_isAttacking = false;
					_isIdle = true;
				}
				if (2 == _index)
				{
					//_isRcSwordOn = true;
					_rcSword = RectMakeCenter(pos.x, pos.y - 20, 130, 100);
				}
				else
				{
					//_isRcSwordOn = false;
					_rcSword = RectMake(-50, -50, 2, 2);
				}

			}
			else if (_isDown)
			{
				willAttack->setFrameX(_index);
				willAttack->setFrameY(1);
				if (_index > willAttack->getMaxFrameX())
				{
					_isAttacking = false;
					_isIdle = true;
				}
				if (2 == _index)
				{
					//_isRcSwordOn = true;
					_rcSword = RectMakeCenter(pos.x, pos.y + 40, 130, 100);
				}
				else
				{
					//_isRcSwordOn = false;
					_rcSword = RectMake(-50, -50, 2, 2);
				}
			}
			else if (_isRight)
			{
				willAttack->setFrameX(_index);
				willAttack->setFrameY(2);
				if (_index > willAttack->getMaxFrameX())
				{
					_isAttacking = false;
					_isIdle = true;
				}
				if (2 == _index)
				{
					//_isRcSwordOn = true;
					_rcSword = RectMakeCenter(pos.x + 25, pos.y + 25, 100, 130);
				}
				else
				{
					//_isRcSwordOn = false;
					_rcSword = RectMake(-50, -50, 2, 2);
				}
			}
			else if (_isLeft)
			{
				willAttack->setFrameX(_index);
				willAttack->setFrameY(3);
				if (_index > willAttack->getMaxFrameX())
				{
					_isAttacking = false;
					_isIdle = true;
				}
				if (2 == _index)
				{
					//_isRcSwordOn = true;
					_rcSword = RectMakeCenter(pos.x - 25, pos.y + 25, 100, 130);
				}
				else
				{
					//_isRcSwordOn = false;
					_rcSword = RectMake(-50, -50, 2, 2);
				}
			}
		}
		else
		{
			//_isRcSwordOn = false;
			_rcSword = RectMake(-50, -50, 2, 2);
		}
		///////////////////////////////////////////////////////////////////////////////
	}
	else
	{
		if (_isUp)
		{
			will->setFrameX(_index);
			will->setFrameY(8);
			if (_count % 6 == 0)
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
			_probeX = pos.x;
			_probeY = pos.y - (will->getFrameHeight() / 4);
			rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());
			_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);
			int disTemp = _rcProbe.top - rc.top;
			for (int i = _probeY; i > _probeY - 15; --i)
			{
				COLORREF color = GetPixel(_pixelImg->getMemDC(), _probeX, i);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					pos.y = i + will->getFrameHeight() * 0.5 - disTemp;
					break;
				}
			}
		}
		else if (_isDown)
		{
			will->setFrameX(_index);
			will->setFrameY(9);
			if (_count % 6 == 0)
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
			_probeX = pos.x;
			_probeY = pos.y + (will->getFrameHeight() / 4);
			rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());
			_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);
			int disTemp = _rcProbe.bottom - rc.bottom;
			for (int i = _probeY; i < _probeY + 15; ++i)
			{
				COLORREF color = GetPixel(_pixelImg->getMemDC(), _probeX, i);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					pos.y = i - will->getFrameHeight() * 0.5 - disTemp;
					break;
				}
			}
		}
		else if (_isRight)
		{
			will->setFrameX(_index);
			will->setFrameY(10);
			if (_count % 6 == 0)
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
			_probeX = pos.x + 20;
			_probeY = pos.y;
			rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());
			_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);
			int disTemp = _rcProbe.right - _rcProbe.left;
			for (int i = _probeX; i < _probeX + 15; ++i)
			{
				COLORREF color = GetPixel(_pixelImg->getMemDC(), i, _probeY);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					pos.x = i - disTemp;
					break;
				}
			}
		}
		else if(_isLeft)
		{
			will->setFrameX(_index);
			will->setFrameY(11);
			if (_count % 6 == 0)
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
			_probeX = pos.x - 20;
			_probeY = pos.y;
			rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());
			_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);
			int disTemp = _rcProbe.right - _rcProbe.left;
			for (int i = _probeX; i > _probeX - 15; --i)
			{
				COLORREF color = GetPixel(_pixelImg->getMemDC(), i, _probeY);
				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == 255 && g == 0 && b == 0)
				{
					pos.x = i + disTemp;
					break;
				}
			}
		}
	}
	rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());
	_rcBody = RectMakeCenter(pos.x, pos.y, 60, 100);
	_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);
	
	if (_isInvincible)
	{
		++_cntIsInvincible;
		if (_cntIsInvincible > 100)
		{
			_cntIsInvincible = 0;
			_isInvincible = false;

		}
	}
	
	
	


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

void player::enemyCheckCollision()
{
	RECT rcTemp;
	vector<gameObject*> _enemyObject = OBJECTMANAGER->findObjects(objectType::ENEMY, "weed");

	//gameObject* _enemyObject = OBJECTMANAGER->findObject(objectType::ENEMY, "weed");
	
	
	char str[128];
	sprintf_s(str, "%d", a);
	TextOut(getMemDC(), WINSIZEX-100,100 , str, strlen(str));
	for (int i = 0; i < _enemyObject.size(); ++i)
	{
		//if (IntersectRect(&rcTemp, &_rcSword, &((smallSlime*)_enemyObject[i])->getRect()))
		//{
		//	EFFECTMANAGER->play("���ҵ�", _enemyObject[i]->pos.x, _enemyObject[i]->pos.y);
		//}
		if (IntersectRect(&rcTemp, &_rcSword, &((weed*)_enemyObject[i])->getRect()))
		{
			EFFECTMANAGER->play("���ҵ�", _enemyObject[i]->pos.x - CAMERAMANAGER->getRenderRc().left, _enemyObject[i]->pos.y - CAMERAMANAGER->getRenderRc().top);
			a = true;
		}
		else
		{
			a = false;
		}
	}
	for (int i = 0; i < _enemyObject.size(); ++i)
	{
	
		if (IntersectRect(&rcTemp, &_rcBody, &((weed*)_enemyObject[i])->getRect()))
		{
			if (_isInvincible == false)
			{
				_isHit = true;
				_damage = 300;
				_currentHp -= _damage;
				_hpBar->setIsHit();
				_hpBar->setGaugeOfDamage(_currentHp, _maxHp, _damage);
				_isInvincible = true;
				SOUNDMANAGER->play("will_damaged", 0.7f);
			}
			a = true;
		}
	}
}

