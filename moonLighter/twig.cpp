#include "stdafx.h"
#include "twig.h"

//csyADD [twig 아이템의 좌표, 이미지, 충돌박스 초기화 및 랜더 추가]

HRESULT twig::init()
{
	_pos = tagFloat(WINSIZEX / 4, WINSIZEY / 2);
	_img = IMAGEMANAGER->findImage("twig");
	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

	return S_OK;
}

void twig::release()
{
}

void twig::update()
{
}

void twig::render()
{
	RECT camRC;
	camRC = CAMERAMANAGER->getRenderRc();
	_img->render(getMemDC(), _pos.x - camRC.left, _pos.y - camRC.top);

	//IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
