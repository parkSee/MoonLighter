#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::psyImageLoading()
{
	//¸Ê
	_loading->loadImage("map", "./Image/map.bmp", 3000, 2460);
	_loading->loadImage("radZone", "./Image/town_object/town_zOder.bmp", 3000, 2460);
	
	
	
	//¿ÀºêÁ§Æ®
	_loading->loadImage("build_Retaile", "./Image/town_object/build_Retaile.bmp", 644, 679, true, RGB(255, 0, 255));
	_loading->loadImage("build_Top1", "./Image/town_object/build_Top1.bmp", 459, 383, true, RGB(255, 0, 255));
	_loading->loadImage("build_Shop", "./Image/town_object/build_Shop.bmp", 648, 508, true, RGB(255, 0, 255));
	_loading->loadImage("build_Enchant", "./Image/town_object/build_Enchant.bmp", 597, 766, true, RGB(255, 0, 255));


}
