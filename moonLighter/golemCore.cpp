#include "stdafx.h"
#include "golemCore.h"

//csyADD [golemCore cpp - �׽�Ʈ �� ������ ����]

HRESULT golemCore::init()
{
	_pos = tagFloat(1620, 1730);
	_img = IMAGEMANAGER->findImage("golemCore");
	_collisionBox = RectMakeCenter(_pos.x, _pos.y, _img->getWidth(), _img->getHeight());

	// OBJECTMANAGER->findObject(objectType::ENEMY,"golem") //csyADD �̰Ŵ� ��� ����ؾ����� �׽�Ʈ �Ѱ�

	return S_OK;
}

void golemCore::release()
{
}

void golemCore::update()
{
}

void golemCore::render()
{
	RECT camRC;
	camRC = CAMERAMANAGER->getRenderRc();
	_img->render(getMemDC(), _pos.x - camRC.left, _pos.y - camRC.top);

	//IMAGEMANAGER->findImage("potion")->render(getMemDC(), _pos.x, _pos.y);
}
