#include "stdafx.h"
#include "loadingDungeonLobby.h"

HRESULT loadingDungeonLobby::init()
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

void loadingDungeonLobby::release()
{
	_loading->release();
	SAFE_DELETE(_loading);

}

void loadingDungeonLobby::update()
{
	_loading->update();
	this->frame();
	//로딩완료후 씬변경

	if (_loading->loadingDone())
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonLobby");
	}

}

void loadingDungeonLobby::render()
{

	//로딩클래스 렌더
	//_loading->render();
	this->textLoading();
	_loadingFrame->frameRender(getMemDC(), WINSIZEX - 100, WINSIZEY - 100);

}

void loadingDungeonLobby::loadingImage()
{

	this->psyDungeonLoading();
	this->lejDungeonLoading();
	this->csyDungeonLoading();
	this->lysDungeonLoading();

}

void loadingDungeonLobby::loadingSound()
{
}

void loadingDungeonLobby::psyDungeonLoading()
{
	//던전 로비
	_loading->loadImage("dunIntro", "./Image/dungeon_object/dungeonLobby_base.bmp", 2460, 2100);
	_loading->loadImage("dunIntroRed", "./Image/dungeon_object/dungeonLobby_redzone.bmp", 2460, 2100);
	_loading->loadFrameImage("dunIntroDoorOpen", "./Image/dungeon_object/dungeonLobby_doorOpen.bmp", 1344, 69, 16, 1);
	_loading->loadFrameImage("dunIntroShowEnterText", "./Image/dungeon_object/dungeonLobby_showEnterText.bmp", 285, 47, 3, 1);
	_loading->loadFrameImage("dunIntroGoInDungeon", "./Image/dungeon_object/dungeonLobby_goInDungeon.bmp", 1764, 97, 21, 1);
	_loading->loadFrameImage("dunIntroGoOutDungeon", "./Image/dungeon_object/dungeonLobby_goOutDungeon.bmp", 4704, 139, 56, 1);


	//던전 오브젝트
	_loading->loadImage("dunIntro", "./Image/dungeon_object/dungeonLobby_base.bmp", 2460, 2100);
	_loading->loadImage("dunIntroRed", "./Image/dungeon_object/dungeonLobby_redzone.bmp", 2460, 2100);

	_loading->loadImage("bottomLeftRock", "Image/dungeon_object/dungeonLobby_bottomLeftRock.bmp", 45, 62, true, MAGENTA);
	_loading->loadImage("bottomRight2Rock", "Image/dungeon_object/dungeonLobby_bottomRight2Rock.bmp", 105, 194, true, MAGENTA);
	_loading->loadImage("middleLeftRock", "Image/dungeon_object/dungeonLobby_middleLeftRock.bmp", 47, 68, true, MAGENTA);
	_loading->loadImage("middleRighttRock", "Image/dungeon_object/dungeonLobby_middleRighttRock.bmp", 61, 91, true, MAGENTA);
	_loading->loadImage("topLeft3Rock", "Image/dungeon_object/dungeonLobby_topLeft3Rock.bmp", 116, 134, true, MAGENTA);
	_loading->loadImage("topRightRock", "Image/dungeon_object/dungeonLobby_topRightRock.bmp", 69, 112, true, MAGENTA);
	_loading->loadImage("entryStructure", "Image/dungeon_object/dungeonLobby_entryStructure.bmp", 531, 234, true, MAGENTA);
	_loading->loadImage("top3LongBoard", "Image/dungeon_object/dungeonLobby_top3LongBoard.bmp", 462, 117, true, MAGENTA);
	_loading->loadImage("bottomLeftTent", "Image/dungeon_object/dungeonLobby_bottomLeftTent.bmp", 248, 235, true, MAGENTA);

}

void loadingDungeonLobby::lejDungeonLoading()
{
}

void loadingDungeonLobby::csyDungeonLoading()
{
}

void loadingDungeonLobby::lysDungeonLoading()
{
}

void loadingDungeonLobby::frame()
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

void loadingDungeonLobby::textLoading()
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
