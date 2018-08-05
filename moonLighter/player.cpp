#include "stdafx.h"
#include "player.h"



HRESULT player::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);
	_cntPendant = 0;
	_index = _count = 0;
	_cntIsInvincible = 0;
	_time = 0.0f;
	_speed = 5.0f;
	_acceleration = 2.5f;
	_attCharge = 0;
	_maxHp = 1000;
	_currentHp = 1000;
	_isIdle = true;
	_isUp = false;
	_isDown = true;
	_isLeft = false;
	_isRight = false;
	_isRolling = false;
	_isInvincible = false;
	_isGoingHome = false;
	_isAutomatic = false;
	_isUsingPendant = false;
	_isHit = false;
	_isDead = false;
	_isAttacking = false;
	_isRcSwordOn = false;
	_playerMove = true;

	a = false;

	will = IMAGEMANAGER->findImage("will");
	willDungeon = IMAGEMANAGER->findImage("will_dungeon");
	willAttack = IMAGEMANAGER->findImage("will_shortAttack");
	willDamaged = IMAGEMANAGER->findImage("will_damaged");
	willPendant = IMAGEMANAGER->findImage("will_pendant");
	willGoHome = IMAGEMANAGER->findImage("will_goHome");

	_hpBar = new progressBar;
	_hpBar->init("will_hpBar", 100, 30, 130, 228, 118, 38);
	_hpBar->setRect(10, 0);

	//공격 effect 초기화
	_efcShortSword1 = new effect;
	_efcShortSword1->init(IMAGEMANAGER->findImage("will_shortSword1"), 0.3f);

	EFFECTMANAGER->addEffect("숏소드", "will_shortSword1", 0.3f, 50);








	//will->init("Image/will_shop2.bmp", 1800, 2160, 10, 12, true, RGB(255, 0, 255));
	//_rc = RectMake(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());

	_rcBody = RectMakeCenter(pos.x, pos.y, 60, 100);										//lysADD(플레이어 몸뚱아리 렉트 초기화)
	_rcSword = RectMakeCenter(pos.x, pos.y, 100, 100);										//플레이어 검 공격범위 렉트 초기화
	rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());		//플레이어 이미지 렉트 초기화
	
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
	if (KEYMANAGER->isStayKeyDown('T'))
	{
		CAMERAMANAGER->shakeCamera(5.0f, 11.0f);
	}
	*/

	//this->collision();
	this->willAction();
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

	if (_isDead)
	{
		willDungeon->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
	}
	else if (!_isAttacking)	//공격모션이 아닐 경우에 출력
	{
		willDungeon->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
	}
	else if(_isAttacking)    //공격 모션일 경우의 출력
	{
		willAttack->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
	}
	if (_isGoingHome)
	{
		willGoHome->frameRender(getMemDC(), (rc.left - willGoHome->getFrameWidth() / 4 + 5) - cam.left, (rc.top - willGoHome->getFrameHeight() / 4 + 20) - cam.top);
	}
	willPendant->frameRender(getMemDC(), 1190, 620);
	
	if (KEYMANAGER->isToggleKey(VK_F9))  //lysADD(카메라 렉트 출력)
	{
		Rectangle(getMemDC(), rc.left - cam.left, rc.top - cam.top, rc.right - cam.left, rc.bottom - cam.top);
	}
	if (KEYMANAGER->isToggleKey(VK_F10))	//lysADD(픽셀충돌체크 렉트 출력)
	{
		Rectangle(getMemDC(), _rcProbe.left - cam.left, _rcProbe.top - cam.top, _rcProbe.right - cam.left, _rcProbe.bottom - cam.top);
	}
	if (KEYMANAGER->isToggleKey(VK_F11))	//lysADD(아이템토글, 몬스터 충돌 렉트 출력)
	{
		Rectangle(getMemDC(), _rcBody.left - cam.left, _rcBody.top - cam.top, _rcBody.right - cam.left, _rcBody.bottom - cam.top);
	}
	if (KEYMANAGER->isToggleKey(VK_F12))	//lysADD(공격 모션 중 공격 범위 렉트 출력)
	{
		Rectangle(getMemDC(), _rcSword.left - cam.left, _rcSword.top - cam.top, _rcSword.right - cam.left, _rcSword.bottom - cam.top);
	}
	
	
	_hpBar->render_isHit(); //체력바 렌더
	this->enemyCheckCollision();
	//_efcShortSword1->render();
	//EFFECTMANAGER->render();
	if (_isHit)
	{
		willDamaged->alphaRender(getMemDC(), 100);
		_isHit = false;
	}
}


//에너미와 충돌처리
void player::collision()
{
	RECT temp;
	//findObjects는 해당 타입과 키값을 가지고 있는 클래스를 벡터에 담아서 값을 반환 해주는 역할을 합니다.
	//포인터! 같은 주소값을 가르키고 있습니다. 
	vector<gameObject*> _mini = OBJECTMANAGER->findObjects(objectType::ENEMY, "enemy");

	
	for (int i = 0; i < _mini.size(); ++i)
	{
		if (IntersectRect(&temp, &_rcSword, &_mini[i]->rc))
		{
			//오브젝트 매니저 업데이트로 가보면
			/*
			//만약 오브젝트가 살아있지않다면
			if (miter->second[i]->isLive() == false)
			{
				miter->second[i]->release();
				SAFE_DELETE(miter->second[i]);
				miter->second.erase(miter->second.begin() + i);
				--i;
				continue;
			}
			
			라는 코드가 있는데 충돌이 됬으면 mini는 죽었어! 라고 오브젝트 매니저쪽에 Set함수로 신호를 보냅니다 
			그럼 오브젝트 매니저 쪽에서 벡터를 삭제 합니다. 
			고로 우린 일일히 벡터를 지우고 어쩌고 안해도 죽었다고 isLive = false로 바꿔주는것만으로도 벡터를 삭제해줍니다.

			참고로 우린 에너미에게 직접접근이 아닌 오브젝트 매니저로 간접접근을 하고 있기에 객체지향에 맞는 코딩을 하고 있는것입니다.

			*/
			_mini[i]->setIsLive(false);
			
		}
	}


}

void player::dungeonMove()
{
	if (_isRolling != true)
	{
		if (_playerMove)
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
					willDungeon->setFrameX(_index);
					willDungeon->setFrameY(0);
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
					rc = RectMakeCenter(pos.x, pos.y, willDungeon->getFrameWidth() / 2, willDungeon->getFrameHeight());
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
							pos.y = i + willDungeon->getFrameHeight() * 0.5 - disTemp;
							break;
						}
					}
					if (_count % 30 == 0)
					{
						SOUNDMANAGER->play("will_step_town_gravel", 0.1f);
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
					willDungeon->setFrameX(_index);
					willDungeon->setFrameY(1);
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
					_probeY = pos.y + (willDungeon->getFrameHeight() / 4);
					rc = RectMakeCenter(pos.x, pos.y, willDungeon->getFrameWidth() / 2, willDungeon->getFrameHeight());
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
							pos.y = i - willDungeon->getFrameHeight() * 0.5 - disTemp;
							break;
						}
					}
					if (_count % 30 == 0)
					{
						SOUNDMANAGER->play("will_step_town_gravel", 0.1f);
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
					willDungeon->setFrameX(_index);
					willDungeon->setFrameY(2);
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
					rc = RectMakeCenter(pos.x, pos.y, willDungeon->getFrameWidth() / 2, willDungeon->getFrameHeight());
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
					if (_count % 30 == 0)
					{
						SOUNDMANAGER->play("will_step_town_gravel", 0.1f);
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
					willDungeon->setFrameX(_index);
					willDungeon->setFrameY(3);
					if (_count % 10 == 0)
					{
						++_index;
						if (_index > 7)
						{
							_index = 0;
						}
					}
					pos.x -= _speed;
					_probeX = pos.x - 20;
					_probeY = pos.y;
					rc = RectMakeCenter(pos.x, pos.y, willDungeon->getFrameWidth() / 2, willDungeon->getFrameHeight());
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
					if (_count % 30 == 0)
					{
						SOUNDMANAGER->play("will_step_town_gravel", 0.1f);
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
						willDungeon->setFrameX(_index);
						willDungeon->setFrameY(10);
						if (_count % 7 == 0)
						{
							++_index;
							if (_index > willDungeon->getMaxFrameX())
							{
								_index = 0;
							}
						}
					}
					else if (_isDown)
					{
						willDungeon->setFrameX(_index);
						willDungeon->setFrameY(11);
						if (_count % 7 == 0)
						{
							++_index;
							if (_index > willDungeon->getMaxFrameX())
							{
								_index = 0;
							}
						}
					}
					else if (_isRight)
					{
						willDungeon->setFrameX(_index);
						willDungeon->setFrameY(8);
						if (_count % 7 == 0)
						{
							++_index;
							if (_index > willDungeon->getMaxFrameX())
							{
								_index = 0;
							}
						}
					}
					else if (_isLeft)
					{
						willDungeon->setFrameX(_index);
						willDungeon->setFrameY(9);
						if (_count % 7 == 0)
						{
							++_index;
							if (_index > willDungeon->getMaxFrameX())
							{
								_index = 0;
							}
						}
					}
				}
			}
			//////////////////////////////////////////////////행동////////////////

			if (KEYMANAGER->isOnceKeyDown('A'))		// 공격
			{
				if (_isAttacking == false && _isRolling == false)
				{
					_isAttacking = true;
					_index = 0;
					SOUNDMANAGER->play("will_shortSwordAttack", 0.3f);
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
				EFFECTMANAGER->play("숏소드", _ptMouse.x, _ptMouse.y);
			}
			if (KEYMANAGER->isOnceKeyDown('F'))
			{
				if (_isDead == false)
				{
					_index = 0;
					_isDead = true;
				}
			}
			if (KEYMANAGER->isStayKeyDown('L'))
			{
				_isUsingPendant = true;
				willPendant->setFrameX(_cntPendant);
				willPendant->setFrameY(0);
				if (_count % 7 == 0)
				{
					++_cntPendant;
					if (_cntPendant > willPendant->getMaxFrameX())
					{
						_index = 0;
						_isAutomatic = true;
						_isGoingHome = true;
					}
				}
			}
			if (KEYMANAGER->isOnceKeyUp('L'))
			{
				_isUsingPendant = false;
				SOUNDMANAGER->stop("will_pendant_charge");
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
	}
	else
	{
		if (_isUp)
		{
			willDungeon->setFrameX(_index);
			willDungeon->setFrameY(6);
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
			_probeY = pos.y - (willDungeon->getFrameHeight() / 4);
			rc = RectMakeCenter(pos.x, pos.y, willDungeon->getFrameWidth(), willDungeon->getFrameHeight());
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
					pos.y = i + willDungeon->getFrameHeight() * 0.5 - disTemp;
					break;
				}
			}
		}
		else if (_isDown)
		{
			willDungeon->setFrameX(_index);
			willDungeon->setFrameY(7);
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
			_probeY = pos.y + (willDungeon->getFrameHeight() / 4);
			rc = RectMakeCenter(pos.x, pos.y, willDungeon->getFrameWidth(), willDungeon->getFrameHeight());
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
					pos.y = i - willDungeon->getFrameHeight() * 0.5 - disTemp;
					break;
				}
			}
		}
		else if (_isRight)
		{
			willDungeon->setFrameX(_index);
			willDungeon->setFrameY(4);
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
			rc = RectMakeCenter(pos.x, pos.y, willDungeon->getFrameWidth(), willDungeon->getFrameHeight());
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
		else if (_isLeft)
		{
			willDungeon->setFrameX(_index);
			willDungeon->setFrameY(5);
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
			rc = RectMakeCenter(pos.x, pos.y, willDungeon->getFrameWidth(), willDungeon->getFrameHeight());
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

	rc = RectMakeCenter(pos.x, pos.y, willDungeon->getFrameWidth(), willDungeon->getFrameHeight());
	_rcBody = RectMakeCenter(pos.x, pos.y, 60, 100);
	_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);

	if (_isInvincible)
	{
		++_cntIsInvincible;
		if (_cntIsInvincible > 75)
		{
			_cntIsInvincible = 0;
			_isInvincible = false;

		}
	}

	if (_isUsingPendant == true)
	{
		if (SOUNDMANAGER->isPlaySound("will_pendant_charge") == false)
		{
			SOUNDMANAGER->play("will_pendant_charge", 0.5f);
		}
	}
	else
	{
		noUsePendant();
	}
}
void player::willAction()
{
	++_count;
	if (_isAutomatic == false)
	{
		dungeonMove();
	}
	else
	{
		willDoSomething();
	}
}
void player::willDoSomething()
{
	if (_isDead)
	{
		if (SOUNDMANAGER->isPlaySound("will_death") == false)
		{
			SOUNDMANAGER->play("will_death", 0.7f);
		}
		willDungeon->setFrameX(_index);
		willDungeon->setFrameY(12);
		if (_count % 4 == 0)
		{
			++_index;
			if (_index > willDungeon->getMaxFrameX())
			{
				OBJECTMANAGER->reset();
				this->setIsActive(false);
				SCENEMANAGER->loadScene("dungeonLobby");
			}
		}
	}
	else if (_isGoingHome)
	{
		goHome();
	}

}
void player::noUsePendant()
{
	willPendant->setFrameX(_cntPendant);
	willPendant->setFrameY(0);
	if (_count % 3 == 0)
	{
		--_cntPendant;
		if (_cntPendant < 0) { _cntPendant = 0; }
	}
}
void player::goHome()
{
	if (SOUNDMANAGER->isPlaySound("will_pendant_absorb"))
	{
		SOUNDMANAGER->play("will_pendant_absorb");
	}
	willGoHome->setFrameX(_index);
	willGoHome->setFrameY(0);
	if (_count % 4 == 0) //4
	{
		++_index;
		if (_index > willGoHome->getMaxFrameX())
		{
			_isGoingHome = false;
			_isAutomatic = false;
			OBJECTMANAGER->reset();
			SCENEMANAGER->loadScene("townScene");
		}
	}
}
void player::enemyCheckCollision()
{
	if (_isDead != true)
	{
		RECT rcTemp;
		vector<gameObject*> _enemyObject = OBJECTMANAGER->findObjects(objectType::ENEMY, "weed");

		//gameObject* _enemyObject = OBJECTMANAGER->findObject(objectType::ENEMY, "weed");


		char str[128];
		sprintf_s(str, "%d", a);
		TextOut(getMemDC(), WINSIZEX - 100, 100, str, strlen(str));
		for (int i = 0; i < _enemyObject.size(); ++i)
		{
			//if (IntersectRect(&rcTemp, &_rcSword, &((smallSlime*)_enemyObject[i])->getRect()))
			//{
			//	EFFECTMANAGER->play("숏소드", _enemyObject[i]->pos.x, _enemyObject[i]->pos.y);
			//}
			if (IntersectRect(&rcTemp, &_rcSword, &((weed*)_enemyObject[i])->getRect()))
			{
				EFFECTMANAGER->play("숏소드", _enemyObject[i]->pos.x - CAMERAMANAGER->getRenderRc().left, _enemyObject[i]->pos.y - CAMERAMANAGER->getRenderRc().top);
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
					_damage = 100;
					_currentHp -= _damage;
					_hpBar->setIsHit();
					_hpBar->setGaugeOfDamage(_currentHp, _maxHp, _damage);
					_isInvincible = true;
					SOUNDMANAGER->play("will_damaged", 0.3f);
				}
				if (_currentHp < 0)
				{
					_count = 0;
					_index = 0;
					_isDead = true;
					_isAutomatic = true;
				}
				a = true;
			}
		}
	}
}

