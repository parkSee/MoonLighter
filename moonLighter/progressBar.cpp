#include "stdafx.h"
#include "progressBar.h"

HRESULT progressBar::init(const char * frontImageKey, const char * backImageKey, int x, int y, int width, int height)
{
	//ü�¹� ��ġ �ʱ�ȭ
	_x = x;
	_y = y;
	//ü�¹� ����, ���α��� �ʱ�ȭ
	_width = width;
	_height = height;
	//ü�¹� ��Ʈ ��ġ �� ũ�� �ʱ�ȭ
	_rcProgress = RectMake(x, y, width, height);

	//Ű������ �̹����̸�(~.bmp)���� �ٷ� �ʱ�ȭ
	char frontImage[128];
	char backImage[128];
	//�޸� ����ϰ� �о��ֱ�
	ZeroMemory(frontImage, sizeof(frontImage));
	ZeroMemory(backImage, sizeof(backImage));
	//~.bmp�� �����
	//Ű, �����̸� IMAGEMANAGER->ADDIMAGE("background", "background.bmp",,,,)
	sprintf(frontImage, "%s.bmp", frontImageKey);
	sprintf(backImage, "%s.bmp", backImageKey);

	//ü�¹� �̹��� �ʱ�ȭ
	_progressBarFront = IMAGEMANAGER->addImage(frontImageKey, frontImage, x, y, width, height, true, RGB(255, 0, 255));
	_progressBarBack = IMAGEMANAGER->addImage(backImageKey, backImage, x, y, width, height, true, RGB(255, 0, 255));

	return S_OK;
}

HRESULT progressBar::init(const char * imageKey, int x, int y, int imgWidth, int imgHeight, int hpWidth, int hpHeight)  //���� �߰��Ѱ�
{
	//const char * imageKey, int x, int y, int imgWidth, int imgHeight, int hpWidth, int hpHeight
	//ü�¹� ��ġ �ʱ�ȭ
	_x = x;
	_y = y;
	//ü�¹� ����, ���α��� �ʱ�ȭ
	_width = imgWidth;
	_height = imgHeight;
	_hpWidth = hpWidth;
	_beforeHpWidth = hpWidth;
	_currentHpWidth = hpWidth;

	_hpHeight = hpHeight;
	//ü�¹� ��Ʈ ��ġ �� ũ�� �ʱ�ȭ
	_rcProgress = RectMake(x, y, imgWidth, imgHeight);

	////Ű������ �̹����̸�(~.bmp)���� �ٷ� �ʱ�ȭ
	//char image[128];
	////�޸� ����ϰ� �о��ֱ�
	//ZeroMemory(image, sizeof(image));
	////~.bmp�� �����
	////Ű, �����̸�, IMAGEMANGER->ADDIMAGE("background", "background.bmp",,,,)
	//sprintf(image, "%s.bmp", imageKey);

	//ü�¹� �̹��� �ʱ�ȭ
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
	_rcProgress = RectMake(_x + 10, _y, _hpWidth, _hpHeight); //���� �߰��Ѱ�
	if (_isHit) //�ĸ����� ī��Ʈ ����
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
	//������ �Ǵ� ������ ���ؼ� ������ �Ǵϱ� ������� ���� ��Ų��
	_progressBarBack->render(getMemDC(), _rcProgress.left, _y);
	//�տ� �������� ü�¹� �̹���
	_progressBarFront->render(getMemDC(), _rcProgress.left, _y,
		0, 0, _width, _progressBarFront->getHeight());
}
//���ֿ����� �����
void progressBar::renderHeight()
{
	_progressBarBack->render(getMemDC(), _rcProgress.left, _y);
	//�տ� �������� ü�¹� �̹���
	_progressBarFront->render(getMemDC(), _rcProgress.left, _y  -_height,
		0,0, _progressBarFront->getWidth(),_height);
}

void progressBar::render_jyp()   	//���� �Ѱ� 
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
