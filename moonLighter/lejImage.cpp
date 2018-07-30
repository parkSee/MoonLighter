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

	_loading->loadFrameImage("보스생성", "./image/enemy/보스생성.bmp", 9216, 256, 36, 1);

	

	_loading->loadFrameImage("보스이펙트오른쪽", "./image/enemy/보스이펙트오른쪽.bmp", 61, 68, 1, 1);
	_loading->loadFrameImage("보스이펙트왼쪽", "./image/enemy/보스이펙트왼쪽.bmp", 61, 68, 1, 1);
	




	


	//_loading->loadFrameImage("뿅", "./image/enemy/뿅.bmp", 1150, 110, 10, 1);
	//IMAGEMANAGER->addFrameImage("뿅", "./image/enemy/뿅.bmp", 1150, 110, 10, 1);

}

void loadingScene::lejSoundLoading()
{
}



