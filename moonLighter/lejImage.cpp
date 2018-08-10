#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::lejImageLoading()
{
	
	_loading->loadFrameImage("shopDoor", "./image/shop_object/shopDoor.bmp", 900, 139, 6, 1);

	_loading->loadFrameImage("È°ÀïÀÌ¿ÞÂÊ", "./image/player/È°ÀïÀÌ¿ÞÂÊ.bmp", 950, 72, 10, 1);
	_loading->loadFrameImage("È°ÀïÀÌ¿À¸¥ÂÊ", "./image/player/È°ÀïÀÌ¿À¸¥ÂÊ.bmp", 850, 73, 10, 1);
	_loading->loadFrameImage("È°ÀïÀÌÀ§", "./image/player/È°ÀïÀÌÀ§.bmp", 657, 100, 9, 1);
	_loading->loadFrameImage("È°ÀïÀÌ¾Æ·¡", "./image/player/È°ÀïÀÌ¾Æ·¡.bmp", 603, 87, 9, 1);

	_loading->loadFrameImage("weaponUi", "./image/player/weaponUi.bmp", 800, 231, 4, 1);


}

void loadingScene::lejSoundLoading()
{
	
}



