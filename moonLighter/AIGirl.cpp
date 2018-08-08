#include "stdafx.h"
#include "AIGirl.h"
#include "display.h"

HRESULT AIGirl::init(string _objName, tagFloat _pos)
{
	gameObject::init(_objName, _pos);

	_state[0] = IMAGEMANAGER->findImage("girl_front_run");
	_state[1] = IMAGEMANAGER->findImage("girl_back_run");
	_state[2] = IMAGEMANAGER->findImage("girl_left_run");
	_state[3] = IMAGEMANAGER->findImage("girl_right_run");

	
	_dp = SAVEDATA->get_display();

	//TODO: 애니메이션 변경 프레임으로 돌리고, 메세지통신
	//this->addCallback("buy",[this](tagMessage msg)
	//{
	//	this->test();
	//});

	_curState = 1;
	_count = _index = 0;
	_currentIndex = 0;
	_maxIndex = 5;
	_buyCount = 0;
	_moveCount = 0;
	_isExit = false;
	_buy = false;
	_pickItem = false;
	_MoveStart = false;

	//===================================  추적 경로 
	_vDot.assign(6, tagFloat());

	_vDot[0] = tagFloat(649, 1185);
	_vDot[1] = tagFloat(549, 1085);
	_vDot[2] = tagFloat(549, 1000);
	_vDot[3] = tagFloat(549, 900);
	_vDot[4] = tagFloat(509, 920);
	_vDot[5] = tagFloat(429, 920);

	rc = RectMakeCenter(pos.x, pos.y, _state[_curState]->getFrameWidth(), _state[_curState]->getFrameHeight());

	

	return S_OK;
}

void AIGirl::release()
{
	

}

void AIGirl::update()
{
	if (_MoveStart)
	{
		gameObject::update();

		this->move();




		this->Frame();
		rc = RectMakeCenter(pos.x, pos.y, _state[_curState]->getFrameWidth(), _state[_curState]->getFrameHeight());
	}
}

void AIGirl::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	_state[_curState]->frameRender(getMemDC(), (pos.x - _state[_curState]->getFrameWidth() / 2) - cam.left, (pos.y - _state[_curState]->getFrameHeight() / 2) - cam.top);

	for (int i = 0; i < _vDot.size(); ++i)
	{
		EllipseMakeCenter(getMemDC(), _vDot[i].x - cam.left, _vDot[i].y - cam.top, 30, 30);
	}

	
		_moveCount++;
	
	char str2[500];
	sprintf(str2, "%d", _moveCount);
	TextOut(getMemDC(), 100, 100, str2, strlen(str2));

}

void AIGirl::Frame()
{
	_count++;
	if (_count % 10 == 0)
	{
		_index++;
		_state[_curState]->setFrameX(0);

		if (_index > _state[_curState]->getMaxFrameX())
		{
			_index = 0;
		}
		_state[_curState]->setFrameX(_index);
	}


}

void AIGirl::move()
{
	if (_currentIndex >= _vDot.size())
	{


		return;
	}

	if (getDistance(pos.x, pos.y, _vDot[_currentIndex].x, _vDot[_currentIndex].y) < 10)
	{
		if (_currentIndex < _maxIndex)
		{
			_currentIndex++;
			if (200 < _moveCount && _moveCount < 300)
			{
				_curState = 2;
			}
			if (430 < _moveCount && _moveCount < 500)
			{
				_curState = 0;
			}
			//else
			//{
			//	_curState = 3;
			//}
			if (500 <= _moveCount && _moveCount < 600)
			{
				_curState = 3;
			}
			
		}
		else if (_currentIndex >= _maxIndex)
		{
			_currentIndex = _maxIndex;

			_buyCount++;
			if (_buyCount < 100 && _buy == false)
			{
				_curState = 0;
			}
			else
			{
				_curState = 3;
			}

			

			if (_buy)
			{
				_curState = 1;
			}


			_index = 0;

			if (_buyCount >= 100)
			{
				if (_pickItem == false) _dp->dp_SetActiveFalse(2);
				_pickItem = true;
				_buyCount = 0;
				if (_isExit == false)
				{
					_currentIndex = 0;
					_vDot[0] = tagFloat(429, 920);
					_vDot[1] = tagFloat(509, 920);
					_vDot[2] = tagFloat(549, 920);
					_vDot[3] = tagFloat(565, 915);
					_vDot[4] = tagFloat(576, 1045);
					_vDot[5] = tagFloat(676, 1000);
					/*
					_vDot[0] = tagFloat(649, 1185);
					_vDot[1] = tagFloat(549, 1085);
					_vDot[2] = tagFloat(549, 1000);
					_vDot[3] = tagFloat(549, 900);
					_vDot[4] = tagFloat(509, 920);
					_vDot[5] = tagFloat(429, 920);
					*/

					_isExit = true;
					_buy = true;
				}
				
				
			}
			
		}
	}
	else
	{
		float angle = getAngle(pos.x, pos.y, _vDot[_currentIndex].x, _vDot[_currentIndex].y);

		pos.x += cosf(angle)* 2.0f;
		pos.y += -sinf(angle)*2.0f;


	}

	if (_isExit)
	{
		if (KEYMANAGER->isOnceKeyDown('7'))
		{
			_dp->subtractDisplay(2);
			_curState = 0;
			_vDot[0] = tagFloat(650, 1045);
			_vDot[1] = tagFloat(650, 1130);
			_vDot[2] = tagFloat(650, 1250);
			_vDot[3] = tagFloat(650, 1350);
			_vDot[4] = tagFloat(650, 1450);
			_vDot[5] = tagFloat(650, 1550);
			_currentIndex = 0;
		}
	}

	

}
