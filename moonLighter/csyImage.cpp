#include "stdafx.h"
#include "loadingScene.h"



void loadingScene::csyImageLoading()
{
	// 각 아이템 별 이미지 (종류(순서대로) 포션, 나뭇가지,액체 아이템, 철근, 붉은 수정, 골렘의 핵)
	_loading->loadImage("potion", "./Image/item_object/item_potion.bmp", 36, 36, true, MAGENTA);
	_loading->loadImage("twig", "./Image/item_object/item_twig.bmp", 36, 36, true, MAGENTA);
	_loading->loadImage("liquidItem", "./Image/item_object/item_liquidItem.bmp", 36, 36, true, MAGENTA);
	_loading->loadImage("rebar", "./Image/item_object/item_rebar.bmp", 36, 36, true, MAGENTA);
	_loading->loadImage("redCristal", "./Image/item_object/item_redCristal.bmp", 36, 36, true, MAGENTA);
	_loading->loadImage("golemCore", "./Image/item_object/item_golemCore.bmp", 36, 36, true, MAGENTA);

	_loading->loadImage("inventory", "./Image/inventory_ui/inventory.bmp", 1000, 512, true, MAGENTA);
	_loading->loadImage("invenSlot", "./Image/inventory_ui/invenSlot.bmp", 68, 68, true, MAGENTA);

	_loading->loadFrameImage("ui_DP", "./Image/shop_object/ui_onDP.bmp", 310, 50, 3, 1,true,MAGENTA);
	_loading->loadFrameImage("cash_register", "./Image/shop_object/cash_register.bmp", 704, 64, 11, 1, true, MAGENTA);
	_loading->loadFrameImage("visitor_face", "./Image/ai/visitor_face.bmp", 256, 32, 8, 1, true, MAGENTA);

	_loading->loadImage("shopDownLayer", "./Image/shop_object/shopDownLayer.bmp", 184, 88, true, MAGENTA);
}

void loadingScene::csySoundLoading()
{

}
