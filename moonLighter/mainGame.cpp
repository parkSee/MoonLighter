#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## 초기화 ## init(void)
//=============================================================
HRESULT mainGame::init(void)
{
	gameNode::init(TRUE);
	
	IMAGEMANAGER->addImage("map", "./Image/map.bmp", 3000, 2460);

	_player = new player;
	_player->init();

	CAMERAMANAGER->setMapSize(3000, 2460);


	return S_OK;
}

//=============================================================
//	## 해제 ## release(void)
//=============================================================
void mainGame::release(void)
{
	gameNode::release();
	
}

//=============================================================
//	## 업데이트 ## update(void)
//=============================================================
void mainGame::update(void)
{
	gameNode::update();

	_player->update();



	CAMERAMANAGER->update();

}

//=============================================================
//	## 렌더 ## render(void)
//=============================================================
void mainGame::render(void)
{
	//흰색 빈 비트맵(이것도 렌더에 그냥 둘것!!)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
//=============================================================
	RECT rc = CAMERAMANAGER->getRenderRc();

	//IMAGEMANAGER->render("map", getMemDC(), 0, 0,rc.left,rc.top,WINSIZEX,WINSIZEY);
	IMAGEMANAGER->render("map", getMemDC(), 0 - rc.left, 0 - rc.top);

	//_background->render(getMemDC(), 0, 0, renderRC.left, renderRC.top, WINSIZEX, WINSIZEY);

	HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);

	SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));

	Rectangle(getMemDC(), CAMERAMANAGER->getRenderRc());

	SelectObject(getMemDC(), oldPen);
	DeleteObject(pen);

	CAMERAMANAGER->render(getMemDC());

	_player->render();

//=============================================================
	//백버퍼의 내용을 HDC에 그린다 (이것도 렌더에 그냥 둘것!!)
	this->getBackBuffer()->render(getHDC());
}
