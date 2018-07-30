#include "stdafx.h"
#include "startScene.h"

HRESULT startScene::init()
{
	

	_doorLeft.img = IMAGEMANAGER->findImage("door_left");
	_doorLeft.pos = tagInt(0, 0);
	_doorRight.img = IMAGEMANAGER->findImage("door_right");
	_doorRight.pos = tagInt(640, 0);

	main_frame = IMAGEMANAGER->findImage("main_frame");
	_logo = IMAGEMANAGER->findImage("logo");
	_count = _index = 0;

	_font = IMAGEMANAGER->findImage("font");
	_isOpen = false;
	_alpha = 0;

	_alphaTime = 0;

	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{

	this->Frame();

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isOpen = true;
		
	}

	if (_isOpen)
	{
		if (_doorLeft.pos.x + _doorLeft.img->getWidth() > 220)
		{
			_doorLeft.pos.x -= 3.0f;
			_doorRight.pos.x += 3.0f;
		}
		
	}
	if (KEYMANAGER->isOnceKeyDown('M'))
	{
		SCENEMANAGER->loadScene("townScene");
	}
	_alphaTime++;
	if (_alphaTime % 5 == 0)
	{
		_alpha++;
		if (_alpha > 255)
			_alpha = 0;
	}
	

}

void startScene::render()
{
	main_frame->frameRender(getMemDC(), 200, 0);
	_doorLeft.img->render(getMemDC(), _doorLeft.pos.x, _doorLeft.pos.y);
	_doorRight.img->render(getMemDC(), _doorRight.pos.x, _doorRight.pos.y);

	_logo->render(getMemDC(), WINSIZEX/2 - _logo->getWidth()/2,100);

	if (!_isOpen)
		_font->alphaRender(getMemDC(), WINSIZEX / 2 - _font->getWidth() / 2, WINSIZEY - 100,_alpha);
}

void startScene::Frame()
{
	_count++;
	if (_count % 10 == 0)
	{
		main_frame->setFrameX(_index);
		_index++;

		if (_index > main_frame->getMaxFrameX())
		{
			_index = 0;

		}
	}

}
