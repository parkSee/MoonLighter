#include "stdafx.h"
#include "loadingScene.h"

// csyADD [�κ��丮 �̹��� �߰�]

void loadingScene::csyImageLoading()
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

}

void loadingScene::csySoundLoading()
{

}
