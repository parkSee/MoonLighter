#include "stdafx.h"
#include "AIKidsState.h"
#include "AIKids.h"
void AIKidsState::enter(gameObject * parent, State::Enum state, image * img, image* pixel)
{
	_parent = parent;
	_state = state;
	_img = img;
	_pixel = pixel;

	switch (_state)
	{
	case State::IDLE:
	{

	}
	break;
	case State::LEFT:
	{
		int arryAni[] = { 12,13,14,15,16,17 };
		_ani1 = new animation;
		_ani1->init(_img->getWidth(), _img->getHeight(), 6, 4);
		_ani1->setPlayFrame(arryAni, 6, true);
		_ani1->setFPS(1.0f);
		_ani1->start();
	}
	break;
	case State::RIGHT:
	{
		int arryAni[] = { 18,19,20,21,22,23 };
		_ani1 = new animation;
		_ani1->init(_img->getWidth(), _img->getHeight(), 6, 4);
		_ani1->setPlayFrame(arryAni, 6, true);
		_ani1->setFPS(1.0f);
		_ani1->start();
	}
	break;
	case State::UP:
	{
		int arryAni[] = { 6,7,8,9,10,11 };
		_ani1 = new animation;
		_ani1->init(_img->getWidth(), _img->getHeight(), 6, 4);
		_ani1->setPlayFrame(arryAni, 6, true);
		_ani1->setFPS(1.0f);
		_ani1->start();
	}
	break;
	case State::DOWN:
	{
		int arryAni[] = { 0,1,2,3,4,5 };
		_ani1 = new animation;
		_ani1->init(_img->getWidth(), _img->getHeight(), 6, 4);
		_ani1->setPlayFrame(arryAni, 6, true);
		_ani1->setFPS(1.0f);
		_ani1->start();
	}
	break;
	case State::BUY:
	{

	}
	break;
	case State::END:
	{

	}
	break;
	}


	_vDot.assign(6, tagFloat());

	_vDot[0] = tagFloat(549, 1185);
	_vDot[1] = tagFloat(475, 1185);
	_vDot[2] = tagFloat(405, 1185);
	_vDot[3] = tagFloat(330, 1185);
	_vDot[4] = tagFloat(288, 1161);
	_vDot[5] = tagFloat(288, 1097);

	_currentIndex = 0;
	_maxIndex = 5;
}

void AIKidsState::update()
{
	this->move();

	switch (_state)
	{
	case State::IDLE:
	{

	}
	break;
	case State::LEFT:
	{
		PIXELMANAGER->collision(_img, _pixel, Direction::LEFT, _parent->pos.x, _parent->pos.y);
	}
	break;
	case State::RIGHT:
	{
		PIXELMANAGER->collision(_img, _pixel, Direction::RIGHT, _parent->pos.x, _parent->pos.y);
	}
	break;
	case State::UP:
	{
		_parent->pos.y--;
		PIXELMANAGER->collision(_img, _pixel, Direction::TOP, _parent->pos.x, _parent->pos.y);
	
	}
	break;
	case State::DOWN:
	{
		PIXELMANAGER->collision(_img, _pixel, Direction::BOTTOM, _parent->pos.x, _parent->pos.y);
	}
	break;
	case State::BUY:
	{

	}
	break;
	case State::END:
	{

	}
	break;

	}

	_ani1->frameUpdate(0.1f);
}

void AIKidsState::move()
{
	if (_currentIndex > _vDot.size() + 1)
	{
		_vDot[_currentIndex].x = 288;
		_vDot[_currentIndex].y = 1097;
		return;
	}

	if (getDistance(_parent->pos.x, _parent->pos.y, _vDot[_currentIndex].x, _vDot[_currentIndex].y) < 5)
	{
		if (_currentIndex < _maxIndex)
			_currentIndex++;
		else if (_currentIndex >= _maxIndex)
			_currentIndex = _maxIndex;
	}

	int angle = getAngle(_parent->pos.x, _parent->pos.y, _vDot[_currentIndex].x, _vDot[_currentIndex].y);

	_parent->pos.x += cosf(angle)* 2.0f;
	_parent->pos.y += -sinf(angle)*2.0f;

}

