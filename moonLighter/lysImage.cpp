#include "stdafx.h"
#include "loadingScene.h"



void loadingScene::lysImageLoading()
{
	_loading->loadFrameImage("will", "Image/will_shop2.bmp", 1800, 2160, 10, 12, true, RGB(255, 0, 255));

	//lysADD(공격이미지 추가)
	_loading->loadFrameImage("will_shortAttack", "Image/will_shortAttack2.bmp", 1344, 816, 8, 4, true, RGB(255, 0, 255));
}

