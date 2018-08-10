#include "stdafx.h"
#include "loadingBossRoom.h"

HRESULT loadingBossRoom::init()
{
	_loading = new loading;
	_loading->init();

	_loadingFrame = IMAGEMANAGER->addFrameImage("loading", "./Image/loading.bmp", 3230, 95, 34, 1, true, MAGENTA);

	//�̹��� �� ���� �ε�
	this->loadingImage();
	this->loadingSound();

	_count = _index = 0;
	textCount = textIndex = 0;



	return S_OK;
}

void loadingBossRoom::release()
{
	_loading->release();
	SAFE_DELETE(_loading);
}

void loadingBossRoom::update()
{
	_loading->update();
	this->frame();
	//�ε��Ϸ��� ������

	if (_loading->loadingDone())
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("bossRoomScene");

	}

}

void loadingBossRoom::render()
{
	//�ε�Ŭ���� ����
	//_loading->render();
	this->textLoading();
	_loadingFrame->frameRender(getMemDC(), WINSIZEX - 100, WINSIZEY - 100);
}

void loadingBossRoom::loadingImage()
{
	this->psyDungeonLoading();
	this->lejDungeonLoading();
	this->csyDungeonLoading();
	this->lysDungeonLoading();
}

void loadingBossRoom::loadingSound()
{
}

void loadingBossRoom::psyDungeonLoading()
{
}

void loadingBossRoom::lejDungeonLoading()
{

	_loading->loadFrameImage("������������Ʈ�ٿ������", "./image/enemy/������������Ʈ�ٿ������.bmp", 2816, 256, 11, 1);
	_loading->loadFrameImage("������������Ʈ�ٿ����", "./image/enemy/������������Ʈ�ٿ����.bmp", 2816, 256, 11, 1);
	_loading->loadFrameImage("������������Ʈ������", "./image/enemy/������������Ʈ������.bmp", 2816, 256, 10, 1);
	_loading->loadFrameImage("������������Ʈ��������", "./image/enemy/������������Ʈ��������.bmp", 2816, 256, 10, 1);

	_loading->loadFrameImage("�����ڿ�����", "./image/enemy/�����ڿ�����.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ����ʱ׸���", "./image/enemy/�����ڿ����ʱ׸���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ����ʻ���", "./image/enemy/�����ڿ����ʻ���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ����ʻ����׸���", "./image/enemy/�����ڿ����ʻ����׸���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ������Ͼ�", "./image/enemy/�����ڿ������Ͼ�.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ������Ͼ�׸���", "./image/enemy/�����ڿ������Ͼ�׸���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ���", "./image/enemy/�����ڿ���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ��ʱ׸���", "./image/enemy/�����ڿ��ʱ׸���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ��ʻ���", "./image/enemy/�����ڿ��ʻ���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ��ʻ����׸���", "./image/enemy/�����ڿ��ʻ����׸���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ����Ͼ�", "./image/enemy/�����ڿ����Ͼ�.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�����ڿ����Ͼ�׸���", "./image/enemy/�����ڿ����Ͼ�׸���.bmp", 23040, 768, 30, 1);

	_loading->loadFrameImage("�����������", "./image/enemy/�����������.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("����������ʱ׸���", "./image/enemy/����������ʱ׸���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("����������ʻ���", "./image/enemy/����������ʻ���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("����������ʻ����׸���", "./image/enemy/����������ʻ����׸���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("������������Ͼ�", "./image/enemy/������������Ͼ�.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("������������Ͼ�׸���", "./image/enemy/������������Ͼ�׸���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("�������������", "./image/enemy/�������������.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("������������ʱ׸���", "./image/enemy/������������ʱ׸���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("������������ʻ���", "./image/enemy/������������ʻ���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("������������ʻ����׸���", "./image/enemy/������������ʻ����׸���.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("��������������Ͼ�", "./image/enemy/��������������Ͼ�.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("��������������Ͼ�׸���", "./image/enemy/��������������Ͼ�׸���.bmp", 23040, 768, 30, 1);

	_loading->loadFrameImage("��������", "./image/enemy/��������.bmp", 28416, 768, 37, 1);
	_loading->loadFrameImage("���������׸���", "./image/enemy/���������׸���.bmp", 28416, 768, 37, 1);



	_loading->loadFrameImage("��������Ʈ������", "./image/enemy/��������Ʈ������.bmp", 61, 68, 1, 1);
	_loading->loadFrameImage("��������Ʈ����", "./image/enemy/��������Ʈ����.bmp", 61, 68, 1, 1);
}

void loadingBossRoom::csyDungeonLoading()
{
}

void loadingBossRoom::lysDungeonLoading()
{
}

void loadingBossRoom::frame()
{
	_count++;
	if (_count % 5 == 0)
	{
		_loadingFrame->setFrameX(_index);
		_index++;

		if (_index >_loadingFrame->getMaxFrameX())
		{
			_index = 0;

		}
	}
}

void loadingBossRoom::textLoading()
{
	textCount = (textCount + 1) % 20;
	if (textCount == 0)
	{
		textIndex += 2;
		if (textIndex > 15)
		{
			textIndex = 0;
		}
	}

	SetTextColor(getMemDC(), RGB(255, 255, 255));
	HFONT font;
	HFONT oldFont;
	font = CreateFont(20, 0, 0, 0, 600, false, false, false, HANGEUL_CHARSET, 0, 0, 0, 0, TEXT("DX������ü��B"));
	oldFont = (HFONT)SelectObject(getMemDC(), font);

	char str[256];
	strncpy_s(str, "�ε���. . .", textIndex);

	RECT textrc = RectMake(WINSIZEX / 2, WINSIZEY - 70, 400, 300);

	DrawText(getMemDC(), str, strlen(str), &textrc, DT_WORDBREAK);

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);
}
