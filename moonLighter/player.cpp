#include "stdafx.h"
#include "player.h"

HRESULT player::init(void)
{

	pos.x = WINSIZEX / 2;
	pos.y = WINSIZEY / 2;

	_time = 0.0f;

	rc = RectMakeCenter(pos.x,pos.y, 70, 70);

	CAMERAMANAGER->connectTarget(pos.x, pos.y);
	
	return S_OK;
}

void player::release(void)
{

}

void player::update(void)
{
	CAMERAMANAGER->connectTarget(pos.x, pos.y);


	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		pos.x -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		pos.x += 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		pos.y -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		pos.y += 5;
	}
	if (KEYMANAGER->isStayKeyDown('T'))
	{
		CAMERAMANAGER->shakeCamera(5.0f, 11.0f);
	}


	rc = RectMakeCenter(pos.x, pos.y, 70, 70);
}

void player::render(void)
{
	RECT cam = CAMERAMANAGER->getRenderRc();

	RectangleMake(getMemDC(), pos.x - cam.left, pos.y - cam.top, 70, 70);

	

}
