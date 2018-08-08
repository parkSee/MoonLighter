#include "stdafx.h"
#include "player.h"
#include "inventory.h"


HRESULT player::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);
	_cntPendant = 0;
	_cntIsHit = 0;
	_cntFoot = 0;
	_cntHp[0] = 0;
	_cntHp[1] = 0;
	_cntHp[2] = 0;
	_cntHp[3] = 0;
	_cntHp[4] = 10;
	_cntMoney[0] = 0;
	_cntMoney[1] = 0;
	_cntMoney[2] = 0;
	_cntMoney[3] = 0;
	_index = _count = 0;
	_cntIsInvincible = 0;
	_time = 0.0f;
	_speed = 5.0f;
	_money[0] = 77;
	_money[1] = 77;
	_acceleration = 2.5f;
	_attCharge = 0;
	_maxHp = 1000;
	_currentHp = 1000;
	_beforeHp = _maxHp;
	_isIdle = true;
	_isUp = false;
	_isDown = true;
	_isLeft = false;
	_isRight = false;
	_isWalking = false;
	_isRolling = false;
	_isInvincible = false;
	_isGoingHome = false;
	_isAutomatic = false;
	_isUsingPendant = false;
	_isEnemyHit = false;
	_isHit = false;
	_isDead = false;
	_isAttacking = false;
	_isRcSwordOn = false;
	_playerMove = true;

	a = false;

	will = IMAGEMANAGER->findImage("will");
	willDungeon = IMAGEMANAGER->findImage("will_dungeon");
	willDungeonShadow = IMAGEMANAGER->findImage("will_dungeon_shadow");
	willAttack = IMAGEMANAGER->findImage("will_shortAttack");
	willAttackShadow = IMAGEMANAGER->findImage("will_shortAttack_shadow");
	willPendant = IMAGEMANAGER->findImage("will_pendant");
	willGoHome = IMAGEMANAGER->findImage("will_goHome");
	willFoot = IMAGEMANAGER->findImage("will_foot");
	willDamaged[0] = IMAGEMANAGER->findImage("will_damaged");
	willDamaged[1] = IMAGEMANAGER->findImage("will_damaged2");
	willDamaged[2] = IMAGEMANAGER->findImage("will_damaged3");
	willAttackDamaged[0] = IMAGEMANAGER->findImage("will_shortAttack_Damaged2");
	willAttackDamaged[1] = IMAGEMANAGER->findImage("will_shortAttack_Damaged3");
	number = IMAGEMANAGER->findImage("number");
	_hpBar = new progressBar;
	_hpBar->init("will_hpBar", 100, 30, 130, 228, 118, 38);
	_hpBar->setRect(10, 0);

	//공격 effect 초기화
	_efcShortSword1 = new effect;
	_efcShortSword1->init(IMAGEMANAGER->findImage("will_shortSword1"), 0.3f);

	EFFECTMANAGER->addEffect("숏소드", "will_shortSword1", 0.3f, 50);
	EFFECTMANAGER->addEffect("발자취", "will_foot", 0.6f, 10);

	_inven = new inventory;
	_inven->init();






	//will->init("Image/will_shop2.bmp", 1800, 2160, 10, 12, true, RGB(255, 0, 255));
	//_rc = RectMake(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());

	_rcBody = RectMakeCenter(pos.x, pos.y, 50, 70);
	_rcSword = RectMakeCenter(pos.x, pos.y, 100, 100);
	rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());

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

	_inven->release();
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

	_inven->update();

	this->willAction();
	this->enemyCheckCollision();
	_hpBar->update_jyp();
	numberUpdate();
}

void player::render(void)
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	if (_isDead)
	{
		willDungeonShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 80);
		willDungeon->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
	}
	else if (!_isAttacking)	//공격모션이 아닐 경우에 출력
	{
		int _count = (int)(_cntIsHit * 0.1);
		if (!_isHit)
		{
			willDungeonShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 80);
			willDungeon->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
		}
		else
		{
			if (_cntIsHit <= 4)
			{
				willDungeonShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 80);
				willDamaged[1]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
			}
			else if (_cntIsHit <= 8)
			{
				willDungeonShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 80);
				willDamaged[2]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
			}
			else if (8 < _cntIsHit && _count % 2 == 1)
			{

			}
			else if (8 < _cntIsHit && _count % 2 == 0)
			{
				willDungeonShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 80);
				willDungeon->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
			}
		}
	}
	else if (_isAttacking)    //공격 모션일 경우의 출력
	{
		int _count = (int)(_cntIsHit * 0.1);
		if (!_isHit)
		{
			willAttackShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 80);
			willAttack->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
		}
		else
		{
			if (_cntIsHit <= 4)
			{
				willAttackShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 80);
				willAttackDamaged[0]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
			}
			else if (_cntIsHit <= 8)
			{
				willAttackShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 80);
				willAttackDamaged[1]->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
			}
			else if (8 < _cntIsHit && _count % 2 == 1)
			{

			}
			else if (8 < _cntIsHit && _count % 2 == 0)
			{
				willAttackShadow->frameAlphaRender(getMemDC(), rc.left - cam.left, rc.top - cam.top, 80);
				willAttack->frameRender(getMemDC(), rc.left - cam.left, rc.top - cam.top);
			}
		}
	}
	if (_isGoingHome)
	{
		willGoHome->frameRender(getMemDC(), (rc.left - willGoHome->getFrameWidth() / 4 + 5) - cam.left, (rc.top - willGoHome->getFrameHeight() / 4 + 20) - cam.top);
	}
	//if (_isWalking)
	//{
	//	willFoot->frameAlphaRender(getMemDC(), footPos.x - cam.left, footPos.y - cam.top, 100);
	//}

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
	if (_isHit && _cntIsHit <= 2 && !_isDead)
	{
		willDamaged[0]->alphaRender(getMemDC(), 100);
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
				if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
				{
					if (_isWalking == false)
					{
						++_cntFoot;
						if (_cntFoot > 15)
						{
							_cntFoot = 0;
							_isWalking = true;
							//EFFECTMANAGER->play("발자취", footPos.x, footPos.y);
						}
					}
					if (_isIdle)
					{
						_index = 0;
						_isIdle = false;
					}
					_isDown = false;
					_isUp = false;
					_isRight = true;
					_isLeft = false;
					othersFrameUpdate(_index, 2);
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
						SOUNDMANAGER->play("will_step_town_gravel", 0.3f);
					}
				}
				if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
				{
					_isIdle = true;
				}
				if (KEYMANAGER->isStayKeyDown(VK_LEFT))
				{
					if (_isWalking == false)
					{
						++_cntFoot;
						if (_cntFoot > 15)
						{
							_cntFoot = 0;
							_isWalking = true;
							//EFFECTMANAGER->play("발자취", footPos.x, footPos.y);
						}
					}
					if (_isIdle)
					{
						_index = 0;
						_isIdle = false;
					}
					_isDown = false;
					_isUp = false;
					_isLeft = true;
					_isRight = false;
					othersFrameUpdate(_index, 3);
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
						SOUNDMANAGER->play("will_step_town_gravel", 0.3f);
					}
				}
				if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
				{
					_isIdle = true;
				}
				if (KEYMANAGER->isStayKeyDown(VK_UP))
				{
					if (_isWalking == false)
					{
						++_cntFoot;
						if (_cntFoot > 15)
						{
							_cntFoot = 0;
							_isWalking = true;
							//EFFECTMANAGER->play("발자취", footPos.x, footPos.y);
						}
					}
					if (_isIdle)
					{
						_index = 0;
						_isIdle = false;
					}
					_isUp = true;
					_isDown = false;
					_isRight = false;
					_isLeft = false;
					othersFrameUpdate(_index, 0);
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
						SOUNDMANAGER->play("will_step_town_gravel", 0.3f);
					}
				}
				if (KEYMANAGER->isOnceKeyUp(VK_UP))
				{
					_isIdle = true;
				}
				if (KEYMANAGER->isStayKeyDown(VK_DOWN))
				{
					if (_isWalking == false)
					{
						++_cntFoot;
						if (_cntFoot > 15)
						{
							_cntFoot = 0;
							_isWalking = true;
							//EFFECTMANAGER->play("발자취", footPos.x, footPos.y);
						}
					}
					if (_isIdle)
					{
						_index = 0;
						_isIdle = false;
					}
					_isDown = true;
					_isUp = false;
					_isRight = false;
					_isLeft = false;
					othersFrameUpdate(_index, 1);
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
						SOUNDMANAGER->play("will_step_town_gravel", 0.3f);
					}
				}
				if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
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
				/////////////////////////아이들 상태 프레임 업데이트/////////////////////
				if (_isIdle == true)
				{
					if (_isUp)
					{
						othersFrameUpdate(_index, 10);
					}
					else if (_isDown)
					{
						othersFrameUpdate(_index, 11);
					}
					else if (_isRight)
					{
						othersFrameUpdate(_index, 8);
					}
					else if (_isLeft)
					{
						othersFrameUpdate(_index, 9);
					}
					if (_count % 7 == 0)
					{
						++_index;
						if (_index > willDungeon->getMaxFrameX())
						{
							_index = 0;
						}
					}
				}
				//////////////////  이동 모션 프레임 /////////////////////////////////////
				else
				{
					if (_count % 6 == 0)
					{
						++_index;
						if (_index > 7)
						{
							_index = 0;
						}
					}
				}
				//////////////////////////////////////////////////행동////////////////
				if (KEYMANAGER->isOnceKeyDown('A'))		// 공격
				{
					if (_isAttacking == false && _isRolling == false)
					{
						_isEnemyHit = false;
						_isRcSwordOn = true;
						_isAttacking = true;
						_index = 0;
						SOUNDMANAGER->play("will_shortSwordAttack", 0.7f);
					}
				}
				if (KEYMANAGER->isOnceKeyDown('S'))
				{
					_isHit = true;
					_damage = 100;
					_beforeHp = _currentHp;
					_currentHp -= _damage;
					_hpBar->setGaugeOfDamage(_currentHp, _maxHp, _damage, 1);
					_money[0] = _money[1];
					_money[1] += 100;
				}
				if (KEYMANAGER->isOnceKeyDown('D'))
				{
					_currentHp += 150;
					if (_currentHp >= _maxHp)
					{
						_currentHp = _maxHp;
					}
					_hpBar->setGaugeOfHeal(_currentHp, _maxHp, 150, 1);
					if (_money[1] >= 100)
					{
						_money[0] = _money[1];
						_money[1] -= 100;
					}
				}
				if (KEYMANAGER->isStayKeyDown('L'))
				{
					_isUsingPendant = true;
					willPendant->setFrameX(_cntPendant);
					willPendant->setFrameY(0);
					if (_count % 4 == 0)
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
				_rcSword = RectMake(-50, -50, 2, 2);    /////////////////////////공격 모션 아닐 때 공격렉트 화면 밖으로
			}
			else if (_isAttacking == true)             /////////////////////////공격 상태 프레임 업데이트/////////////////////
			{
				if (_isUp)
				{
					willAttack->setFrameX(_index);
					willAttack->setFrameY(0);
					willAttackShadow->setFrameX(_index);
					willAttackShadow->setFrameY(0);
					if (2 == _index)
					{
						_rcSword = RectMakeCenter(pos.x, pos.y - 20, 100, 50);
					}
					else
					{
						_rcSword = RectMake(-50, -50, 2, 2);
					}
				}
				else if (_isDown)
				{
					willAttack->setFrameX(_index);
					willAttack->setFrameY(1);
					willAttackShadow->setFrameX(_index);
					willAttackShadow->setFrameY(1);
					if (2 == _index)
					{
						_rcSword = RectMakeCenter(pos.x, pos.y + 40, 100, 50);
					}
					else
					{
						_rcSword = RectMake(-50, -50, 2, 2);
					}
				}
				else if (_isRight)
				{
					willAttack->setFrameX(_index);
					willAttack->setFrameY(2);
					willAttackShadow->setFrameX(_index);
					willAttackShadow->setFrameY(2);
					if (2 == _index)
					{
						_rcSword = RectMakeCenter(pos.x + 25, pos.y + 25, 80, 100);
					}
					else
					{
						_rcSword = RectMake(-50, -50, 2, 2);
					}
				}
				else if (_isLeft)
				{
					willAttack->setFrameX(_index);
					willAttack->setFrameY(3);
					willAttackShadow->setFrameX(_index);
					willAttackShadow->setFrameY(3);
					if (2 == _index)
					{
						_rcSword = RectMakeCenter(pos.x - 25, pos.y + 25, 80, 100);
					}
					else
					{
						_rcSword = RectMake(-50, -50, 2, 2);
					}
				}
				if (_count % 7 == 0)
				{
					++_index;
					if (_index > willAttack->getMaxFrameX())
					{
						_index = 0;
						_isAttacking = false;
						_isIdle = true;
					}
				}
			}
		}
	}
	else
	{
		if (_isUp)
		{
			willDungeon->setFrameX(_index);
			willDungeon->setFrameY(6);
			willDungeonShadow->setFrameX(_index);
			willDungeonShadow->setFrameY(6);
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
			willDungeonShadow->setFrameX(_index);
			willDungeonShadow->setFrameY(7);
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
			willDungeonShadow->setFrameX(_index);
			willDungeonShadow->setFrameY(4);
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
			willDungeonShadow->setFrameX(_index);
			willDungeonShadow->setFrameY(5);
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
	}
	rc = RectMakeCenter(pos.x, pos.y, willDungeon->getFrameWidth(), willDungeon->getFrameHeight());
	_rcBody = RectMakeCenter(pos.x, pos.y, 50, 70);
	_rcProbe = RectMakeCenter(_probeX, _probeY, 30, 30);
	/////////////////////////////상태 업데이트//////////////////////////////////
	if (_isInvincible)
	{
		++_cntIsInvincible;
		if (_cntIsInvincible > 75)
		{
			_cntIsHit = 0;
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
	if (_currentHp <= 0)
	{
		_count = 0;
		_index = 0;
		_isDead = true;
		_isHit = false;
		_isAutomatic = true;
	}
	if (_isHit)
	{
		++_cntIsHit;
		if (_cntIsHit >= 50)
		{
			_cntIsHit = 0;
			_isHit = false;
		}
	}
	if (_isWalking)
	{
		if (_isUp)
		{
			footPos.x = RND->getFromIntTo(_rcBody.left + 20, _rcBody.right - 20);
			footPos.y = rc.bottom;
		}
		else if (_isDown)
		{
			footPos.x = RND->getFromIntTo(_rcBody.left + 20, _rcBody.right - 20);
			footPos.y = rc.top;
		}
		else if (_isLeft)
		{
			footPos.x = rc.right;
			footPos.y = RND->getFromIntTo(pos.y + 20, pos.y + 20);
		}
		else if (_isRight)
		{
			footPos.x = rc.left;
			footPos.y = RND->getFromIntTo(pos.y + 20, pos.y + 20);
		}
		_isWalking = false;
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
			SOUNDMANAGER->play("will_death");
		}
		willDungeon->setFrameX(_index);
		willDungeon->setFrameY(12);
		willDungeonShadow->setFrameX(_index);
		willDungeonShadow->setFrameY(12);
		if (_count % 5 == 0)
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
void player::othersFrameUpdate(int frameX, int frameY)
{
	willDungeon->setFrameX(frameX);
	willDungeon->setFrameY(frameY);
	willDamaged[1]->setFrameX(frameX);
	willDamaged[1]->setFrameY(frameY);
	willDamaged[2]->setFrameX(frameX);
	willDamaged[2]->setFrameY(frameY);
	willDungeonShadow->setFrameX(frameX);
	willDungeonShadow->setFrameY(frameY);
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
	if (_count % 4 == 0)
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
void player::numberUpdate()
{
	if (_beforeHp > _currentHp)
	{
		--_beforeHp;
	}
	else if(_beforeHp < _currentHp)
	{
		++_beforeHp;
	}
	_cntHp[0] = (int)(_beforeHp * 0.001);
	_cntHp[1] = (int)((_beforeHp % 1000) / 100);
	_cntHp[2] = (int)((_beforeHp % 100) / 10);
	_cntHp[3] = _beforeHp % 10;

	_cntHp[5] = (int)(_maxHp * 0.001);
	_cntHp[6] = (int)((_maxHp % 1000) / 100);
	_cntHp[7] = (int)((_maxHp % 100) / 10);
	_cntHp[8] = _maxHp % 10;

	if (_money[0] > _money[1])
	{
		--_money[0];
	}
	else if (_money[0] < _money[1])
	{
		++_money[0];
	}
	_cntMoney[0] = (int)(_money[0] * 0.001);
	_cntMoney[1] = (int)((_money[0] % 1000) / 100);
	_cntMoney[2] = (int)((_money[0] % 100) / 10);
	_cntMoney[3] = _money[0] % 10;
}
void player::numberRender()
{
	if (_beforeHp >= 1000)
	{
		number->frameRender(getMemDC(), 140, 60, _cntHp[0], 0);
	}
	number->frameRender(getMemDC(), 150, 60, _cntHp[1], 0);
	number->frameRender(getMemDC(), 160, 60, _cntHp[2], 0);
	number->frameRender(getMemDC(), 170, 60, _cntHp[3], 0);
	number->frameRender(getMemDC(), 180, 60, _cntHp[4], 0);
	number->frameRender(getMemDC(), 190, 60, _cntHp[5], 0);
	number->frameRender(getMemDC(), 200, 60, _cntHp[6], 0);
	number->frameRender(getMemDC(), 210, 60, _cntHp[7], 0);
	number->frameRender(getMemDC(), 220, 60, _cntHp[8], 0);

	if (_money[0] >= 1000)
	{
		number->frameRender(getMemDC(), 50, 120, _cntMoney[0], 0);
	}
	number->frameRender(getMemDC(), 60, 120, _cntMoney[1], 0);
	number->frameRender(getMemDC(), 70, 120, _cntMoney[2], 0);
	number->frameRender(getMemDC(), 80, 120, _cntMoney[3], 0);

	IMAGEMANAGER->findImage("coin")->render(getMemDC(), 95, 120);
}
void player::setIsIdleUp(bool isUp)
{
	if (isUp)
	{
		_isUp = isUp;
		_isDown = false;
	}
	else
	{
		_isDown = true;
		_isUp = false;
	}
}
void player::setIsIdleLeft(bool isLeft)
{
}
void player::setRevive()
{
	_currentHp = _maxHp;
	_hpBar->setGaugeOfHeal(_currentHp, _maxHp, _maxHp, 0.07);
}
void player::enemyCheckCollision()
{
	if (_isDead != true)
	{
		RECT rcTemp;
		RECT camera = CAMERAMANAGER->getRenderRc();
		vector<gameObject*> _enemyObject[5];
		_enemyObject[0] = OBJECTMANAGER->findObjects(objectType::ENEMY, "smallSlime");
		_enemyObject[1] = OBJECTMANAGER->findObjects(objectType::ENEMY, "weed");
		_enemyObject[2] = OBJECTMANAGER->findObjects(objectType::ENEMY, "golem");
		_enemyObject[3] = OBJECTMANAGER->findObjects(objectType::ENEMY, "boss");
		_enemyObject[4] = OBJECTMANAGER->findObjects(objectType::ENEMY, "bigSlime");

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < _enemyObject[i].size(); ++j)
			{
				RECT rcEnemy;
				if (i == 0)
				{
					rcEnemy = ((smallSlime*)_enemyObject[i][j])->getCollisionRect();
				}
				else if (i == 1)
				{
					rcEnemy = ((weed*)_enemyObject[i][j])->getCollisionRect();
				}
				else if (i == 2)
				{
					rcEnemy = ((golem*)_enemyObject[i][j])->getCollisionRC();
				}
				else if (i == 3)
				{
					rcEnemy = ((boss*)_enemyObject[i][j])->getCollisionRC();
				}
				if (IntersectRect(&rcTemp, &_rcSword, &rcEnemy) && _isRcSwordOn == true)
				{
					CAMERAMANAGER->shakeCamera(1.5f, 0.1);
					EFFECTMANAGER->play("숏소드", _enemyObject[i][j]->pos.x, _enemyObject[i][j]->pos.y);
					_isEnemyHit = true;
				}
				if (IntersectRect(&rcTemp, &_rcBody, &rcEnemy))
				{
					if (_isInvincible == false)
					{
						_isHit = true;
						_damage = 86;
						_beforeHp = _currentHp;
						_currentHp -= _damage;
						_hpBar->setGaugeOfDamage(_currentHp, _maxHp, _damage, 1);
						_isInvincible = true;
						SOUNDMANAGER->play("will_damaged", 0.6f);
						CAMERAMANAGER->shakeCamera(1.5f, 0.1);
					}
				}
				if (i == 2)
				{
					RECT rcSword = ((golem*)_enemyObject[i][j])->getAttackRc();
					if (IntersectRect(&rcTemp, &_rcBody, &rcSword))
					{
						if (_isInvincible == false)
						{
							_isHit = true;
							_damage = 100;
							_beforeHp = _currentHp;
							_currentHp -= _damage;
							_hpBar->setGaugeOfDamage(_currentHp, _maxHp, _damage, 1);
							_isInvincible = true;
							SOUNDMANAGER->play("will_damaged", 0.6f);
							CAMERAMANAGER->shakeCamera(5.5f, 0.1);
						}
					}
				}
				if (i == 3)
				{
					RECT rcSword = ((boss*)_enemyObject[i][j])->getAttackRc();
					if (IntersectRect(&rcTemp, &_rcBody, &rcSword))
					{
						if (_isInvincible == false)
						{
							_isHit = true;
							_damage = 100;
							_beforeHp = _currentHp;
							_currentHp -= _damage;
							_hpBar->setGaugeOfDamage(_currentHp, _maxHp, _damage, 1);
							_isInvincible = true;
							SOUNDMANAGER->play("will_damaged", 0.6f);
							CAMERAMANAGER->shakeCamera(5.5f, 0.1);
						}
					}
				}
			}
		}
		if (_currentHp <= 0)
		{
			_count = 0;
			_index = 0;
			_isDead = true;
			_isHit = false;
			_isAutomatic = true;
		}
		if (_isEnemyHit && _index == 2 && _isAttacking)
		{
			_isRcSwordOn = false;
		}
	}
	//char str[128];
	//sprintf_s(str, "%d", a);
	//TextOut(getMemDC(), WINSIZEX - 100, 100, str, strlen(str));
}

void player::renderUI()
{
	_inven->render(getMemDC());
	_hpBar->render_jyp();
	numberRender();
	willPendant->frameRender(getMemDC(), 1190, 620);
}

