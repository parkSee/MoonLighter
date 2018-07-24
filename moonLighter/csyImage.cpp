#include "stdafx.h"
#include "loadingScene.h"



void loadingScene::csyImageLoading()
{
	//_loading->loadImage("build_Retaile", "./Image/town_object/build_Retaile.bmp", 644, 679, true, RGB(255, 0, 255));
	//_loading->loadImage("build_Top1", "./Image/town_object/build_Top1.bmp", 459, 383, true, RGB(255, 0, 255));

	_loading->loadImage("potion", "./Image/item_object/item_potion.bmp", 8, 26, true, MAGENTA);
	_loading->loadImage("twig", "./Image/item_object/item_twig.bmp", 26, 30, true, MAGENTA);
	_loading->loadImage("liquidItem", "./Image/item_object/item_liquidItem.bmp", 30, 20, true, MAGENTA);
	_loading->loadImage("rebar", "./Image/item_object/item_rebar.bmp", 20, 34, true, MAGENTA);
	_loading->loadImage("redCristal", "./Image/item_object/item_redCristal.bmp", 28, 36, true, MAGENTA);
	_loading->loadImage("golemCore", "./Image/item_object/item_golemCore.bmp", 24, 24, true, MAGENTA);

}
