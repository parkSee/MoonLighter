#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::psyImageLoading()
{
	//타운맵
	_loading->loadImage("map", "./Image/map2.bmp", 3000, 2460);
	_loading->loadImage("redZone", "./Image/town_object/town_pixel2.bmp", 3000, 2460);

	//샵
	_loading->loadImage("shopMap", "./Image/shop_object/shop.bmp", 1122, 1440, true, MAGENTA);
	_loading->loadImage("shopLayer", "./Image/shop_object/shopLayer2.bmp", 167, 147, true, MAGENTA);
	_loading->loadImage("shopPixel", "./Image/shop_object/shopPixel.bmp", 1122, 1440);

	_loading->loadImage("display", "./Image/shop_object/display.bmp", 100, 152, true, MAGENTA);
	_loading->loadImage("counter", "./Image/shop_object/counter.bmp", 300, 104, true, MAGENTA);

	_loading->loadFrameImage("buttonUi", "Image/shop_object/buttonUi.bmp", 1720, 100, 8, 1, true, MAGENTA);
	_loading->loadFrameImage("button", "Image/shop_object/button.bmp", 3400, 83, 40, 1, true, MAGENTA);
	_loading->loadImage("jButton", "Image/shop_object/jButton.bmp", 40, 40, true, MAGENTA);
	_loading->loadImage("shop_door_layer", "Image/shop_object/shop_door_layer.bmp", 183, 118,true,MAGENTA);

	//던전 로비
	_loading->loadImage("dunIntro", "./Image/dungeon_object/dungeonLobby_base.bmp", 2460, 2100);
	_loading->loadImage("dunIntroRed", "./Image/dungeon_object/dungeonLobby_redzone.bmp", 2460, 2100);
	_loading->loadFrameImage("dunIntroDoorOpen", "./Image/dungeon_object/dungeonLobby_doorOpen.bmp", 1344, 69, 16, 1);
	_loading->loadFrameImage("dunIntroShowEnterText", "./Image/dungeon_object/dungeonLobby_showEnterText.bmp", 285, 47, 3, 1);
	_loading->loadFrameImage("dunIntroGoInDungeon", "./Image/dungeon_object/dungeonLobby_goInDungeon.bmp", 1764, 97, 21, 1);
	_loading->loadFrameImage("dunIntroGoOutDungeon", "./Image/dungeon_object/dungeonLobby_goOutDungeon.bmp", 4704, 139, 56, 1);

	//던전
	_loading->loadImage("dungeonMap", "./Image/dungeon_object/dungeonMap.bmp",3840,2160,true,MAGENTA);
	_loading->loadImage("dungeonRedZone", "./Image/dungeon_object/dungeonMap_redZone.bmp", 3840, 2160, true, MAGENTA);
	_loading->loadImage("bossRoom", "./Image/dungeon_object/bossRoom.bmp", 3152, 2131);
	_loading->loadImage("bossRoomRedZoon", "./Image/dungeon_object/bossRoomRedZoon.bmp", 3152, 2131);

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

	_loading->loadImage("bottomLeftRock", "Image/dungeon_object/dungeonLobby_bottomLeftRock.bmp", 45, 62, true, MAGENTA);
	_loading->loadImage("bottomRight2Rock", "Image/dungeon_object/dungeonLobby_bottomRight2Rock.bmp", 105, 194, true, MAGENTA);
	_loading->loadImage("middleLeftRock", "Image/dungeon_object/dungeonLobby_middleLeftRock.bmp", 47, 68, true, MAGENTA);
	_loading->loadImage("middleRighttRock", "Image/dungeon_object/dungeonLobby_middleRighttRock.bmp", 61, 91, true, MAGENTA);
	_loading->loadImage("topLeft3Rock", "Image/dungeon_object/dungeonLobby_topLeft3Rock.bmp", 116, 134, true, MAGENTA);
	_loading->loadImage("topRightRock", "Image/dungeon_object/dungeonLobby_topRightRock.bmp", 69, 112, true, MAGENTA);
	_loading->loadImage("entryStructure", "Image/dungeon_object/dungeonLobby_entryStructure.bmp", 531, 234, true, MAGENTA);
	_loading->loadImage("top3LongBoard", "Image/dungeon_object/dungeonLobby_top3LongBoard.bmp", 462, 117, true, MAGENTA);
	_loading->loadImage("bottomLeftTent", "Image/dungeon_object/dungeonLobby_bottomLeftTent.bmp", 248, 235, true, MAGENTA);

	_loading->loadFrameImage("tree", "Image/town_object/tree.bmp", 828, 222, 4, 1, true, MAGENTA);

	//NPC
	_loading->loadFrameImage("npc_witch", "./Image/town_object/npc.bmp", 525, 105, 5, 1, true, MAGENTA);
	_loading->loadFrameImage("talking", "./Image/말하기.bmp", 363, 50, 3, 1, true, MAGENTA);

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
	_loading->loadFrameImage("main_frame", "Image/main_frame.bmp", 14080, 720, 16, 1,true,MAGENTA);
	//logo
	_loading->loadImage("logo", "Image/logo.bmp", 400, 325, true, MAGENTA);

	//font
	_loading->loadImage("aniKey", "Image/아무키나.bmp", 509, 45, true, MAGENTA);
	_loading->loadImage("start", "Image/새로운.bmp", 200, 45, true, MAGENTA);
	_loading->loadImage("option", "Image/옵션.bmp", 200, 45, true, MAGENTA);
	_loading->loadImage("exit", "Image/나가기.bmp", 200, 45, true, MAGENTA);
	_loading->loadImage("select", "Image/selectMain.bmp", 280, 50, true, MAGENTA);

	//option
	_loading->loadImage("optionBook", "Image/option/optionImg.bmp", 800, 513, true, MAGENTA);
	_loading->loadImage("soundSelect", "Image/option/음악선택화살.bmp", 361, 33, true, MAGENTA);
	_loading->loadImage("volumeSelect", "Image/option/볼륨선택화살.bmp", 362, 46, true, MAGENTA);
	_loading->loadImage("on", "Image/option/on.bmp", 51, 31);
	_loading->loadImage("off", "Image/option/off.bmp", 57, 41);
	_loading->loadImage("soundChoice", "Image/option/음악선택.bmp", 156, 41,true,MAGENTA);
	_loading->loadImage("volumeChoice", "Image/option/볼륨선택.bmp", 212, 39, true, MAGENTA);
	_loading->loadImage("inactiveOn", "Image/option/inactiveOn.bmp", 51, 31);
	_loading->loadImage("inactiveOff", "Image/option/inactiveOff.bmp", 57, 41);
	_loading->loadImage("block", "Image/option/volblock.bmp", 23, 23);
	
	
}

void loadingScene::psySoundLoading()
{
	_loading->loadSound("townBGM", "./gameSound/townBGM.mp3", true, true);
	_loading->loadSound("shopBGM", "./gameSound/shopBGM.mp3", true, true);
	_loading->loadSound("introBGM", "./gameSound/introBGM.mp3", true, true);
	_loading->loadSound("dungeonBGM", "./gameSound/dungeonBGM.mp3", true, true);
	_loading->loadSound("bossBGM", "./gameSound/bossRoomBGM.mp3", true, true);
}

