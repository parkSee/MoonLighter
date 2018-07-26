#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::psyImageLoading()
{
	//타운맵
	_loading->loadImage("map", "./Image/map.bmp", 3000, 2460);
	_loading->loadImage("redZone", "./Image/town_object/town_pixel.bmp", 3000, 2460);

	//샵
	_loading->loadImage("shopMap", "./Image/shop_object/shop.bmp", 1122, 1440, true, MAGENTA);
	_loading->loadImage("shopLayer", "./Image/shop_object/shopLayer.bmp", 1122, 248, true, MAGENTA);
	_loading->loadImage("shopPixel", "./Image/shop_object/shopPixel.bmp", 1122, 1440);

	//던전 로비
	_loading->loadImage("dunIntro", "./Image/dungeon_object/dungeonLobby_base.bmp", 1680, 1434);
	_loading->loadImage("dunIntroRed", "./Image/dungeon_object/dungeonLobby_redzone.bmp", 1680, 1434);

	//던전
	_loading->loadImage("stage1", "./Image/dungeon_object/stage1.bmp",1280,720);
	_loading->loadImage("stage2", "./Image/dungeon_object/stage2.bmp", 1280, 720);

	//오브젝트
	_loading->loadImage("build_Retaile", "./Image/town_object/build_Retaile.bmp", 644, 679, true, RGB(255, 0, 255));
	_loading->loadImage("build_Top1", "./Image/town_object/build_Top1.bmp", 459, 383, true, RGB(255, 0, 255));
	_loading->loadImage("build_Shop", "./Image/town_object/build_Shop.bmp", 648, 508, true, RGB(255, 0, 255));
	_loading->loadImage("build_Enchant", "./Image/town_object/build_Enchant.bmp", 597, 766, true, MAGENTA);
	_loading->loadImage("build_Bottom1", "./Image/town_object/build_Bottom1.bmp", 483, 333, true, MAGENTA);
	_loading->loadImage("build_Bottom2", "./Image/town_object/build_Bottom2.bmp", 345, 383, true, MAGENTA);
	_loading->loadImage("build_Bottom3", "./Image/town_object/build_Bottom3.bmp", 534, 508, true, MAGENTA);
	_loading->loadImage("build_Forge", "./Image/town_object/build_Forge.bmp", 640, 483, true, MAGENTA);
	_loading->loadImage("build_Well", "./Image/town_object/build_Well.bmp", 132, 160, true, MAGENTA);
	_loading->loadImage("build_Board", "./Image/town_object/build_Board.bmp", 204, 134, true, MAGENTA);


}

