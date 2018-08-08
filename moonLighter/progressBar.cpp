#include "stdafx.h"
#include "progressBar.h"

HRESULT progressBar::init(const char * frontImageKey, const char * backImageKey, int x, int y, int width, int height)
{
	//체력바 위치 초기화
	_x = x;
	_y = y;
	//체력바 가로, 세로길이 초기화
	_width = width;
	_height = height;
	//체력바 렉트 위치 및 크기 초기화
	_rcProgress = RectMake(x, y, width, height);

	//키값으로 이미지이름(~.bmp)으로 바로 초기화
	char frontImage[128];
	char backImage[128];
	//메모리 깔끔하게 밀어주기
	ZeroMemory(frontImage, sizeof(frontImage));
	ZeroMemory(backImage, sizeof(backImage));
	//~.bmp로 만들기
	//키, 파일이름 IMAGEMANAGER->ADDIMAGE("background", "background.bmp",,,,)
	sprintf(frontImage, "%s.bmp", frontImageKey);
	sprintf(backImage, "%s.bmp", backImageKey);

	//체력바 이미지 초기화
	_progressBarFront = IMAGEMANAGER->addImage(frontImageKey, frontImage, x, y, width, height, true, RGB(255, 0, 255));
	_progressBarBack = IMAGEMANAGER->addImage(backImageKey, backImage, x, y, width, height, true, RGB(255, 0, 255));

	return S_OK;
}

HRESULT progressBar::init(const char * imageKey, int x, int y, int imgWidth, int imgHeight, int hpWidth, int hpHeight)  //내가 추가한거
{
	//const char * imageKey, int x, int y, int imgWidth, int imgHeight, int hpWidth, int hpHeight
	//체력바 위치 초기화
	_x = x;
	_y = y;
	//체력바 가로, 세로길이 초기화
	_width = imgWidth;
	_height = imgHeight;
	_hpWidth = hpWidth;
	_beforeHpWidth = hpWidth;
	_currentHpWidth = hpWidth;

	_hpHeight = hpHeight;
	//체력바 렉트 위치 및 크기 초기화
	_rcProgress = RectMake(x, y, imgWidth, imgHeight);

	////키값으로 이미지이름(~.bmp)으로 바로 초기화
	//char image[128];
	////메모리 깔끔하게 밀어주기
	//ZeroMemory(image, sizeof(image));
	////~.bmp로 만들기
	////키, 파일이름, IMAGEMANGER->ADDIMAGE("background", "background.bmp",,,,)
	//sprintf(image, "%s.bmp", imageKey);

	//체력바 이미지 초기화
	//_progressBar = IMAGEMANAGER->addImage(imageKey, image, x, y, imgWidth, imgHeight, true, RGB(255, 0, 255));
	_progressBar = IMAGEMANAGER->findImage(imageKey);
	return S_OK;
}

void progressBar::release(void)
{
}

void progressBar::update(void)
{
	_rcProgress = RectMake(_x, _y, _progressBarBack->getWidth(), _progressBarBack->getHeight());
}

void progressBar::update_jyp(void)
{
	_rcProgress = RectMake(_x + 10, _y, _hpWidth, _hpHeight); //내가 추가한거
	if (_isHit) //쳐맞으면 카운트 시작
	{
		--_count;
		_beforeHpWidth -= _hpDifferential;
		if (_count < 0)
		{
			_isHit = false;
			_beforeHpWidth = _currentHpWidth;
		}
	}
	if (_isHealed)
	{
		--_count;
		_beforeHpWidth += _hpDifferential;
		if (_count < 0)
		{
			_isHealed = false;
			_beforeHpWidth = _currentHpWidth;
		}
	}
}

void progressBar::render(void)
{
	//렌더링 되는 순서에 의해서 렌더가 되니까 피통부터 렌더 시킨다
	_progressBarBack->render(getMemDC(), _rcProgress.left, _y);
	//앞에 보여지는 체력바 이미지
	_progressBarFront->render(getMemDC(), _rcProgress.left, _y,
		0, 0, _width, _progressBarFront->getHeight());
}
//응주오빠가 만든거
void progressBar::renderHeight()
{
	_progressBarBack->render(getMemDC(), _rcProgress.left, _y);
	//앞에 보여지는 체력바 이미지
	_progressBarFront->render(getMemDC(), _rcProgress.left, _y  -_height,
		0,0, _progressBarFront->getWidth(),_height);
}

void progressBar::render_jyp()   	//내가 한거 
{
	if (!_isHit && !_isHealed)
	{
		_progressBar->render(getMemDC(), _x, _y, 0, 0, _progressBar->getWidth(), _hpHeight);
		_progressBar->render(getMemDC(), _rcProgress.left, _y, 10, 38, _beforeHpWidth, _hpHeight);
	}
	else if (_isHealed)
	{
		_progressBar->render(getMemDC(), _x, _y, 0, 0, _progressBar->getWidth(), _hpHeight);

		if (_count > _heal * 0.1 * _speed)
		{
			_progressBar->render(getMemDC(), _rcProgress.left, _y, 10, 76, _beforeHpWidth, _hpHeight);
		}
		else if (_count > _heal * 0.2 * _speed)
		{
			_progressBar->render(getMemDC(), _rcProgress.left, _y, 10, 114, _beforeHpWidth, _hpHeight);
		}
		else if (_count > _heal * 0.4 * _speed)
		{
			_progressBar->render(getMemDC(), _rcProgress.left, _y, 10, 152, _beforeHpWidth, _hpHeight);
		}
		else
		{
			_progressBar->render(getMemDC(), _rcProgress.left, _y, 10, 190, _beforeHpWidth, _hpHeight);
		}
	}
	else if (_isHit)
	{
		_progressBar->render(getMemDC(), _x, _y, 0, 0, _progressBar->getWidth(), _hpHeight);

		if (_count > _damage * 0.4 * _speed)
		{
			_progressBar->render(getMemDC(), _rcProgress.left, _y, 10, 76, _beforeHpWidth, _hpHeight);
		}
		else if (_count > _damage * 0.2 * _speed)
		{
			_progressBar->render(getMemDC(), _rcProgress.left, _y, 10, 114, _beforeHpWidth, _hpHeight);
		}
		else if (_count > _damage * 0.1 * _speed)
		{
			_progressBar->render(getMemDC(), _rcProgress.left, _y, 10, 152, _beforeHpWidth, _hpHeight);
		}
		else
		{
			_progressBar->render(getMemDC(), _rcProgress.left, _y, 10, 190, _beforeHpWidth, _hpHeight);
		}
	}
}

void progressBar::setGauge(float currentHp, float maxHp)
{
	_width = (currentHp / maxHp) * _progressBarBack->getWidth();
}

void progressBar::setHeightGuge(float currentHp, float maxHp)
{
	_height = (currentHp / maxHp) * _progressBarBack->getHeight();
}

void progressBar::setGaugeOfDamage(float currentHp, float maxHp, int damage, float speed)
{
	_isHit = true;
	_speed = speed;
	_damage = damage;
	_count = _damage * _speed;
	_currentHpWidth = (currentHp / maxHp) * _hpWidth;
	_hpDifferential = (_beforeHpWidth - _currentHpWidth) / _count;
}

void progressBar::setGaugeOfHeal(float currentHp, float maxHp, int heal, float speed)
{
	_isHealed = true;
	_speed = speed;
	_heal = heal;
	_count = _heal * _speed;
	_currentHpWidth = (currentHp / maxHp) * _hpWidth;
	_hpDifferential = (_currentHpWidth - _beforeHpWidth) / _count;
}

void progressBar::setRect(int x, int y)
{
	_rcProgress.left = _x + 10;
	_rcProgress.top = _y + y;
	_rcProgress.right = _x + _hpWidth;
	_rcProgress.bottom = _y + _hpHeight;
}
