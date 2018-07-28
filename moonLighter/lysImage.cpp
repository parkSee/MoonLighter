#include "stdafx.h"
#include "loadingScene.h"



void loadingScene::lysImageLoading()
{
	_loading->loadFrameImage("will", "Image/player/will_shop.bmp", 1800, 2160, 10, 12, true, RGB(255, 0, 255));
	_loading->loadFrameImage("will_shortAttack", "Image/player/will_shortAttack.bmp", 1344, 816, 8, 4, true, RGB(255, 0, 255));
	_loading->loadImage("will_hpBar", "Image/player/hpBar.bmp", 150, 50, 130, 228, true, RGB(255, 0, 255));  //lysADD(체력바 이미지 로딩)
}

