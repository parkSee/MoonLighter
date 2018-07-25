#include "stdafx.h"
#include "liquidItem.h"

//csyADD [liquidItem 아이템의 좌표, 이미지, 충돌박스 초기화 및 랜더 추가]

HRESULT liquidItem::init()
{
	_pos = tagFloat(WINSIZEX / 3, WINSIZEY / 3);
	_img = IMAGEMANAGER->findImage("liquidItem");
	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

	return S_OK;
}

void liquidItem::release()
{
}

void liquidItem::update()
{
}

void liquidItem::render()
{
	RECT camRC;
	camRC = CAMERAMANAGER->getRenderRc();
	_img->render(getMemDC(), _pos.x - camRC.left, _pos.y - camRC.top);

	//IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
