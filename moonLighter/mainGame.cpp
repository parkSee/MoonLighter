#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## �ʱ�ȭ ## init(void)
//=============================================================
HRESULT mainGame::init(void)
{
	gameNode::init(TRUE);
	
	IMAGEMANAGER->addImage("map", "./Image/map.bmp", 3000, 2460);
	IMAGEMANAGER->addImage("radZone", "./Image/pixel.bmp", 3000, 2460);


	//���߿� ���Ŵ��� �߰��ؼ� �Ű� �����̴ϴ�. 
	_player = new player;
	_player->init("player",tagFloat(WINSIZEX/2,WINSIZEY/2));
	OBJECTMANAGER->addObject(objectType::PLAYER, _player);


	//���߿� ���Ŵ��� �߰��ؼ� �Ű� �����̴ϴ�. 
	//���ʹ� �Ŵ��� �Ҵ�
	_em = new enemyController;
	_em->init();


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

	OBJECTMANAGER->update();

	
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


	IMAGEMANAGER->render("map", getMemDC(), 0, 0,rc.left,rc.top,WINSIZEX,WINSIZEY);
	
	if (KEYMANAGER->isStayKeyDown('V'))
	{
		IMAGEMANAGER->render("radZone", getMemDC(), 0, 0, rc.left, rc.top, WINSIZEX, WINSIZEY);
	}
	//_background->render(getMemDC(), 0, 0, renderRC.left, renderRC.top, WINSIZEX, WINSIZEY);

	/*HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);

	SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));

	Rectangle(getMemDC(), CAMERAMANAGER->getRenderRc());


	SelectObject(getMemDC(), oldPen);
	DeleteObject(pen);
*/
	CAMERAMANAGER->render(getMemDC());
	
	OBJECTMANAGER->render(getMemDC());
	

//=============================================================
	//������� ������ HDC�� �׸��� (�̰͵� ������ �׳� �Ѱ�!!)
	this->getBackBuffer()->render(getHDC());
}
