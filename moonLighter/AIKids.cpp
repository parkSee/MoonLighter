#include "stdafx.h"
#include "AIKids.h"

HRESULT AIKids::init(string _objName, tagFloat _pos)
{

	gameObject::init(_objName, _pos);

	_state[0] = IMAGEMANAGER->findImage("guy_front_run");
	_state[1] = IMAGEMANAGER->findImage("guy_back_run");
	_state[2] = IMAGEMANAGER->findImage("guy_left_run");
	_state[3] = IMAGEMANAGER->findImage("guy_right_run");


	//TODO: 애니메이션 변경 프레임으로 돌리고, 메세지통신
	//this->addCallback("buy",[this](tagMessage msg)
	//{
	//	this->test();
	//});

	_curState = 1;
	_count = _index = 0;
	_currentIndex = 0;
	_maxIndex = 5;

	//===================================  추적 경로 
	_vDot.assign(6, tagFloat());

	_vDot[0] = tagFloat(549, 1185);
	_vDot[1] = tagFloat(475, 1185);
	_vDot[2] = tagFloat(405, 1185);
	_vDot[3] = tagFloat(330, 1185);
	_vDot[4] = tagFloat(288, 1161);
	_vDot[5] = tagFloat(288, 1097);

	rc = RectMakeCenter(pos.x, pos.y, _state[_curState]->getFrameWidth(), _state[_curState]->getFrameHeight());

	return S_OK;
}

void AIKids::release()
{


}

void AIKids::update()
{
	gameObject::update();

	this->move();

	switch (_curState)
	{
	case State::FRONT:
	{

		//PIXELMANAGER->collision(_img, _pixelImg, Direction::BOTTOM, pos.x, pos.y);
	}
	break;
	case State::BACK:
	{
		//PIXELMANAGER->collision(_img, _pixelImg, Direction::TOP, pos.x, pos.y);
	}
	break;
	case State::LEFT:
	{
		//	PIXELMANAGER->collision(_img, _pixelImg, Direction::LEFT, pos.x, pos.y);
	}
	break;
	case::State::RIGHT:
	{
		//PIXELMANAGER->collision(_img, _pixelImg, Direction::RIGHT, pos.x, pos.y);
	}
	break;
	case State::BUY:
	{

	}
	break;
	}


	this->Frame();
	rc = RectMakeCenter(pos.x, pos.y, _state[_curState]->getFrameWidth(), _state[_curState]->getFrameHeight());
}

void AIKids::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	_state[_curState]->frameRender(getMemDC(), (pos.x - _state[_curState]->getFrameWidth() / 2) - cam.left, (pos.y - _state[_curState]->getFrameHeight() / 2) - cam.top);

	for (int i = 0; i < _vDot.size(); ++i)
	{
		EllipseMakeCenter(getMemDC(), _vDot[i].x - cam.left, _vDot[i].y - cam.top, 30, 30);
	}


	char str[500];
	//sprintf_s(str, "angle : %f ", angle);
	//TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));


}

void AIKids::Frame()
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

void AIKids::move()
{
	if (_currentIndex >= _vDot.size())
	{


		return;
	}

	if (getDistance(pos.x, pos.y, _vDot[_currentIndex].x, _vDot[_currentIndex].y) < 10)
	{
		if (_currentIndex < _maxIndex)
			_currentIndex++;
		else if (_currentIndex >= _maxIndex)
		{
			_currentIndex = _maxIndex;

			buyCount++;

			_curState = 3;
			_index = 0;

			if (buyCount >= 100)
			{
				buyCount = 0;
				if (_isExit == false)
				{
					_currentIndex = 0;
					_vDot[0] = tagFloat(246, 1049);
					_vDot[1] = tagFloat(246, 960);
					_vDot[2] = tagFloat(341, 915);
					_vDot[3] = tagFloat(465, 915);
					_vDot[4] = tagFloat(562, 957);
					_vDot[5] = tagFloat(576, 1045);

					_isExit = true;
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
		if (KEYMANAGER->isOnceKeyDown('9'))
		{
			_curState = 0;
			_vDot[0] = tagFloat(576, 1045);
			_vDot[1] = tagFloat(576, 1130);
			_vDot[2] = tagFloat(576, 1250);
			_vDot[3] = tagFloat(576, 1350);
			_vDot[4] = tagFloat(576, 1450);
			_vDot[5] = tagFloat(576, 1550);
			_currentIndex = 0;
		}
	}

}

void AIKids::test()
{
	_curState = 2;
}
