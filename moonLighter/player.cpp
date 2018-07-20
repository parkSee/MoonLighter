#include "stdafx.h"
#include "player.h"

HRESULT player::init(void)
{

	pos.x = WINSIZEX / 2;
	pos.y = WINSIZEY / 2;

	_time = 0.0f;

	rc = RectMakeCenter(pos.x,pos.y, 70, 70);

	//처음 타겟을 지정해줍니다
	CAMERAMANAGER->connectTarget(pos.x, pos.y);
	
	return S_OK;
}

void player::release(void)
{

}

void player::update(void)
{
	//업데이트에서 계속해서 타겟팅될 아이의 좌표를 넣어줍니다.
	//그래야지 그 좌표를 따라 움직입니다.
	//에너미로 카메라를 바꾸고 싶으면 플레이어쪽에 connectTarget을 주석처리하고 
	//에너미 업데이트에 connectTarget를 넣어주면됩니다.
	//렌더에서 좌표빼는거 잊지마세요!
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

	//카메라의 rc만큼 플레이어 좌표에서 빼줍니다.
	RECT cam = CAMERAMANAGER->getRenderRc();

	RectangleMake(getMemDC(), pos.x - cam.left, pos.y - cam.top, 70, 70);

	

}
