#include "stdafx.h"
#include "loadingDungeon.h"



HRESULT loadingDungeon::init()
{
	_loading = new loading;
	_loading->init();

	_loadingFrame = IMAGEMANAGER->findImage("loading");
	//IMAGEMANAGER->addFrameImage("loading", "./Image/loading.bmp", 3230, 95, 34, 1, true, MAGENTA);

	//이미지 및 사운드 로딩
	this->loadingImage();
	this->loadingSound();

	_count = _index = 0;
	textCount = textIndex = 0;

	return S_OK;
}

void loadingDungeon::release()
{
	_loading->release();
	SAFE_DELETE(_loading);
}

void loadingDungeon::update()
{
	_loading->update();
	this->frame();
	//로딩완료후 씬변경

	if (_loading->loadingDone())
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonScene");
	}
}

void loadingDungeon::render()
{

	//로딩클래스 렌더
	//_loading->render();
	this->textLoading();
	_loadingFrame->frameRender(getMemDC(), WINSIZEX - 100, WINSIZEY - 100);
}

void loadingDungeon::loadingImage()
{
	this->psyDungeonLoading();
	this->lejDungeonLoading();
	this->csyDungeonLoading();
	this->lysDungeonLoading();
}

void loadingDungeon::loadingSound()
{
	_loading->loadSound("dungeonBGM", "./gameSound/dungeonBGM.mp3", true, true);

	//효과음
	_loading->loadSound("enemy_death", "./gameSound/enemy_death.wav", false, false);
	_loading->loadSound("golem_hit", "./gameSound/golem_hit.wav", false, false);
	_loading->loadSound("slime_hit", "./gameSound/slime_hit.wav", false, false);
	_loading->loadSound("weed_hit", "./gameSound/weed_hit.wav", false, false);
}

void loadingDungeon::psyDungeonLoading()
{

	//던전
	_loading->loadImage("dungeonMap", "./Image/dungeon_object/dungeonMap.bmp", 3840, 2160, true, MAGENTA);
	_loading->loadImage("dungeonRedZone", "./Image/dungeon_object/dungeonMap_redZone.bmp", 3840, 2160, true, MAGENTA);
	_loading->loadImage("bossRoom", "./Image/dungeon_object/bossRoom.bmp", 3152, 2131);
	_loading->loadImage("bossRoomRedZoon", "./Image/dungeon_object/bossRoomRedZoon.bmp", 3152, 2131);

}

void loadingDungeon::lejDungeonLoading()
{
	_loading->loadFrameImage("잡초", "./image/enemy/잡초.bmp", 4200, 90, 60, 1);
	_loading->loadFrameImage("잡초빨강", "./image/enemy/잡초빨강.bmp", 4200, 90, 60, 1);
	_loading->loadFrameImage("잡초하양", "./image/enemy/잡초하양.bmp", 4200, 90, 60, 1);

	_loading->loadFrameImage("잡초그림자", "./image/enemy/잡초그림자.bmp", 4200, 90, 60, 1);
	_loading->loadFrameImage("잡초빨강그림자", "./image/enemy/잡초빨강그림자.bmp", 4200, 90, 60, 1);
	_loading->loadFrameImage("잡초하양그림자", "./image/enemy/잡초하양그림자.bmp", 4200, 90, 60, 1);

	_loading->loadFrameImage("큰슬라임", "./image/enemy/큰슬라임.bmp", 6000, 110, 60, 1);
	_loading->loadFrameImage("큰슬라임빨강", "./image/enemy/큰슬라임빨강.bmp", 6000, 110, 60, 1);
	_loading->loadFrameImage("큰슬라임하양", "./image/enemy/큰슬라임하양.bmp", 6000, 110, 60, 1);

	_loading->loadFrameImage("큰슬라임그림자", "./image/enemy/큰슬라임그림자.bmp", 6000, 110, 60, 1);
	_loading->loadFrameImage("큰슬라임빨강그림자", "./image/enemy/큰슬라임빨강그림자.bmp", 6000, 110, 60, 1);
	_loading->loadFrameImage("큰슬라임하양그림자", "./image/enemy/큰슬라임하양그림자.bmp", 6000, 110, 60, 1);

	_loading->loadFrameImage("작은슬라임", "./image/enemy/작은슬라임.bmp", 3000, 55, 60, 1);
	_loading->loadFrameImage("작은슬라임빨강", "./image/enemy/작은슬라임빨강.bmp", 3000, 55, 60, 1);
	_loading->loadFrameImage("작은슬라임하양", "./image/enemy/작은슬라임하양.bmp", 3000, 55, 60, 1);

	_loading->loadFrameImage("작은슬라임그림자", "./image/enemy/작은슬라임그림자.bmp", 3000, 55, 60, 1);
	_loading->loadFrameImage("작은슬라임빨강그림자", "./image/enemy/작은슬라임빨강그림자.bmp", 3000, 55, 60, 1);
	_loading->loadFrameImage("작은슬라임하양그림자", "./image/enemy/작은슬라임하양그림자.bmp", 3000, 55, 60, 1);


	_loading->loadFrameImage("골렘정면", "./image/enemy/골렘정면.bmp", 4800, 170, 60, 1);
	_loading->loadFrameImage("정면맞는빨강", "./image/enemy/정면맞는빨강.bmp", 4800, 170, 60, 1);
	_loading->loadFrameImage("정면맞는하양", "./image/enemy/정면맞는하양.bmp", 4800, 170, 60, 1);

	_loading->loadFrameImage("골렘정면그림자", "./image/enemy/골렘정면그림자.bmp", 4800, 170, 60, 1);
	_loading->loadFrameImage("정면맞는빨강그림자", "./image/enemy/정면맞는빨강그림자.bmp", 4800, 170, 60, 1);
	_loading->loadFrameImage("정면맞는하양그림자", "./image/enemy/정면맞는하양그림자.bmp", 4800, 170, 60, 1);

	_loading->loadFrameImage("골렘왼쪽", "./image/enemy/골렘왼쪽.bmp", 7800, 125, 60, 1);
	_loading->loadFrameImage("왼쪽맞는빨강", "./image/enemy/왼쪽맞는빨강.bmp", 7800, 125, 60, 1);
	_loading->loadFrameImage("왼쪽맞는하양", "./image/enemy/왼쪽맞는하양.bmp", 7800, 125, 60, 1);

	_loading->loadFrameImage("골렘왼쪽그림자", "./image/enemy/골렘왼쪽그림자.bmp", 7800, 125, 60, 1);
	_loading->loadFrameImage("왼쪽맞는빨강그림자", "./image/enemy/왼쪽맞는빨강그림자.bmp", 7800, 125, 60, 1);
	_loading->loadFrameImage("왼쪽맞는하양그림자", "./image/enemy/왼쪽맞는하양그림자.bmp", 7800, 125, 60, 1);

	_loading->loadFrameImage("골렘오른쪽", "./image/enemy/골렘오른쪽.bmp", 7800, 140, 60, 1);
	_loading->loadFrameImage("오른쪽맞는빨강", "./image/enemy/오른쪽맞는빨강.bmp", 7800, 140, 60, 1);
	_loading->loadFrameImage("오른쪽맞는하양", "./image/enemy/오른쪽맞는하양.bmp", 7800, 140, 60, 1);

	_loading->loadFrameImage("골렘오른쪽그림자", "./image/enemy/골렘오른쪽그림자.bmp", 7800, 140, 60, 1);
	_loading->loadFrameImage("오른쪽맞는빨강그림자", "./image/enemy/오른쪽맞는빨강그림자.bmp", 7800, 140, 60, 1);
	_loading->loadFrameImage("오른쪽맞는하양그림자", "./image/enemy/오른쪽맞는하양그림자.bmp", 7800, 140, 60, 1);

	_loading->loadFrameImage("골렘뒤쪽", "./image/enemy/골렘뒤쪽.bmp", 4800, 140, 60, 1);
	_loading->loadFrameImage("뒤쪽맞는빨강", "./image/enemy/뒤쪽맞는빨강.bmp", 4800, 140, 60, 1);
	_loading->loadFrameImage("뒤쪽맞는하양", "./image/enemy/뒤쪽맞는하양.bmp", 4800, 140, 60, 1);

	_loading->loadFrameImage("골렘뒤쪽그림자", "./image/enemy/골렘뒤쪽그림자.bmp", 4800, 140, 60, 1);
	_loading->loadFrameImage("뒤쪽맞는빨강그림자", "./image/enemy/뒤쪽맞는빨강그림자.bmp", 4800, 140, 60, 1);
	_loading->loadFrameImage("뒤쪽맞는하양그림자", "./image/enemy/뒤쪽맞는하양그림자.bmp", 4800, 140, 60, 1);

	_loading->loadFrameImage("뿅", "./image/enemy/뿅.bmp", 1150, 110, 10, 1);



	_loading->loadFrameImage("검은화면", "./image/enemy/검은화면.bmp", WINSIZEX, WINSIZEY, 1, 1);
	//_loading->loadImage("보스체력", "보스체력.bmp", 1000, 14);
	//_loading->loadImage("보스체력껍데기", "보스체력껍데기.bmp", 1000, 14,true);


	_loading->loadFrameImage("대미지폰트", "./image/enemy/대미지폰트.bmp", 300, 40, 10, 1);
	_loading->loadFrameImage("shopDoor", "./image/shop_object/shopDoor.bmp", 900, 139, 6, 1);

	_loading->loadFrameImage("활쟁이왼쪽", "./image/player/활쟁이왼쪽.bmp", 950, 72, 10, 1);
	_loading->loadFrameImage("활쟁이오른쪽", "./image/player/활쟁이오른쪽.bmp", 850, 73, 10, 1);
	_loading->loadFrameImage("활쟁이위", "./image/player/활쟁이위.bmp", 657, 100, 9, 1);
	_loading->loadFrameImage("활쟁이아래", "./image/player/활쟁이아래.bmp", 603, 87, 9, 1);

	_loading->loadFrameImage("weaponUi", "./image/player/weaponUi.bmp", 800, 231, 4, 1);
	_loading->loadFrameImage("door", "./image/Dungeon/door.bmp", 780, 96, 5, 1);
	_loading->loadFrameImage("door아래", "./image/Dungeon/door아래.bmp", 780, 96, 5, 1);
	_loading->loadFrameImage("door왼쪽", "./image/Dungeon/door왼쪽.bmp", 480, 156, 5, 1);
	_loading->loadFrameImage("door오른쪽", "./image/Dungeon/door오른쪽.bmp", 480, 156, 5, 1);
	_loading->loadFrameImage("보스입구", "./image/Dungeon/보스입구.bmp", 936, 230, 6, 1);
	//_loading->loadFrameImage("뿅", "./image/enemy/뿅.bmp", 1150, 110, 10, 1);
	//IMAGEMANAGER->addFrameImage("뿅", "./image/enemy/뿅.bmp", 1150, 110, 10, 1);

}

void loadingDungeon::csyDungeonLoading()
{
}

void loadingDungeon::lysDungeonLoading()
{
}

void loadingDungeon::frame()
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

void loadingDungeon::textLoading()
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
