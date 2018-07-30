#include "stdafx.h"
#include "AIKids.h"

HRESULT AIKids::init(string _objName, tagFloat _pos, image * imgName)
{

	gameObject::init(_objName, _pos);

	_img = imgName;

	_state = new AIKidsState;
	_state->enter(this, State::UP, IMAGEMANAGER->findImage("AiKids"), IMAGEMANAGER->findImage("shopPixel"));

	this->rc = RectMakeCenter(pos.x, pos.y, _state->_ani1->getFrameWidth(), _state->_ani1->getFrameHeight());

	return S_OK;
}

void AIKids::release()
{
	SAFE_DELETE(_state);
}

void AIKids::update()
{
	_state->update();

	this->rc = RectMakeCenter(pos.x, pos.y, _state->_ani1->getFrameWidth(), _state->_ani1->getFrameHeight());

}

void AIKids::render()
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	_img->aniRender(getMemDC(), (pos.x - _state->_ani1->getFrameWidth() / 2) - cam.left, (pos.y - _state->_ani1->getFrameHeight() / 2) - cam.top, _state->_ani1);

	for (int i = 0; i < _state->_vDot.size(); ++i)
	{
		EllipseMakeCenter(getMemDC(), _state->_vDot[i].x - cam.left, _state->_vDot[i].y - cam.top, 30, 30);
	}

}
