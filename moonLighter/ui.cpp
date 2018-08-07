#include "stdafx.h"
#include "ui.h"

HRESULT ui::init()
{

	_vol = 1.0f;
	SOUNDMANAGER->playBGM("introBGM", _vol);

	_bookImg = IMAGEMANAGER->findImage("optionBook");
	_selectImg[0] = IMAGEMANAGER->findImage("soundChoice");			//¿Ωæ« ∞Òπ¿Ã∏æÁ º±≈√
	_selectImg[1] = IMAGEMANAGER->findImage("volumeChoice");		//∫º∑˝ ∞Òπ¿Ã ∏æÁ º±≈√
	_soundImg[0] = IMAGEMANAGER->findImage("on");					//¿Ωæ« ø¬
	_soundImg[1] = IMAGEMANAGER->findImage("off");					//¿Ωæ« ø¿«¡
	_inActiveSoundImg[0] = IMAGEMANAGER->findImage("inactiveOn");	//∫Ò»∞º∫ ø¬
	_inActiveSoundImg[1] = IMAGEMANAGER->findImage("inactiveOff");	//∫Ò»∞º∫ ø¿«¡

	_currSound = _soundImg[1];
	_currSelect = _selectImg[0];				//
	_rc[0] = RectMake(400, 365, 100, 46);		//¿Ωæ« ∑∫∆Æ

	for (int i = 0; i < 9; ++i)
	{
		_volRect[i].blockImg = IMAGEMANAGER->findImage("block");
		_volRect[i].rc = RectMake((720) + 30 * i, 440, _volRect[i].blockImg->getWidth(), _volRect[i].blockImg->getHeight());
		_volRect[i].isActive = true;
	}


	_state = uiState::SOUND;
	_isOpen = false;
	_isOn = false;
	

	return S_OK;
}

void ui::release()
{
}

void ui::update()
{
	if (_isOpen)
	{
		switch (_state)
		{
		case uiState::IDLE:
		{
		
		}
			break;
		case uiState::SOUND:
		{
			_currSelect = _selectImg[0];
			_selecPos = tagInt(365, 365);
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				_state = uiState::SOUNDON;
			
			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				_state = uiState::SOUNDOFF;
				

			}
		}
		break;
		case uiState::SOUNDON:
		{
			_currSound = _soundImg[0];
			SOUNDMANAGER->setVolume(1.0);
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				_state = uiState::SOUNDOFF;
				

			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				_state = uiState::SOUNDOFF;
				
			}

			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				_currSound = _inActiveSoundImg[0];
				_state = uiState::VOLUME;
			}
			_isOn = true;
			_onoffPos = tagInt(418, 438);
		}
			break;
		case uiState::SOUNDOFF:
		{
			_currSound = _soundImg[1];
			SOUNDMANAGER->setVolume(0.0);
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				_state = uiState::SOUNDON;

			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				_state = uiState::SOUNDON;

			}
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				_currSound = _inActiveSoundImg[1];
				_state = uiState::VOLUME;
			}
			_onoffPos = tagInt(412, 432);
			_isOn = false;
		}
			break;
		case uiState::VOLUME:
		{
			_currSelect = _selectImg[1];
			_selecPos = tagInt(745, 361);


			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				_vol -= 0.1f;
				SOUNDMANAGER->setVolume(_vol);

				for (int i = 9; i > 0; --i)
				{
					if (_volRect[i].isActive == true)
					{
						_volRect[i].isActive = false;
						break;

					}
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				_vol += 0.1f;
				SOUNDMANAGER->setVolume(_vol);

				for (int i = 0; i < 9; ++i)
				{
					if (_volRect[i].isActive == false)
					{
						_volRect[i].isActive = true;
						break;

					}
				}
			}


			/*if (KEYMANAGER->isOnceKeyDown('6'))
			{
				_vol -= 0.1f;
				SOUNDMANAGER->setVolume(_vol);
			}*/
			//_selecPos = tagInt(365, 365);
		}
		break;
		case uiState::END:
			break;
		default:
			break;
		}
	}
}

void ui::render()
{
 	RECT rc = CAMERAMANAGER->getRenderRc();

	if (_isOpen)
	{

		_bookImg->render(getMemDC(), WINSIZEX / 2 - (_bookImg->getWidth() / 2), WINSIZEY / 2 - (_bookImg->getHeight()/2));
		//Rectangle(getMemDC(), _rc[0]);
		_currSound->render(getMemDC(), _onoffPos.x, _onoffPos.y);
		_currSelect->render(getMemDC(), _selecPos.x, _selecPos.y);

	
		for (int i = 0; i < 9; ++i)
		{
			if (_volRect[i].isActive == true)
			{
				Rectangle(getMemDC(), _volRect[i].rc);
				_volRect[i].blockImg->render(getMemDC(), (720)+ 30  * i, 440);

			}
			
		}

	}



	char str[128];
	sprintf_s(str, "x : %d, y : %d", _ptMouse.x, _ptMouse.y);
	TextOut(getMemDC(), 300, 300, str, strlen(str));
	//char str[128];
	//sprintf_s(str, "vol : %f", _vol);
	//TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));


}
