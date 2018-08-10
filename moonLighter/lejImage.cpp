#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::lejImageLoading()
{
	_loading->loadFrameImage("잡초", "./image/enemy/잡초.bmp", 4200, 90, 60, 1);
	_loading->loadFrameImage("잡초빨강", "./image/enemy/잡초빨강.bmp", 4200, 90, 60, 1);
	_loading->loadFrameImage("잡초하양", "./image/enemy/잡초하양.bmp", 4200, 90, 60, 1);

	_loading->loadFrameImage("큰슬라임", "./image/enemy/큰슬라임.bmp", 6000, 110, 60, 1);
	_loading->loadFrameImage("큰슬라임빨강", "./image/enemy/큰슬라임빨강.bmp", 6000, 110, 60, 1);
	_loading->loadFrameImage("큰슬라임하양", "./image/enemy/큰슬라임하양.bmp", 6000, 110, 60, 1);

	_loading->loadFrameImage("작은슬라임", "./image/enemy/작은슬라임.bmp", 3000, 55, 60, 1);
	_loading->loadFrameImage("작은슬라임빨강", "./image/enemy/작은슬라임빨강.bmp", 3000, 55, 60, 1);
	_loading->loadFrameImage("작은슬라임하양", "./image/enemy/작은슬라임하양.bmp", 3000, 55, 60, 1);

	_loading->loadFrameImage("골렘정면", "./image/enemy/골렘정면.bmp", 4800, 170, 60, 1);
	_loading->loadFrameImage("정면맞는빨강", "./image/enemy/정면맞는빨강.bmp", 4800, 170, 60, 1);
	_loading->loadFrameImage("정면맞는하양", "./image/enemy/정면맞는하양.bmp", 4800, 170, 60, 1);

	_loading->loadFrameImage("골렘왼쪽", "./image/enemy/골렘왼쪽.bmp", 7800, 125, 60, 1);
	_loading->loadFrameImage("왼쪽맞는빨강", "./image/enemy/왼쪽맞는빨강.bmp", 7800, 125, 60, 1);
	_loading->loadFrameImage("왼쪽맞는하양", "./image/enemy/왼쪽맞는하양.bmp", 7800, 125, 60, 1);

	_loading->loadFrameImage("골렘오른쪽", "./image/enemy/골렘오른쪽.bmp", 7800, 140, 60, 1);
	_loading->loadFrameImage("오른쪽맞는빨강", "./image/enemy/오른쪽맞는빨강.bmp", 7800, 140, 60, 1);
	_loading->loadFrameImage("오른쪽맞는하양", "./image/enemy/오른쪽맞는하양.bmp", 7800, 140, 60, 1);

	_loading->loadFrameImage("골렘뒤쪽", "./image/enemy/골렘뒤쪽.bmp", 4800, 140, 60, 1);
	_loading->loadFrameImage("뒤쪽맞는빨강", "./image/enemy/뒤쪽맞는빨강.bmp", 4800, 140, 60, 1);
	_loading->loadFrameImage("뒤쪽맞는하양", "./image/enemy/뒤쪽맞는하양.bmp", 4800, 140, 60, 1);

	_loading->loadFrameImage("뿅", "./image/enemy/뿅.bmp", 1150, 110, 10, 1);



	_loading->loadFrameImage("보스공격이펙트다운오른쪽", "./image/enemy/보스공격이펙트다운오른쪽.bmp", 1408, 128, 11, 1);
	_loading->loadFrameImage("보스공격이펙트다운왼쪽", "./image/enemy/보스공격이펙트다운왼쪽.bmp", 1408, 128, 11, 1);
	_loading->loadFrameImage("보스공격이펙트업왼쪽", "./image/enemy/보스공격이펙트업왼쪽.bmp", 1408, 128, 10, 1);
	_loading->loadFrameImage("보스공격이펙트업오른쪽", "./image/enemy/보스공격이펙트업오른쪽.bmp", 1408, 128, 10, 1);

	_loading->loadFrameImage("보스뒤오른쪽", "./image/enemy/보스뒤오른쪽.bmp", 7680, 256, 30, 1);
	_loading->loadFrameImage("보스뒤오른쪽빨강", "./image/enemy/보스뒤오른쪽빨강.bmp", 7680, 256, 30, 1);
	_loading->loadFrameImage("보스뒤오른쪽하양", "./image/enemy/보스뒤오른쪽하양.bmp", 7680, 256, 30, 1);
	_loading->loadFrameImage("보스뒤왼쪽", "./image/enemy/보스뒤왼쪽.bmp", 7680, 256, 30, 1);
	_loading->loadFrameImage("보스뒤왼쪽빨강", "./image/enemy/보스뒤왼쪽빨강.bmp", 7680, 256, 30, 1);
	_loading->loadFrameImage("보스뒤왼쪽하양", "./image/enemy/보스뒤왼쪽하양.bmp", 7680, 256, 30, 1);

	_loading->loadFrameImage("보스정면왼쪽", "./image/enemy/보스정면왼쪽.bmp", 7680, 256, 30, 1);
	_loading->loadFrameImage("보스정면왼쪽빨강", "./image/enemy/보스정면왼쪽빨강.bmp", 7680, 256, 30, 1);
	_loading->loadFrameImage("보스정면왼쪽하양", "./image/enemy/보스정면왼쪽하양.bmp", 7680, 256, 30, 1);
	_loading->loadFrameImage("보스정면오른쪽", "./image/enemy/보스정면오른쪽.bmp", 7680, 256, 30, 1);
	_loading->loadFrameImage("보스정면오른쪽빨강", "./image/enemy/보스정면오른쪽빨강.bmp", 7680, 256, 30, 1);
	_loading->loadFrameImage("보스정면오른쪽하양", "./image/enemy/보스정면오른쪽하양.bmp", 7680, 256, 30, 1);

	_loading->loadFrameImage("보스생성", "./image/enemy/보스생성.bmp", 9216, 256, 37, 1);

	

	_loading->loadFrameImage("보스이펙트오른쪽", "./image/enemy/보스이펙트오른쪽.bmp", 61, 68, 1, 1);
	_loading->loadFrameImage("보스이펙트왼쪽", "./image/enemy/보스이펙트왼쪽.bmp", 61, 68, 1, 1);
	_loading->loadFrameImage("검은화면", "./image/enemy/검은화면.bmp", WINSIZEX, WINSIZEY, 1, 1);
	//_loading->loadImage("보스체력", "보스체력.bmp", 1000, 14);
	//_loading->loadImage("보스체력껍데기", "보스체력껍데기.bmp", 1000, 14,true);


	_loading->loadFrameImage("대미지폰트", "./image/enemy/대미지폰트.bmp", 300, 40, 10, 1);
	_loading->loadFrameImage("shopDoor", "./image/shop_object/shopDoor.bmp", 900, 139, 6, 1);

	_loading->loadFrameImage("활쟁이왼쪽", "./image/player/활쟁이왼쪽.bmp", 950, 72, 10, 1);
	_loading->loadFrameImage("활쟁이오른쪽", "./image/player/활쟁이오른쪽.bmp", 850, 73, 10, 1);
	_loading->loadFrameImage("활쟁이위", "./image/player/활쟁이위.bmp", 657, 100, 9, 1);
	_loading->loadFrameImage("활쟁이아래", "./image/player/활쟁이아래.bmp", 603, 87, 9, 1);

	_loading->loadFrameImage("weaponUi", "./image/player/weaponUi.bmp", 800, 231, 4, 1);
	_loading->loadFrameImage("door", "./image/Dungeon/door.bmp", 780, 96, 5, 1);
	_loading->loadFrameImage("door아래", "./image/Dungeon/door아래.bmp", 780, 96, 5, 1);
	_loading->loadFrameImage("door왼쪽", "./image/Dungeon/door왼쪽.bmp", 480, 156, 5, 1);
	_loading->loadFrameImage("door오른쪽", "./image/Dungeon/door오른쪽.bmp", 480, 156, 5, 1);
	_loading->loadFrameImage("보스입구", "./image/Dungeon/보스입구.bmp", 936, 230, 6, 1);
	//_loading->loadFrameImage("뿅", "./image/enemy/뿅.bmp", 1150, 110, 10, 1);
	//IMAGEMANAGER->addFrameImage("뿅", "./image/enemy/뿅.bmp", 1150, 110, 10, 1);

}

void loadingScene::lejSoundLoading()
{
	_loading->loadSound("enemy_death", "./gameSound/enemy_death.wav", false, false);
	_loading->loadSound("golem_hit", "./gameSound/golem_hit.wav", false, false);
	_loading->loadSound("slime_hit", "./gameSound/slime_hit.wav", false, false);
	_loading->loadSound("weed_hit", "./gameSound/weed_hit.wav", false, false);
}



