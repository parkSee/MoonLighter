#include "stdafx.h"
#include "loadingDungeon.h"



HRESULT loadingDungeon::init()
{
	_loading = new loading;
	_loading->init();

	_loadingFrame = IMAGEMANAGER->findImage("loading");
	//IMAGEMANAGER->addFrameImage("loading", "./Image/loading.bmp", 3230, 95, 34, 1, true, MAGENTA);

	//�̹��� �� ���� �ε�
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
	//�ε��Ϸ��� ������

	if (_loading->loadingDone())
	{
		OBJECTMANAGER->reset();
		SCENEMANAGER->loadScene("dungeonScene");
	}
}

void loadingDungeon::render()
{

	//�ε�Ŭ���� ����
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

	//ȿ����
	_loading->loadSound("enemy_death", "./gameSound/enemy_death.wav", false, false);
	_loading->loadSound("golem_hit", "./gameSound/golem_hit.wav", false, false);
	_loading->loadSound("slime_hit", "./gameSound/slime_hit.wav", false, false);
	_loading->loadSound("weed_hit", "./gameSound/weed_hit.wav", false, false);
}

void loadingDungeon::psyDungeonLoading()
{

	//����
	_loading->loadImage("dungeonMap", "./Image/dungeon_object/dungeonMap.bmp", 3840, 2160, true, MAGENTA);
	_loading->loadImage("dungeonRedZone", "./Image/dungeon_object/dungeonMap_redZone.bmp", 3840, 2160, true, MAGENTA);
	_loading->loadImage("bossRoom", "./Image/dungeon_object/bossRoom.bmp", 3152, 2131);
	_loading->loadImage("bossRoomRedZoon", "./Image/dungeon_object/bossRoomRedZoon.bmp", 3152, 2131);

}

void loadingDungeon::lejDungeonLoading()
{
	_loading->loadFrameImage("����", "./image/enemy/����.bmp", 4200, 90, 60, 1);
	_loading->loadFrameImage("���ʻ���", "./image/enemy/���ʻ���.bmp", 4200, 90, 60, 1);
	_loading->loadFrameImage("�����Ͼ�", "./image/enemy/�����Ͼ�.bmp", 4200, 90, 60, 1);

	_loading->loadFrameImage("���ʱ׸���", "./image/enemy/���ʱ׸���.bmp", 4200, 90, 60, 1);
	_loading->loadFrameImage("���ʻ����׸���", "./image/enemy/���ʻ����׸���.bmp", 4200, 90, 60, 1);
	_loading->loadFrameImage("�����Ͼ�׸���", "./image/enemy/�����Ͼ�׸���.bmp", 4200, 90, 60, 1);

	_loading->loadFrameImage("ū������", "./image/enemy/ū������.bmp", 6000, 110, 60, 1);
	_loading->loadFrameImage("ū�����ӻ���", "./image/enemy/ū�����ӻ���.bmp", 6000, 110, 60, 1);
	_loading->loadFrameImage("ū�������Ͼ�", "./image/enemy/ū�������Ͼ�.bmp", 6000, 110, 60, 1);

	_loading->loadFrameImage("ū�����ӱ׸���", "./image/enemy/ū�����ӱ׸���.bmp", 6000, 110, 60, 1);
	_loading->loadFrameImage("ū�����ӻ����׸���", "./image/enemy/ū�����ӻ����׸���.bmp", 6000, 110, 60, 1);
	_loading->loadFrameImage("ū�������Ͼ�׸���", "./image/enemy/ū�������Ͼ�׸���.bmp", 6000, 110, 60, 1);

	_loading->loadFrameImage("����������", "./image/enemy/����������.bmp", 3000, 55, 60, 1);
	_loading->loadFrameImage("���������ӻ���", "./image/enemy/���������ӻ���.bmp", 3000, 55, 60, 1);
	_loading->loadFrameImage("�����������Ͼ�", "./image/enemy/�����������Ͼ�.bmp", 3000, 55, 60, 1);

	_loading->loadFrameImage("���������ӱ׸���", "./image/enemy/���������ӱ׸���.bmp", 3000, 55, 60, 1);
	_loading->loadFrameImage("���������ӻ����׸���", "./image/enemy/���������ӻ����׸���.bmp", 3000, 55, 60, 1);
	_loading->loadFrameImage("�����������Ͼ�׸���", "./image/enemy/�����������Ͼ�׸���.bmp", 3000, 55, 60, 1);


	_loading->loadFrameImage("������", "./image/enemy/������.bmp", 4800, 170, 60, 1);
	_loading->loadFrameImage("����´»���", "./image/enemy/����´»���.bmp", 4800, 170, 60, 1);
	_loading->loadFrameImage("����´��Ͼ�", "./image/enemy/����´��Ͼ�.bmp", 4800, 170, 60, 1);

	_loading->loadFrameImage("������׸���", "./image/enemy/������׸���.bmp", 4800, 170, 60, 1);
	_loading->loadFrameImage("����´»����׸���", "./image/enemy/����´»����׸���.bmp", 4800, 170, 60, 1);
	_loading->loadFrameImage("����´��Ͼ�׸���", "./image/enemy/����´��Ͼ�׸���.bmp", 4800, 170, 60, 1);

	_loading->loadFrameImage("�񷽿���", "./image/enemy/�񷽿���.bmp", 7800, 125, 60, 1);
	_loading->loadFrameImage("���ʸ´»���", "./image/enemy/���ʸ´»���.bmp", 7800, 125, 60, 1);
	_loading->loadFrameImage("���ʸ´��Ͼ�", "./image/enemy/���ʸ´��Ͼ�.bmp", 7800, 125, 60, 1);

	_loading->loadFrameImage("�񷽿��ʱ׸���", "./image/enemy/�񷽿��ʱ׸���.bmp", 7800, 125, 60, 1);
	_loading->loadFrameImage("���ʸ´»����׸���", "./image/enemy/���ʸ´»����׸���.bmp", 7800, 125, 60, 1);
	_loading->loadFrameImage("���ʸ´��Ͼ�׸���", "./image/enemy/���ʸ´��Ͼ�׸���.bmp", 7800, 125, 60, 1);

	_loading->loadFrameImage("�񷽿�����", "./image/enemy/�񷽿�����.bmp", 7800, 140, 60, 1);
	_loading->loadFrameImage("�����ʸ´»���", "./image/enemy/�����ʸ´»���.bmp", 7800, 140, 60, 1);
	_loading->loadFrameImage("�����ʸ´��Ͼ�", "./image/enemy/�����ʸ´��Ͼ�.bmp", 7800, 140, 60, 1);

	_loading->loadFrameImage("�񷽿����ʱ׸���", "./image/enemy/�񷽿����ʱ׸���.bmp", 7800, 140, 60, 1);
	_loading->loadFrameImage("�����ʸ´»����׸���", "./image/enemy/�����ʸ´»����׸���.bmp", 7800, 140, 60, 1);
	_loading->loadFrameImage("�����ʸ´��Ͼ�׸���", "./image/enemy/�����ʸ´��Ͼ�׸���.bmp", 7800, 140, 60, 1);

	_loading->loadFrameImage("�񷽵���", "./image/enemy/�񷽵���.bmp", 4800, 140, 60, 1);
	_loading->loadFrameImage("���ʸ´»���", "./image/enemy/���ʸ´»���.bmp", 4800, 140, 60, 1);
	_loading->loadFrameImage("���ʸ´��Ͼ�", "./image/enemy/���ʸ´��Ͼ�.bmp", 4800, 140, 60, 1);

	_loading->loadFrameImage("�񷽵��ʱ׸���", "./image/enemy/�񷽵��ʱ׸���.bmp", 4800, 140, 60, 1);
	_loading->loadFrameImage("���ʸ´»����׸���", "./image/enemy/���ʸ´»����׸���.bmp", 4800, 140, 60, 1);
	_loading->loadFrameImage("���ʸ´��Ͼ�׸���", "./image/enemy/���ʸ´��Ͼ�׸���.bmp", 4800, 140, 60, 1);

	_loading->loadFrameImage("��", "./image/enemy/��.bmp", 1150, 110, 10, 1);



	_loading->loadFrameImage("����ȭ��", "./image/enemy/����ȭ��.bmp", WINSIZEX, WINSIZEY, 1, 1);
	//_loading->loadImage("����ü��", "����ü��.bmp", 1000, 14);
	//_loading->loadImage("����ü�²�����", "����ü�²�����.bmp", 1000, 14,true);


	_loading->loadFrameImage("�������Ʈ", "./image/enemy/�������Ʈ.bmp", 300, 40, 10, 1);
	_loading->loadFrameImage("shopDoor", "./image/shop_object/shopDoor.bmp", 900, 139, 6, 1);

	_loading->loadFrameImage("Ȱ���̿���", "./image/player/Ȱ���̿���.bmp", 950, 72, 10, 1);
	_loading->loadFrameImage("Ȱ���̿�����", "./image/player/Ȱ���̿�����.bmp", 850, 73, 10, 1);
	_loading->loadFrameImage("Ȱ������", "./image/player/Ȱ������.bmp", 657, 100, 9, 1);
	_loading->loadFrameImage("Ȱ���̾Ʒ�", "./image/player/Ȱ���̾Ʒ�.bmp", 603, 87, 9, 1);

	_loading->loadFrameImage("weaponUi", "./image/player/weaponUi.bmp", 800, 231, 4, 1);
	_loading->loadFrameImage("door", "./image/Dungeon/door.bmp", 780, 96, 5, 1);
	_loading->loadFrameImage("door�Ʒ�", "./image/Dungeon/door�Ʒ�.bmp", 780, 96, 5, 1);
	_loading->loadFrameImage("door����", "./image/Dungeon/door����.bmp", 480, 156, 5, 1);
	_loading->loadFrameImage("door������", "./image/Dungeon/door������.bmp", 480, 156, 5, 1);
	_loading->loadFrameImage("�����Ա�", "./image/Dungeon/�����Ա�.bmp", 936, 230, 6, 1);
	//_loading->loadFrameImage("��", "./image/enemy/��.bmp", 1150, 110, 10, 1);
	//IMAGEMANAGER->addFrameImage("��", "./image/enemy/��.bmp", 1150, 110, 10, 1);

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
	font = CreateFont(20, 0, 0, 0, 600, false, false, false, HANGEUL_CHARSET, 0, 0, 0, 0, TEXT("DX������ü��B"));
	oldFont = (HFONT)SelectObject(getMemDC(), font);

	char str[256];
	strncpy_s(str, "�ε���. . .", textIndex);

	RECT textrc = RectMake(WINSIZEX / 2, WINSIZEY - 70, 400, 300);

	DrawText(getMemDC(), str, strlen(str), &textrc, DT_WORDBREAK);

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);

}
