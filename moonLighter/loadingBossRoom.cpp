#include "stdafx.h"
#include "loadingBossRoom.h"

HRESULT loadingBossRoom::init()
{
	_loading = new loading;
	_loading->init();

	_loadingFrame = IMAGEMANAGER->addFrameImage("loading", "./Image/loading.bmp", 3230, 95, 34, 1, true, MAGENTA);

	//이미지 및 사운드 로딩
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
	//로딩완료후 씬변경

	if (_loading->loadingDone())
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("bossRoomScene");

	}

}

void loadingBossRoom::render()
{
	//로딩클래스 렌더
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

	_loading->loadFrameImage("보스공격이펙트다운오른쪽", "./image/enemy/보스공격이펙트다운오른쪽.bmp", 2816, 256, 11, 1);
	_loading->loadFrameImage("보스공격이펙트다운왼쪽", "./image/enemy/보스공격이펙트다운왼쪽.bmp", 2816, 256, 11, 1);
	_loading->loadFrameImage("보스공격이펙트업왼쪽", "./image/enemy/보스공격이펙트업왼쪽.bmp", 2816, 256, 10, 1);
	_loading->loadFrameImage("보스공격이펙트업오른쪽", "./image/enemy/보스공격이펙트업오른쪽.bmp", 2816, 256, 10, 1);

	_loading->loadFrameImage("보스뒤오른쪽", "./image/enemy/보스뒤오른쪽.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤오른쪽그림자", "./image/enemy/보스뒤오른쪽그림자.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤오른쪽빨강", "./image/enemy/보스뒤오른쪽빨강.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤오른쪽빨강그림자", "./image/enemy/보스뒤오른쪽빨강그림자.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤오른쪽하양", "./image/enemy/보스뒤오른쪽하양.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤오른쪽하양그림자", "./image/enemy/보스뒤오른쪽하양그림자.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤왼쪽", "./image/enemy/보스뒤왼쪽.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤왼쪽그림자", "./image/enemy/보스뒤왼쪽그림자.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤왼쪽빨강", "./image/enemy/보스뒤왼쪽빨강.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤왼쪽빨강그림자", "./image/enemy/보스뒤왼쪽빨강그림자.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤왼쪽하양", "./image/enemy/보스뒤왼쪽하양.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스뒤왼쪽하양그림자", "./image/enemy/보스뒤왼쪽하양그림자.bmp", 23040, 768, 30, 1);

	_loading->loadFrameImage("보스정면왼쪽", "./image/enemy/보스정면왼쪽.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면왼쪽그림자", "./image/enemy/보스정면왼쪽그림자.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면왼쪽빨강", "./image/enemy/보스정면왼쪽빨강.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면왼쪽빨강그림자", "./image/enemy/보스정면왼쪽빨강그림자.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면왼쪽하양", "./image/enemy/보스정면왼쪽하양.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면왼쪽하양그림자", "./image/enemy/보스정면왼쪽하양그림자.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면오른쪽", "./image/enemy/보스정면오른쪽.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면오른쪽그림자", "./image/enemy/보스정면오른쪽그림자.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면오른쪽빨강", "./image/enemy/보스정면오른쪽빨강.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면오른쪽빨강그림자", "./image/enemy/보스정면오른쪽빨강그림자.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면오른쪽하양", "./image/enemy/보스정면오른쪽하양.bmp", 23040, 768, 30, 1);
	_loading->loadFrameImage("보스정면오른쪽하양그림자", "./image/enemy/보스정면오른쪽하양그림자.bmp", 23040, 768, 30, 1);

	_loading->loadFrameImage("보스생성", "./image/enemy/보스생성.bmp", 28416, 768, 37, 1);
	_loading->loadFrameImage("보스생성그림자", "./image/enemy/보스생성그림자.bmp", 28416, 768, 37, 1);



	_loading->loadFrameImage("보스이펙트오른쪽", "./image/enemy/보스이펙트오른쪽.bmp", 61, 68, 1, 1);
	_loading->loadFrameImage("보스이펙트왼쪽", "./image/enemy/보스이펙트왼쪽.bmp", 61, 68, 1, 1);
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
	font = CreateFont(20, 0, 0, 0, 600, false, false, false, HANGEUL_CHARSET, 0, 0, 0, 0, TEXT("DX빨간우체통B"));
	oldFont = (HFONT)SelectObject(getMemDC(), font);

	char str[256];
	strncpy_s(str, "로드중. . .", textIndex);

	RECT textrc = RectMake(WINSIZEX / 2, WINSIZEY - 70, 400, 300);

	DrawText(getMemDC(), str, strlen(str), &textrc, DT_WORDBREAK);

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);
}
