#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## �ʱ�ȭ ## init(void)
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
//	## ���� ## release(void)
//=============================================================
void mainGame::release(void)
{
	gameNode::release();
	
}

//=============================================================
//	## ������Ʈ ## update(void)
//=============================================================
void mainGame::update(void)
{
	gameNode::update();

	_player->update();


	//ī�޶��� ������ ����Դϴ�. �Ȱǵ���� �ǿ�
	CAMERAMANAGER->update();

}

//=============================================================
//	## ���� ## render(void)
//=============================================================
void mainGame::render(void)
{
	//��� �� ��Ʈ��(�̰͵� ������ �׳� �Ѱ�!!)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
//=============================================================
	RECT rc = CAMERAMANAGER->getRenderRc();

	//ī�޶� �����ִ� �κб����� �κ� ���� �մϴ�. 
	//�׷����� �������� ���������ϴ�.
	IMAGEMANAGER->render("map", getMemDC(), 0, 0,rc.left,rc.top,WINSIZEX,WINSIZEY);
	//IMAGEMANAGER->render("map", getMemDC(), 0 - rc.left, 0 - rc.top);

	//_background->render(getMemDC(), 0, 0, renderRC.left, renderRC.top, WINSIZEX, WINSIZEY);

	//ī�޶��� ��Ʈ �����ֱ� ���ؼ� �־�����̴ϴ�. 
	//�Ž����� �ּ�ó�� ����=====================================
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);

	SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));

	Rectangle(getMemDC(), CAMERAMANAGER->getRenderRc());

	SelectObject(getMemDC(), oldPen);
	DeleteObject(pen);
	//=========================================================

	//ī�޶� ���� �κ��Դϴ� ��� �۵� �ߵ˴ϴ�
	//CAMERAMANAGER->render(getMemDC());

	_player->render();

//=============================================================
	//������� ������ HDC�� �׸��� (�̰͵� ������ �׳� �Ѱ�!!)
	this->getBackBuffer()->render(getHDC());
}
