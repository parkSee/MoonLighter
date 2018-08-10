#include "stdafx.h"
#include "player.h"
#include "inventory.h"


HRESULT player::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);
	_cntPendant = 0;
	_cntIsHit = 0;
	_cntShakeHeart = 0;
	_cntFoot = 0;
	_cntHp[0] = 0;
	_cntHp[1] = 0;
	_cntHp[2] = 0;
	_cntHp[3] = 0;
	_cntHp[4] = 10;
	_cntHp[5] = 0;
	_cntHp[6] = 0;
	_cntHp[7] = 0;
	_cntHp[8] = 0;

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
	_attack = 30;
	_attCharge = 0;
	_maxHp = 1000;
	_currentHp = 1000;
	_beforeHp = _maxHp;
	_isIdle = true;
	_isUp = false;
	_dir = DOWN;
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
	_isShakingHeart = false;
	_isHit = false;
	_isDead = false;
	_isAttacking = false;
	_isRcSwordOn = false;
	_playerMove = true;
	_bow = true;
	_knife = false;
	_cam = CAMERAMANAGER->getRenderRc();

	_UiCount=0;
	_UiCurrentX=0;
	_UiCurrentY=0;
	_UiBool=false;

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
	willMoneyBag = IMAGEMANAGER->findImage("moneyBag");

	willArrow[UP] = IMAGEMANAGER->findImage("윌_화살위");
	willArrow[DOWN] = IMAGEMANAGER->findImage("윌_화살아래");
	willArrow[LEFT] = IMAGEMANAGER->findImage("윌_화살왼쪽");
	willArrow[RIGHT] = IMAGEMANAGER->findImage("윌_화살오른쪽");
	willBowAttack[UP] = IMAGEMANAGER->findImage("will_bow_back");
	willBowAttack[DOWN] = IMAGEMANAGER->findImage("will_bow_front");
	willBowAttack[LEFT] = IMAGEMANAGER->findImage("will_bow_left");
	willBowAttack[RIGHT] = IMAGEMANAGER->findImage("will_bow_right");
	willBowAttackShadow[UP] = IMAGEMANAGER->findImage("will_bow_back_shadow");
	willBowAttackShadow[DOWN] = IMAGEMANAGER->findImage("will_bow_front_shadow");
	willBowAttackShadow[LEFT] = IMAGEMANAGER->findImage("will_bow_left_shadow");
	willBowAttackShadow[RIGHT] = IMAGEMANAGER->findImage("will_bow_right_shadow");
	willBowAttackDamaged[0][UP] = IMAGEMANAGER->findImage("will_bow_back_damaged2");
	willBowAttackDamaged[0][DOWN] = IMAGEMANAGER->findImage("will_bow_front_damaged2");
	willBowAttackDamaged[0][LEFT] = IMAGEMANAGER->findImage("will_bow_left_damaged2");
	willBowAttackDamaged[0][RIGHT] = IMAGEMANAGER->findImage("will_bow_right_damaged2");
	willBowAttackDamaged[1][UP] = IMAGEMANAGER->findImage("will_bow_back_damaged3");
	willBowAttackDamaged[1][DOWN] = IMAGEMANAGER->findImage("will_bow_front_damaged3");
	willBowAttackDamaged[1][LEFT] = IMAGEMANAGER->findImage("will_bow_left_damaged3");
	willBowAttackDamaged[1][RIGHT] = IMAGEMANAGER->findImage("will_bow_right_damaged3");


	weaponUi = IMAGEMANAGER->findImage("weaponUi");

	
	shakeHeart = IMAGEMANAGER->findImage("shakeHeart");
	number = IMAGEMANAGER->findImage("number");
	_hpBar = new progressBar;
	_hpBar->init("will_hpBar", 120, 20, 130, 228, 118, 38);
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

	for (int i = 0; i < 10; ++i)
	{
		_arrow[i].pos.x = 0;
		_arrow[i].pos.y = 0;
		_arrow[i].isActive = false;
		_arrow[i].speed = 3;
		_arrow[i].rc = RectMakeCenter(-5, -5, 2, 2);
	}

	_rcBody = RectMakeCenter(pos.x, pos.y, 50, 70);
	_rcSword = RectMakeCenter(pos.x, pos.y, 100, 100);
	rc = RectMakeCenter(pos.x, pos.y, will->getFrameWidth(), will->getFrameHeight());

	_probeX = pos.x;
	_probeY = pos.y;

	//__camERAMANAGER->connectTarget(pos.x, pos.y);

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

	//__camERAMANAGER->connectTarget(pos.x, pos.y);

	/*
	if (KEYMANAGER->isStayKeyDown('T'))
	{
	__camERAMANAGER->shake__camera(5.0f, 11.0f);
	}
	*/
	_cam = CAMERAMANAGER->getRenderRc();
	_inven->update();

	this->willAction();
	this->enemyCheckCollision();
	_hpBar->update_jyp();
	numberUpdate();
}

void player::render(void)
{
	if (_isAutomatic)
	{
		if (_isDead)
		{
			willDungeonShadow->frameAlphaRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top, 80);
			willDungeon->frameRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top);
		}
	}
	else
	{
		if (!_isAttacking)	//공격모션이 아닐 경우에 출력
		{
			int _count = (int)(_cntIsHit * 0.1);
			
				if (!_isHit)
				{
					willDungeonShadow->frameAlphaRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top, 80);
					willDungeon->frameRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top);
				}
				else
				{
					if (_cntIsHit <= 4)
					{
						willDungeonShadow->frameAlphaRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top, 80);
						willDamaged[1]->frameRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top);
					}
					else if (_cntIsHit <= 8)
					{
						willDungeonShadow->frameAlphaRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top, 80);
						willDamaged[2]->frameRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top);
					}
					else if (8 < _cntIsHit && _count % 2 == 1)
					{

					}
					else if (8 < _cntIsHit && _count % 2 == 0)
					{
						willDungeonShadow->frameAlphaRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top, 80);
						willDungeon->frameRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top);
					}
				}
			
		}
		else if (_isAttacking)    //공격 모션일 경우의 출력
		{
			attackRender();
		}
		arrowRender();
		
	}
	
	if (_isGoingHome)
	{
		if (_index < 15)
		{
			willDungeon->frameRender(getMemDC(), rc.left - _cam.left, rc.top - _cam.top);
		}
		willGoHome->frameRender(getMemDC(), (rc.left - willGoHome->getFrameWidth() / 4 + 5) - _cam.left, (rc.top - willGoHome->getFrameHeight() / 4 + 20) - _cam.top);
	}
	//if (_isWalking)
	//{
	//	willFoot->frameAlphaRender(getMemDC(), footPos.x - _cam.left, footPos.y - _cam.top, 100);
	//}
	if (KEYMANAGER->isToggleKey(VK_F8)) 
	{
		for (int i = 0; i < 0; ++i)
		{
			Rectangle(getMemDC(), _arrow[i].rc.left - _cam.left, _arrow[i].rc.top - _cam.top, _arrow[i].rc.right - _cam.left, _arrow[i].rc.bottom - _cam.top);
		}
	}
	if (KEYMANAGER->isToggleKey(VK_F9))  //lysADD(카메라 렉트 출력)
	{
		Rectangle(getMemDC(), rc.left - _cam.left, rc.top - _cam.top, rc.right - _cam.left, rc.bottom - _cam.top);
	}
	if (KEYMANAGER->isToggleKey(VK_F10))	//lysADD(픽셀충돌체크 렉트 출력)
	{
		Rectangle(getMemDC(), _rcProbe.left - _cam.left, _rcProbe.top - _cam.top, _rcProbe.right - _cam.left, _rcProbe.bottom - _cam.top);
	}
	if (KEYMANAGER->isToggleKey(VK_F11))	//lysADD(아이템토글, 몬스터 충돌 렉트 출력)
	{
		Rectangle(getMemDC(), _rcBody.left - _cam.left, _rcBody.top - _cam.top, _rcBody.right - _cam.left, _rcBody.bottom - _cam.top);
	}
	if (KEYMANAGER->isToggleKey(VK_F12))	//lysADD(공격 모션 중 공격 범위 렉트 출력)
	{
		Rectangle(getMemDC(), _rcSword.left - _cam.left, _rcSword.top - _cam.top, _rcSword.right - _cam.left, _rcSword.bottom - _cam.top);
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
					_dir = RIGHT;
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
					_dir = LEFT;
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
					_dir = UP;
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
					_dir = DOWN;
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
				if (KEYMANAGER->isOnceKeyDown('A') && _knife)		// 칼 공격
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
				if (KEYMANAGER->isOnceKeyDown('W') && _bow)		// 활 공격
				{
					if (_isAttacking == false && _isRolling == false)
					{
						_isEnemyHit = false;
						//_isRcBowOn = true;
						_isAttacking = true;
						_index = 0;
						SOUNDMANAGER->play("will_bowAttack", 0.7f);
						for (int i = 0; i < 10; ++i)
						{
							if (_arrow[i].isActive == false)
							{
								_arrow[i].isActive = true;
								switch (_dir)
								{
									case UP:
										_arrow[i].dir = UP;
										_arrow[i].pos.x = pos.x;
										_arrow[i].pos.y = pos.y;
										_arrow[i].rc = RectMakeCenter(_arrow[i].pos.x, _arrow[i].pos.y, 10, 51);
										break;
									case DOWN:
										_arrow[i].dir = DOWN;
										_arrow[i].pos.x = pos.x;
										_arrow[i].pos.y = pos.y;
										_arrow[i].rc = RectMakeCenter(_arrow[i].pos.x, _arrow[i].pos.y, 10, 51);
										break;
									case LEFT:
										_arrow[i].dir = LEFT;
										_arrow[i].pos.x = pos.x;
										_arrow[i].pos.y = pos.y;
										_arrow[i].rc = RectMakeCenter(_arrow[i].pos.x, _arrow[i].pos.y, 51, 10);
										break;
									case RIGHT:
										_arrow[i].dir = RIGHT;
										_arrow[i].pos.x = pos.x;
										_arrow[i].pos.y = pos.y;
										_arrow[i].rc = RectMakeCenter(_arrow[i].pos.x, _arrow[i].pos.y, 51, 10);
										break;
								}
								break;
							}
						}		
					}
				}
				if (KEYMANAGER->isOnceKeyDown('S'))
				{
					_isHit = true;
					_isShakingHeart = true;
					_cntShakeHeart = 0;
					_damage = 100;
					_beforeHp = _currentHp;
					_currentHp -= _damage;
					_hpBar->setGaugeOfDamage(_currentHp, _maxHp, _damage, 1);
					_money[0] = _money[1];
					_money[1] += 100;
				}
				if (KEYMANAGER->isOnceKeyDown('D'))
				{
					_beforeHp = _currentHp;
					_currentHp += 100;
					if (_currentHp >= _maxHp)
					{
						_currentHp = _maxHp;
					}
					_hpBar->setGaugeOfHeal(_currentHp, _maxHp, 100, 1);
					if (_money[1] >= 100)
					{
						_money[0] = _money[1];
						_money[1] -= 100;
					}
				}
				if (KEYMANAGER->isOnceKeyDown('5'))
				{
					if (_UiBool == false)
					{
						_UiBool = true;
					}
				}

				if (_UiBool)
				{
					_UiCount++;

					if (_UiCount % 5 == 0 && _bow)
					{
						_UiCurrentX++;
						if (_UiCurrentX > weaponUi->getMaxFrameX())
						{
							_UiBool = false;
							_UiCurrentX = 4;
							_UiCount = 0;
							_knife = true;
							_bow = false;
						}
					}
					if (_UiCount % 5 == 0 && _knife)
					{
						_UiCurrentX--;
						if (_UiCurrentX < 0)
						{
							_UiBool = false;
							_UiCurrentX = 0;
							_UiCount = 0;
							_bow = true;
							_knife = false;
						}
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
							setIsIdleUp(false);
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
			else if (_isAttacking == true && _bow)             /////////////////////////활 공격 상태 프레임 업데이트/////////////////////
			{
				bowFrameUpdate();
			}
			else if (_isAttacking == true && _knife)    /////////////////////////칼 공격 상태 프레임 업데이트/////////////////////
			{
				swordFrameUpdate();
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
	if (_isShakingHeart)
	{
		shakeHeart->setFrameX(_cntShakeHeart);
		shakeHeart->setFrameY(0);
		if (_count % 2 == 0)
		{
			++_cntShakeHeart;
			if (_cntShakeHeart > shakeHeart->getMaxFrameX())
			{
				_cntShakeHeart = 0;
				_isShakingHeart = false;
			}
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
	arrowUpdate();
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
			if (_index >= willDungeon->getMaxFrameX() && _hpBar->getCount() <= 0)
			{
				OBJECTMANAGER->reset();
				this->setIsActive(false);
				SCENEMANAGER->loadScene("dungeonLobby");
			}
			else if (_index >= willDungeon->getMaxFrameX())
			{
				_index = willDungeon->getMaxFrameX();
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

void player::swordFrameUpdate()
{
	switch (_dir)
	{
		case UP:
			willAttack->setFrameX(_index);
			willAttack->setFrameY(0);
			willAttackShadow->setFrameX(_index);
			willAttackShadow->setFrameY(0);
			willAttackDamaged[0]->setFrameX(_index);
			willAttackDamaged[0]->setFrameY(0);
			willAttackDamaged[1]->setFrameX(_index);
			willAttackDamaged[1]->setFrameY(0);
			if (2 == _index)
			{
				_rcSword = RectMakeCenter(pos.x, pos.y - 20, 100, 50);
			}
			else
			{
				_rcSword = RectMake(-50, -50, 2, 2);
			}
			break;
		case DOWN:
			willAttack->setFrameX(_index);
			willAttack->setFrameY(1);
			willAttackShadow->setFrameX(_index);
			willAttackShadow->setFrameY(1);
			willAttackDamaged[0]->setFrameX(_index);
			willAttackDamaged[0]->setFrameY(1);
			willAttackDamaged[1]->setFrameX(_index);
			willAttackDamaged[1]->setFrameY(1);
			if (2 == _index)
			{
				_rcSword = RectMakeCenter(pos.x, pos.y + 40, 100, 50);
			}
			else
			{
				_rcSword = RectMake(-50, -50, 2, 2);
			}
			break;
		case RIGHT:
		
			willAttack->setFrameX(_index);
			willAttack->setFrameY(2);
			willAttackShadow->setFrameX(_index);
			willAttackShadow->setFrameY(2);
			willAttackDamaged[0]->setFrameX(_index);
			willAttackDamaged[0]->setFrameY(2);
			willAttackDamaged[1]->setFrameX(_index);
			willAttackDamaged[1]->setFrameY(2);
			if (2 == _index)
			{
				_rcSword = RectMakeCenter(pos.x + 25, pos.y + 25, 80, 100);
			}
			else
			{
				_rcSword = RectMake(-50, -50, 2, 2);
			}
			break;
		case LEFT:
			willAttack->setFrameX(_index);
			willAttack->setFrameY(3);
			willAttackShadow->setFrameX(_index);
			willAttackShadow->setFrameY(3);
			willAttackDamaged[0]->setFrameX(_index);
			willAttackDamaged[0]->setFrameY(3);
			willAttackDamaged[1]->setFrameX(_index);
			willAttackDamaged[1]->setFrameY(3);
			if (2 == _index)
			{
				_rcSword = RectMakeCenter(pos.x - 25, pos.y + 25, 80, 100);
			}
			else
			{
				_rcSword = RectMake(-50, -50, 2, 2);
			}
			break;
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

void player::bowFrameUpdate()
{
	willBowAttack[_dir]->setFrameX(_index);
	willBowAttack[_dir]->setFrameY(1);
	willBowAttackShadow[_dir]->setFrameX(_index);
	willBowAttackShadow[_dir]->setFrameY(1);
	willBowAttackDamaged[0][_dir]->setFrameX(_index);
	willBowAttackDamaged[0][_dir]->setFrameY(1);
	willBowAttackDamaged[1][_dir]->setFrameX(_index);
	willBowAttackDamaged[1][_dir]->setFrameY(1);
	if (_count % 4 == 0)
	{
		++_index;
		switch (_dir)
		{
			case UP:
				if (_index > willBowAttack[_dir]->getMaxFrameX())
				{
					_index = 0;
					_isIdle = true;
					_isAttacking = false;
					//_isUp = true;
				}
				break;
			case DOWN:
				if (_index > willBowAttack[_dir]->getMaxFrameX())
				{
					_index = 0;
					_isIdle = true;
					_isAttacking = false;
					//_isUp = true;
				}
				break;
			case LEFT:
				if (_index > willBowAttack[_dir]->getMaxFrameX())
				{
					_index = 0;
					_isIdle = true;
					_isAttacking = false;
					//_isUp = true;
				}
				break;
			case RIGHT:
				if (_index > willBowAttack[_dir]->getMaxFrameX())
				{
					_index = 0;
					_isIdle = true;
					_isAttacking = false;
					//_isUp = true;
				}
				break;
		}
	}
}

void player::arrowUpdate()
{
	for (int i = 0; i < 10; ++i)
	{
		if (_arrow[i].isActive)
		{
			switch (_arrow[i].dir)
			{
				case UP:
					_arrow[i].pos.y -= _arrow[i].speed;
					_arrow[i].rc = RectMakeCenter(_arrow[i].pos.x, _arrow[i].pos.y, 10, 51);
					if (_arrow[i].rc.bottom < 0)
					{
						_arrow[i].isActive = false;
						_arrow[i].rc = RectMakeCenter(-50, -50, 2, 2);
					}
					break;
				case DOWN:
					_arrow[i].pos.y += _arrow[i].speed;
					_arrow[i].rc = RectMakeCenter(_arrow[i].pos.x, _arrow[i].pos.y, 10, 51);
					if (_arrow[i].rc.top > 3000)
					{
						_arrow[i].isActive = false;
						_arrow[i].rc = RectMakeCenter(-50, -50, 2, 2);
					}
					break;
				case LEFT:
					_arrow[i].pos.x -= _arrow[i].speed;
					_arrow[i].rc = RectMakeCenter(_arrow[i].pos.x, _arrow[i].pos.y, 51, 10);
					if (_arrow[i].rc.right < 0)
					{
						_arrow[i].isActive = false;
						_arrow[i].rc = RectMakeCenter(-50, -50, 2, 2);
					}
					break;
				case RIGHT:
					_arrow[i].pos.x += _arrow[i].speed;
					_arrow[i].rc = RectMakeCenter(_arrow[i].pos.x, _arrow[i].pos.y, 51, 10);
					if (_arrow[i].rc.left > 3000)
					{
						_arrow[i].isActive = false;
						_arrow[i].rc = RectMakeCenter(-50, -50, 2, 2);
					}
					break;
			}
		}
	}
}

void player::attackRender()
{
	int _count = (int)(_cntIsHit * 0.1);
	if (_knife)
	{
		int addX;
		int addY;

		switch (_dir)
		{
		case UP:
			addX = -5;
			addY = -15;
			break;
		case DOWN:
			addX = -5;
			addY = -5;
			break;
		case LEFT:
			addX = -10;
			addY = -15;
			break;
		case RIGHT:
			addX = 5;
			addY = -18;
			break;
		}
		if (!_isHit)
		{
			willAttackShadow->frameAlphaRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top, 80);
			willAttack->frameRender(getMemDC(), rc.left + addX - _cam.left, rc.top - _cam.top);
		}
		else
		{
			if (_cntIsHit <= 4)
			{
				willAttackShadow->frameAlphaRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top, 80);
				willAttackDamaged[0]->frameRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top);
			}
			else if (_cntIsHit <= 8)
			{
				willAttackShadow->frameAlphaRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top, 80);
				willAttackDamaged[1]->frameRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top);
			}
			else if (8 < _cntIsHit && _count % 2 == 1)
			{

			}
			else if (8 < _cntIsHit && _count % 2 == 0)
			{
				willAttackShadow->frameAlphaRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top, 80);
				willAttack->frameRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top);
			}
		}
	}
	else if (_bow)
	{
		int addX;
		int addY;

		switch (_dir)
		{
			case UP:
				addX = 26;
				addY = 8;
				break;
			case DOWN:
				addX = 30;
				addY = 28;
				break;
			case LEFT:
				addX = 3;
				addY = 25;
				break;
			case RIGHT:
				addX = 9;
				addY = 25;
				break;
		}

		if (!_isHit)
		{
			willBowAttackShadow[_dir]->frameAlphaRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top, 80);
			willBowAttack[_dir]->frameRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top);
		}
		else
		{
			if (_cntIsHit <= 4)
			{
				willBowAttackShadow[_dir]->frameAlphaRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top, 80);
				willBowAttackDamaged[0][_dir]->frameRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top);
			}
			else if (_cntIsHit <= 8)
			{
				willBowAttackShadow[_dir]->frameAlphaRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top, 80);
				willBowAttackDamaged[1][_dir]->frameRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top);
			}
			else if (8 < _cntIsHit && _count % 2 == 1)
			{

			}
			else if (8 < _cntIsHit && _count % 2 == 0)
			{
				willBowAttackShadow[_dir]->frameAlphaRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top, 80);
				willBowAttack[_dir]->frameRender(getMemDC(), rc.left + addX - _cam.left, rc.top + addY - _cam.top);
			}
		}
	}
}

void player::arrowRender()
{
	for (int i = 0; i < 10; ++i)
	{
		if (_arrow[i].isActive)
		{
			switch (_arrow[i].dir)
			{
			case UP:
				willArrow[UP]->render(getMemDC(), _arrow[i].pos.x - _cam.left, _arrow[i].pos.y - _cam.top);
				break;
			case DOWN:
				willArrow[DOWN]->render(getMemDC(), _arrow[i].pos.x - _cam.left, _arrow[i].pos.y - _cam.top);
				break;
			case LEFT:
				willArrow[LEFT]->render(getMemDC(), _arrow[i].pos.x - _cam.left, _arrow[i].pos.y - _cam.top);
				break;
			case RIGHT:
				willArrow[RIGHT]->render(getMemDC(), _arrow[i].pos.x - _cam.left, _arrow[i].pos.y - _cam.top);
				break;
			}
		}
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
	if (_index < 15)
	{
		willDungeon->setFrameX(_index);
		willDungeon->setFrameY(11);
	}
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
		number->frameRender(getMemDC(), 160, 55, _cntHp[0], 0);
	}
	for (int i = 1; i < 9; ++i)
	{
		number->frameRender(getMemDC(), 160+(i*10), 55, _cntHp[i], 0);
	}
	
	if (_money[0] >= 1000)
	{
		number->frameRender(getMemDC(), 25, 90, _cntMoney[0], 0);
	}

	for (int i = 1; i < 4; ++i)
	{
		number->frameRender(getMemDC(), 25 + (i * 10), 90, _cntMoney[i], 0);
	}
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
	_hpBar->setGaugeOfHeal(_currentHp, _maxHp, _maxHp, 0.8);
}
int player::getAttack()
{
	return _attack;
}
RECT player::getRcArrow()
{
	return RECT();
}
void player::enemyCheckCollision()
{
	if (_isDead != true)
	{
		RECT rcTemp;
		RECT _camera = CAMERAMANAGER->getRenderRc();
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
						_isShakingHeart = true;
						_cntShakeHeart = 0;
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
							_isShakingHeart = true;
							_cntShakeHeart = 0;
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
							_isShakingHeart = true;
							_cntShakeHeart = 0;
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
			_currentHp = 0;
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
	willMoneyBag->render(getMemDC(), 10, 10);
	IMAGEMANAGER->findImage("coin")->render(getMemDC(), 75, 90);
	shakeHeart->frameRender(getMemDC(), 65, 17);
	willPendant->frameRender(getMemDC(), 1190, 620);
	weaponUi->frameRender(getMemDC(), 1050, 0, _UiCurrentX, _UiCurrentY);
}

