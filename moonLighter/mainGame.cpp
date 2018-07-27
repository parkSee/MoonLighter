#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## �ʱ�ȭ ## init(void)
//=============================================================

HRESULT mainGame::init(void)
{
	gameNode::init(TRUE);
	
	//��Ʈ�� ��
	SCENEMANAGER->addScene("startScene", new startScene);
	SCENEMANAGER->addScene("loadingScene", new loadingScene);
	SCENEMANAGER->addScene("townScene", new townScene);
	SCENEMANAGER->addScene("shopScene", new shopScene);
	SCENEMANAGER->addScene("dungeonScene", new dungeonScene);
	SCENEMANAGER->addScene("dungeonLobby", new dungeonLobby);

	/*����� ����*/
	SCENEMANAGER->loadScene("loadingScene");


	
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

	SCENEMANAGER->update();
	SOUNDMANAGER->update();
	EFFECTMANAGER->update();

}

//=============================================================
//	## ���� ## render(void)
//=============================================================
void mainGame::render(void)
{
	//��� �� ��Ʈ��(�̰͵� ������ �׳� �Ѱ�!!)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
//=============================================================
	


	SCENEMANAGER->render();
	EFFECTMANAGER->render();
//=============================================================
	//������� ������ HDC�� �׸��� (�̰͵� ������ �׳� �Ѱ�!!)
	this->getBackBuffer()->render(getHDC());
}
