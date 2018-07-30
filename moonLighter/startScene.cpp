#include "stdafx.h"
#include "startScene.h"

HRESULT startScene::init()
{
	/*_door_leftImg = IMAGEMANAGER->findImage("door_left");
	_door_rightImg = IMAGEMANAGER->findImage("door_right");*/

	_doorLeft.img = IMAGEMANAGER->findImage("door_left");
	_doorLeft.pos = tagInt(0, 0);
	_doorRight.img = IMAGEMANAGER->findImage("door_right");
	_doorRight.pos = tagInt(640, 0);

	main_frame = IMAGEMANAGER->findImage("main_frame");
	_count = _index = 0;
	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{

	this->Frame();
}

void startScene::render()
{
	_doorLeft.img->render(getMemDC(), _doorLeft.pos.x, _doorLeft.pos.y);
	_doorRight.img->render(getMemDC(), _doorRight.pos.x, _doorRight.pos.y);

	main_frame->frameRender(getMemDC(), 200, 0);
}

void startScene::Frame()
{
	_count++;
	if (_count % 7 == 0)
	{
		main_frame->setFrameX(_index);
		_index++;

		if (_index > main_frame->getMaxFrameX())
		{
			_index = 0;

		}
	}

}
