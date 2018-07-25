#include "stdafx.h"
#include "rebar.h"

//csyADD [rebar 아이템의 좌표, 이미지, 충돌박스 초기화 및 랜더 추가]

HRESULT rebar::init()
{
	_pos = tagFloat(WINSIZEX / 2, WINSIZEY / 3);
	_img = IMAGEMANAGER->findImage("rebar");
	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

	return S_OK;
}

void rebar::release()
{
}

void rebar::update()
{
}

void rebar::render()
{
	RECT camRC;
	camRC = CAMERAMANAGER->getRenderRc();
	_img->render(getMemDC(), _pos.x - camRC.left, _pos.y - camRC.top);

	//IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
