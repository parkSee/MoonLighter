#include "stdafx.h"
#include "loadingTown.h"



HRESULT loadingTown::init()
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

void loadingTown::release()
{
	_loading->release();
	SAFE_DELETE(_loading);
}

void loadingTown::update()
{
	_loading->update();
	this->frame();
	//�ε��Ϸ��� ������

	if (_loading->loadingDone())
	{
	//	OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("townScene");

	}
}

void loadingTown::render()
{
	//�ε�Ŭ���� ����
	//_loading->render();
	this->textLoading();
	_loadingFrame->frameRender(getMemDC(), WINSIZEX - 100, WINSIZEY - 100);
}

void loadingTown::loadingImage()
{
	this->psyDungeonLoading();
	this->lejDungeonLoading();
	this->csyDungeonLoading();
	this->lysDungeonLoading();
}

void loadingTown::loadingSound()
{
	_loading->loadSound("townBGM", "./gameSound/townBGM.mp3", true, true);
	_loading->loadSound("shopBGM", "./gameSound/shopBGM.mp3", true, true);
}

void loadingTown::psyDungeonLoading()
{
	//Ÿ���
	_loading->loadImage("map", "./Image/map2.bmp", 3000, 2460);
	_loading->loadImage("redZone", "./Image/town_object/town_pixel3.bmp", 3000, 2460);

	//������Ʈ
	_loading->loadImage("build_Retaile", "./Image/town_object/build_Retaile.bmp", 644, 444, true, RGB(255, 0, 255));
	_loading->loadImage("build_Top1", "./Image/town_object/build_Top1.bmp", 459, 383, true, RGB(255, 0, 255));
	_loading->loadImage("build_Shop", "./Image/town_object/build_Shop.bmp", 648, 508, true, RGB(255, 0, 255));
	_loading->loadImage("build_Enchant", "./Image/town_object/build_Enchant.bmp", 597, 766, true, MAGENTA);
	_loading->loadImage("build_Bottom1", "./Image/town_object/build_Bottom1.bmp", 483, 333, true, MAGENTA);
	_loading->loadImage("build_Bottom2", "./Image/town_object/build_Bottom2.bmp", 345, 383, true, MAGENTA);
	_loading->loadImage("build_Bottom3", "./Image/town_object/build_Bottom3.bmp", 534, 508, true, MAGENTA);
	_loading->loadImage("build_Forge", "./Image/town_object/build_Forge.bmp", 640, 483, true, MAGENTA);
	_loading->loadImage("build_Well", "./Image/town_object/build_Well.bmp", 132, 160, true, MAGENTA);
	_loading->loadImage("build_Board", "./Image/town_object/build_Board.bmp", 204, 134, true, MAGENTA);
	_loading->loadImage("build_fountain", "Image/town_object/build_fountain.bmp", 108, 123, true, MAGENTA);

	_loading->loadFrameImage("tree", "Image/town_object/tree.bmp", 828, 222, 4, 1, true, MAGENTA);

	//NPC
	_loading->loadFrameImage("npc_witch", "./Image/town_object/npc.bmp", 525, 105, 5, 1, true, MAGENTA);
	_loading->loadFrameImage("talking", "./Image/���ϱ�.bmp", 363, 50, 3, 1, true, MAGENTA);
	_loading->loadImage("talkBox", "./Image/�ÿ�test.bmp", 531, 180, true, MAGENTA);

	_loading->loadFrameImage("npc_�伺", "./Image/town_object/forge.bmp", 380, 105, 5, 1, true, MAGENTA);
	_loading->loadImage("�伺_talkBox", "./Image/�̿伺.bmp", 531, 180, true, MAGENTA);

	_loading->loadFrameImage("npc_����", "./Image/town_object/����npc.bmp", 3195, 180, 9, 1, true, MAGENTA);
	_loading->loadImage("����_talkBox", "./Image/������.bmp", 531, 180, true, MAGENTA);

	_loading->loadFrameImage("npc_����", "./Image/town_object/����.bmp", 900, 50, 18, 1, true, MAGENTA);
	_loading->loadImage("����_talkBox", "./Image/ä����.bmp", 531, 180, true, MAGENTA);

	//AI
	_loading->loadImage("AiKids", "Image/ai/AiKids.bmp", 600, 400, true, MAGENTA);

	_loading->loadFrameImage("girl_front_run", "Image/ai/girl_front_run.bmp", 810, 90, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("girl_back_run", "Image/ai/girl_back_run.bmp", 810, 90, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("girl_left_run", "Image/ai/girl_left_run.bmp", 810, 90, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("girl_right_run", "Image/ai/girl_right_run.bmp", 810, 90, 9, 1, true, MAGENTA);

	_loading->loadFrameImage("guy_front_run", "Image/ai/guy_front_run.bmp", 810, 90, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("guy_back_run", "Image/ai/guy_back_run.bmp", 810, 90, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("guy_left_run", "Image/ai/guy_left_run.bmp", 810, 90, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("guy_right_run", "Image/ai/guy_right_run.bmp", 810, 90, 9, 1, true, MAGENTA);

	_loading->loadFrameImage("link_front_run", "Image/ai/link_front_run.bmp", 700, 78, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("link_back_run", "Image/ai/link_back_run.bmp", 700, 78, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("link_left_run", "Image/ai/link_left_run.bmp", 700, 78, 9, 1, true, MAGENTA);
	_loading->loadFrameImage("link_right_run", "Image/ai/link_right_run.bmp", 700, 78, 9, 1, true, MAGENTA);

	//door
	_loading->loadImage("door_left", "Image/door_left.bmp", 640, 737, true, MAGENTA);
	_loading->loadImage("door_right", "Image/door_right.bmp", 640, 737, true, MAGENTA);

	//mainFrame
	_loading->loadFrameImage("main_frame", "Image/main_frame.bmp", 14080, 720, 16, 1, true, MAGENTA);

	//logo
	_loading->loadImage("logo", "Image/logo.bmp", 400, 325, true, MAGENTA);

	
}

void loadingTown::lejDungeonLoading()
{
	_loading->loadFrameImage("weaponUi", "./image/player/weaponUi.bmp", 800, 231, 4, 1);
}

void loadingTown::csyDungeonLoading()
{
	// �� ������ �� �̹��� (����(�������) ����, ��������,��ü ������, ö��, ���� ����, ���� ��)
	_loading->loadImage("potion", "./Image/item_object/item_potion.bmp", 36, 36, true, MAGENTA);
	_loading->loadImage("twig", "./Image/item_object/item_twig.bmp", 36, 36, true, MAGENTA);
	_loading->loadImage("liquidItem", "./Image/item_object/item_liquidItem.bmp", 36, 36, true, MAGENTA);
	_loading->loadImage("rebar", "./Image/item_object/item_rebar.bmp", 36, 36, true, MAGENTA);
	_loading->loadImage("redCristal", "./Image/item_object/item_redCristal.bmp", 36, 36, true, MAGENTA);
	_loading->loadImage("golemCore", "./Image/item_object/item_golemCore.bmp", 36, 36, true, MAGENTA);

	_loading->loadImage("inventory", "./Image/inventory_ui/inventory.bmp", 1000, 512, true, MAGENTA);
	_loading->loadImage("invenSlot", "./Image/inventory_ui/invenSlot.bmp", 68, 68, true, MAGENTA);

	_loading->loadFrameImage("ui_DP", "./Image/shop_object/ui_onDP.bmp", 310, 50, 3, 1, true, MAGENTA);
	_loading->loadFrameImage("cash_register", "./Image/shop_object/cash_register.bmp", 704, 64, 11, 1, true, MAGENTA);
	_loading->loadFrameImage("visitor_face", "./Image/ai/visitor_face.bmp", 256, 32, 8, 1, true, MAGENTA);

	_loading->loadImage("shopDownLayer", "./Image/shop_object/shopDownLayer.bmp", 184, 88, true, MAGENTA);
}

void loadingTown::lysDungeonLoading()
{
}

void loadingTown::frame()
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

void loadingTown::textLoading()
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
