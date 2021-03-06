#include "stdafx.h"
#include "startScene.h"
#include "display.h"

HRESULT startScene::init()
{

	_doorLeft.img = IMAGEMANAGER->findImage("door_left");
	_doorLeft.pos = tagInt(0, 0);
	_doorRight.img = IMAGEMANAGER->findImage("door_right");
	_doorRight.pos = tagInt(640, 0);

	main_frame = IMAGEMANAGER->findImage("main_frame");
	_logo = IMAGEMANAGER->findImage("logo");
	_count = _index = 0;

	_aniKeyFont = IMAGEMANAGER->findImage("aniKey");
	_startFont = IMAGEMANAGER->findImage("start");
	_optionFont = IMAGEMANAGER->findImage("option");
	_exitFont = IMAGEMANAGER->findImage("exit");
	_selectImg = IMAGEMANAGER->findImage("select");
	_selectPos = tagInt(WINSIZEX / 2 - _selectImg->getWidth() / 2, WINSIZEY - 200);

	_ui = new ui;
	_ui->init();
	
	_isOpen = false;
	_alpha = 0;

	_alphaTime = 0;
	

	player* _player;
	_player = new player;
	_player->init("player", tagFloat(0, 0));
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);

	_display = new display;
	_display->init();


	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{

	this->Frame();
	
	//���� ������ Ű
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isOpen = true;
	}


	if (_ui->getIsOpen() == false)
	{
		//���� ����Ű��
		if ((_selectPos.x == WINSIZEX / 2 - _selectImg->getWidth() / 2) && _selectPos.y == WINSIZEY - 200)
		{

			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				SOUNDMANAGER->stop("introBGM");
				SAVEDATA->setVolume(_ui->getVolume());
				SAVEDATA->setEffectVolume(_ui->getEffectVol());
				SAVEDATA->set_display(_display);
				SCENEMANAGER->loadScene("townScene");
			}


			

		}
		else if (_selectPos.y == WINSIZEY - 150)
		{
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				_ui->setIsOpen(true);

			}
		}
		else if (_selectPos.y == WINSIZEY - 100)
		{
			if (KEYMANAGER->isOnceKeyDown('Z'))
				exit(0);
		}
	}
	if (_ui->getIsOpen())
		_ui->update();
	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		_ui->setIsOpen(false);
	}

	if (_isOpen)
	{
		if (_doorLeft.pos.x + _doorLeft.img->getWidth() > 220)
		{
			_doorLeft.pos.x -= 3.0f;
			_doorRight.pos.x += 3.0f;
		}
		if (_ui->getIsOpen() == false)
		{
			//���߿� _isOpen������ �ű��
			//���� ���� Ű��
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				_selectPos.y += 50;
				if (_selectPos.y > 650)
					_selectPos.y = WINSIZEY - 200;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				_selectPos.y -= 50;
				if (_selectPos.y < 520)
					_selectPos.y = WINSIZEY - 100;
			}
		}
	}
	_alphaTime++;
	if (_alphaTime % 5 == 0)
	{
		_alpha+= 5;
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
		_aniKeyFont->alphaRender(getMemDC(), WINSIZEX / 2 - _aniKeyFont->getWidth() / 2, WINSIZEY - 100,_alpha);
	else
	{
		_startFont->render(getMemDC(), WINSIZEX / 2 - _startFont->getWidth() / 2, WINSIZEY - 200);
		_optionFont->render(getMemDC(), WINSIZEX / 2 - _optionFont->getWidth() / 2, WINSIZEY - 150);
		_exitFont->render(getMemDC(), WINSIZEX / 2 - _exitFont->getWidth() / 2, WINSIZEY - 100);
		_selectImg->render(getMemDC(),_selectPos.x,_selectPos.y);

	}

	_ui->render();


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
