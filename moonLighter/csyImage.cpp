#include "stdafx.h"
#include "loadingScene.h"

// csyADD [�κ��丮 �̹��� �߰�]

void loadingScene::csyImageLoading()
{
	// �� ������ �� �̹��� (����(�������) ����, ��������,��ü ������, ö��, ���� ����, ���� ��)
	_loading->loadImage("potion", "./Image/item_object/item_potion.bmp", 8, 26, true, MAGENTA);
	_loading->loadImage("twig", "./Image/item_object/item_twig.bmp", 26, 30, true, MAGENTA);
	_loading->loadImage("liquidItem", "./Image/item_object/item_liquidItem.bmp", 30, 20, true, MAGENTA);
	_loading->loadImage("rebar", "./Image/item_object/item_rebar.bmp", 20, 34, true, MAGENTA);
	_loading->loadImage("redCristal", "./Image/item_object/item_redCristal.bmp", 28, 36, true, MAGENTA);
	_loading->loadImage("golemCore", "./Image/item_object/item_golemCore.bmp", 24, 24, true, MAGENTA);
<<<<<<< HEAD
	_loading->loadImage("inventory", "./Image/item_object/inven.bmp", 828, 423, true, MAGENTA);
=======
	_loading->loadImage("inventory", "./Image/inventory_ui/inventory.bmp", 1000, 512, true, MAGENTA);
	_loading->loadImage("invenSlot", "./Image/inventory_ui/invenSlot.bmp", 68, 68, true, MAGENTA);

}

void loadingScene::csySoundLoading()
{
>>>>>>> 77b635cc87d82f6c2a16b0f3a7034f0863023f67
}
